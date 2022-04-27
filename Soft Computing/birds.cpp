#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;


double func1(double* pos,int dim);
double getlrand(double upper,double lower);

class partical{
public:
double *velocity;
double *position;
double *localg;

void init(int dimsize){

velocity = new double[dimsize];
position = new double[dimsize];
localg   = new double[dimsize];

         }

};

class swarm{
public:
partical *p;
double *globalg;
int popsize,dim;
double upper,lower,lrt,deltag,deltap,w;
double (*evalfunc)(double *pos,int dim);

swarm(int number,int dimsize){
popsize = number;
dim = dimsize;

globalg = new double[dimsize];

p = new partical[number];

for(int i=0;i<number;i++){
p[i].init(dim);
         }
}

void initialise(double w_,double deltag_,double deltap_,double 
lrt_,double upper_,double lower_,double (*evalfunc_) (double* 
pos,int dim))
{
upper=upper_;
lower=lower_;
lrt=lrt_;
deltag=deltag_;
deltap=deltap_;
w=w_;
evalfunc=evalfunc_;

for(int j=0;j<dim;j++){
globalg[j] = getlrand(lower,upper);
}


for(int i=0;i<popsize;i++){

for(int j=0;j<dim;j++){

p[i].position[j] = getlrand(lower,upper);
p[i].velocity[j] = getlrand(lower,upper);
p[i].localg[j] = p[i].position[j]; 

}				


if(evalfunc(p[i].localg,3)<evalfunc(globalg,3)){

for(int k=0;k<dim;k++)
globalg[k] = p[i].localg[k];

						}


			}


				}
            
void printout(){

for(int i=0;i<popsize;i++){

for(int j=0;j<dim;j++){
cout << "partical" <<i<<"\n";
cout << evalfunc(p[i].position,3) << "\n";
			}
			  }
			  
for(int j=0;j<dim;j++){
cout << "Global Best = " <<evalfunc(globalg,3) << "\n";
			}

}

void mainloop(int iter_){

double rp[1000],rg[1000];

for(int iter=0;iter<iter_;iter++){

for(int j=0;j<dim;j++){
cout << "Global Best = " <<evalfunc(globalg,3) << "\n";
			}

for(int i=0;i<popsize;i++){

for(int j=0;j<dim;j++){

rp[j] = getlrand(lower,upper);
rg[j] = getlrand(lower,upper);

//Update velocity
p[i].velocity[j] = w*p[i].velocity[j] + deltap * rp[j] * (p[i].localg[j]-p[i].position[j]) + deltag*rg[j]*(globalg[j]-p[i].position[j]);

//Update position
p[i].position[j] = p[i].position[j] + lrt * p[i].velocity[j];

//cout<<p[i].position[0]<<"************\n";

			}
			
if(evalfunc(p[i].position,3)<evalfunc(p[i].localg,3)){

for(int k=0;k<dim;k++)
p[i].localg[k] = p[i].position[k];
						}			

if(evalfunc(p[i].localg,3)<evalfunc(globalg,3)){

for(int k=0;k<dim;k++)
globalg[k] = p[i].localg[k];
						}

				}
		}
}


};

double func1(double* pos,int dim){

/*dim=3*/

return pow(pos[0],2) + pow(pos[1],2) + pow(pos[3],2);
//return pos[0];
}


double getlrand(double lower,double upper){

return ((double) rand()/ RAND_MAX) * (upper-lower) + lower;

}


int main(){

swarm myswarm(55,3);
myswarm.initialise(0.34,0.05,0.055,0.75,10,-10,func1);
myswarm.mainloop(1000);
myswarm.printout();
}