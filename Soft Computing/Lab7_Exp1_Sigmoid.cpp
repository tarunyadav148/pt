#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a=9999, c=0.003, x, y1, y2, mf;
    cout<<"Enter a number"<<endl;
    cin>>x;

    y1=-a*(x-c);

    y2=exp(y1);

    mf=1/(1+y2);



    cout<<"Fuzziness: "<<mf<<endl;
    

    return 0;
}