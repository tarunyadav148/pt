#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float m=0.7, a=0.1*m, b=0.9*m, sig, x;
    sig=b-a;

    
    float mf,y , w1=0.03, w2=0.5, bias=0.2, target;
    cout<<"Enter a number"<<endl;
    cin>>x;

y=-0.5*((x-m)/sig)*((x-m)/sig);

mf=exp(y);

cout<<"Fuzziness: "<<mf<<endl;
    

    return 0;
}