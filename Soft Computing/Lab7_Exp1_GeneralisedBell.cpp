#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a=0.3, b=2*a, c=0.8, slopeX, slopeY, x, mf, y1, y2;
    
    cout<<"Enter a number"<<endl;
    cin>>x;

    slopeX=b/2*a;
    slopeY=-b/2*a;

    y1=(x-c)/a;

    if(y1>0)

        y2=pow(y1,2*b);

    else
    {
        y1=-y1;
        y2=pow(y1,2*b);
    }

    mf=1/(1+y2);
    cout<<"Fuzziness: "<<mf<<endl;
    

    return 0;
}