
#include <iostream>
#include <math.h>

using namespace std;

double func1(double *pos, int dim);
double getlrand(double upper, double lower);

class Partical
{
public:
    double *velocity;
    double *position;
    double *location;

    void init(int dimsize)
    {
        velocity = new double[dimsize];
        position = new double[dimsize];
        location = new double[dimsize];
    }
};

class Swarm
{
public:
    Partical *p;
    double *global;
    int populationSize, dimension;
    double upper, lower, lrt, deltaG, deltaP, w;

    double (*evalFunction)(double *position, int dimension);

    Swarm(int number, int dimensionSize)
    {
        populationSize = number;
        dimension = dimensionSize;

        global = new double[dimensionSize];

        p = new Partical[number];

        for (int i = 0; i < number; i++)
        {
            p[i].init(dimension);
        }
    }

    void initialise(double w_, double deltag, double deltap, double lrt_, double upper_, double lower_, double (*evalfunc)(double *pos, int dim))
    {
        upper = upper_;
        lower = lower_;
        lrt = lrt_;
        deltaG = deltag;
        deltaP = deltap;
        w = w_;
        evalFunction = evalfunc;

        for (int j = 0; j < dimension; j++)
        {
            global[j] = getlrand(lower, upper);
        }

        for (int i = 0; i < populationSize; i++)
        {

            for (int j = 0; j < dimension; j++)
            {

                p[i].position[j] = getlrand(lower, upper);
                p[i].velocity[j] = getlrand(lower, upper);
                p[i].location[j] = p[i].position[j];
            }

            if (evalfunc(p[i].location, 3) < evalfunc(global, 3))
            {

                for (int k = 0; k < dimension; k++)
                    global[k] = p[i].location[k];
            }
        }
    }


};

int main()
{
    Swarm mySwarm(50,5);
    mySwarm.initialise(0.32, 0.45, 0.23, 0.67, 2.34, 0.03, func1);
    return 0;
}