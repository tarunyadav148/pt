#include <array>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
constexpr array<char, 26> vocab = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<vector<double>> log_p_language_model;

double lm(const char current, const char next) { return log_p_language_model[current - 'a'][next - 'a']; }

pair<string, double> greedy_decoding(char start, size_t length)
{
    string decoded(length, '0');
    decoded[0] = start;
    double log_p = 0;

    for (int i = 1; i < length; i++)
    {
        double max_p{numeric_limits<double>::lowest()};
        char best_c;
        for (auto const &c : vocab)
        {
            double p = lm(decoded[i - 1], c);
            if (p > max_p)
            {
                max_p = p;
                best_c = c;
            }
        }
        decoded[i] = best_c;
        log_p += max_p;
    }
    return make_pair(decoded, log_p);
}

struct Beam
{
    double log_p;
    string s;
    Beam() : log_p(0.), s("") {}
    Beam(double _lp, string _s) : log_p(_lp), s(_s) {}
};

bool beam_comp(const Beam &b1, const Beam &b2) { return b1.log_p < b2.log_p; }

void expand_beam(size_t beam_idx, vector<Beam> &beams, vector<Beam> &next_beams, size_t beam_size)
{
    vector<Beam> next_possible_beams{};
    next_possible_beams.reserve(vocab.size());
    for (auto const &c : vocab)
        next_possible_beams.push_back(Beam(beams[beam_idx].log_p + lm(beams[beam_idx].s.back(), c), beams[beam_idx].s + c));

    make_heap(next_possible_beams.begin(), next_possible_beams.end(),
              beam_comp);
    for (int k = 0; k < beam_size; ++k)
    {
        pop_heap(next_possible_beams.begin(), next_possible_beams.end(), beam_comp);

        next_beams.push_back(next_possible_beams.back());
        next_possible_beams.pop_back();
    }
}

void expand_all_beams(vector<Beam> &beams, vector<Beam> &next_beams, size_t beam_size)
{
    for (int j = 0; j < beams.size(); j++)
    {
        expand_beam(j, beams, next_beams, beam_size);
    }
    make_heap(next_beams.begin(), next_beams.end(), beam_comp);
}

vector<Beam> expand_all_beams_moremem(vector<Beam> &beams, size_t beam_size)
{
    vector<Beam> next_beams{};
    next_beams.reserve(beams.size() * beam_size * vocab.size());

    for (int j = 0; j < beams.size(); j++)
    {
        for (auto const &c : vocab)
            next_beams.push_back(Beam(beams[j].log_p + lm(beams[j].s.back(), c), beams[j].s + c));
    }
    make_heap(next_beams.begin(), next_beams.end(), beam_comp);
    return next_beams;
}

void select_best_beams(vector<Beam> &beams, vector<Beam> &next_beams, size_t beam_size)
{

    vector<char> last_states(beam_size);
    beams.clear();
    for (int k = 0; k < beam_size; ++k)
    {
        pop_heap(next_beams.begin(), next_beams.end(), beam_comp);

        while (k > 0 &&
               find(last_states.begin(), last_states.end(),
                    next_beams.back().s.back()) != last_states.end())
        {
            next_beams.pop_back();
            pop_heap(next_beams.begin(), next_beams.end(), beam_comp);
        }
        beams.push_back(next_beams.back());
        last_states.push_back(beams[k].s.back());
        next_beams.pop_back();
    }
}

pair<string, double> beam_decoding(char start, size_t length, size_t beam_size)
{

    vector<Beam> beams(1);
    beams[0].s = start;

    for (int i = 1; i < length; i++)
    {
        vector<Beam> next_beams{};
        next_beams.reserve(beams.size() * beam_size);
        expand_all_beams(beams, next_beams, beam_size);

        select_best_beams(beams, next_beams, beam_size);
    }

    int max_idx = 0;
    for (int i = 1; i < beams.size(); i++)
        if (beam_comp(beams[max_idx], beams[i]))
            max_idx = i;

    return make_pair(beams[max_idx].s, beams[max_idx].log_p);
}

pair<string, double> fast_beam_decoding(char start, size_t length, size_t beam_size)
{

    vector<Beam> beams(1);
    beams[0].s = start;

    for (int i = 1; i < length; i++)
    {
        auto next_beams = expand_all_beams_moremem(beams, beam_size);
        select_best_beams(beams, next_beams, beam_size);
    }

    int max_idx = 0;
    for (int i = 1; i < beams.size(); i++)
        if (beam_comp(beams[max_idx], beams[i]))
            max_idx = i;

    return make_pair(beams[max_idx].s, beams[max_idx].log_p);
}

int main(int argc, char const *argv[])
{

    log_p_language_model = vector<vector<double>>(26);
    for (auto &row : log_p_language_model)
        row = vector<double>(26, numeric_limits<double>::lowest());

    log_p_language_model[0][1] = log(0.55);
    log_p_language_model[0][2] = log(0.45);
    log_p_language_model[1][0] = log(0.15);
    for (int i = 1; i < 26; i++)
        log_p_language_model[1][i] = log((1. - log_p_language_model[1][0]) / 25);

    log_p_language_model[2][0] = log(0.4);
    for (int i = 1; i < 26; i++)
        log_p_language_model[2][i] = log((1. - log_p_language_model[2][0]) / 25);

    size_t beam_size = 5;
    size_t length = 30;

    auto start = std::chrono::high_resolution_clock::now();

    auto gd = greedy_decoding('a', length);
    cout << "Best (greedily) decoded string: " << gd.first << "\n\twhich had a probability of " << gd.second << endl;

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by Greedy Decoding: "
         << duration.count() << " microseconds" << endl
         << endl;

    start = std::chrono::high_resolution_clock::now();
    auto bd = beam_decoding('a', length, beam_size);
    cout << "Best (beam_search) decoded string: " << bd.first << "\n\twhich had a probability of " << bd.second << endl;

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by Beam Decoding: "
         << duration.count() << " microseconds" << endl
         << endl;

    start = std::chrono::high_resolution_clock::now();
    auto fbd = fast_beam_decoding('a', length, beam_size);
    cout << "Best (fast_beam_search) decoded string: " << fbd.first << "\n\twhich had a probability of " << fbd.second << endl;

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by Fast Beam Decoding: "
         << duration.count() << " microseconds" << endl
         << endl;

    return 0;
}