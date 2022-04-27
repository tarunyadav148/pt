#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float targetOutput=17, actualOutput=0.0;
    float i1=0.3, i2=0.1, w1=0.9, w2=0.8, w3=1.5, w4=1.3, bias=0.02, error;
    for(int i=0;;i++)
    {
        actualOutput=i1*w1+i2*w2+bias;
        w1=w1*w3;
        w2=w2*w4;
        
        error=(targetOutput-actualOutput)/targetOutput*100;
        cout<<"Actual Output: "<<actualOutput<<endl;
        cout<<"Target Output: "<<targetOutput<<endl;
        cout<<"Error: "<<error<<"%"<<endl;



        if(actualOutput>=targetOutput)
            break;
    }
}