#include <iostream>

using namespace std;

int main()
{
    float precision=0.4, recall=0.3;
    float F1 = 2*(precision*recall) /(precision+recall);
    cout<<"Score of F1: "<<F1<<endl;
}