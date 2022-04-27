#include <iostream>
using namespace std;
int OR(int n1, int n2)
{
    int w1=1, w2=1, b=-0.5;
    int s=(n1*w1+n2*w2)+b;

    if(s>=1)
     return 1;

    else
    return 0;
}

int AND(int n1, int n2)
{
    int w1=1, w2=1, b=-1.5;
    int s=(n1*w1+n2*w2)+b;

    if(s==1)
     return 1;

    else
    return 0;
}

int NOT(int n)
{
    int w=-1, b=-0.5;
    int s=n*w+b;

    if(s>=0)
     return 1;

    else
    return 0;
}

int XOR(int n1, int n2)
{
    //XOR=AND(NOT(AND(n1,n2)), OR(n1,n2))
    int o1=AND(n1,n2);
    int o2=NOT(o1);
    int o3=OR(n1,n2);
    return AND(o2,o3);

}

int main()
{
    int x, y;
    cout<<"Enter two inputs: "<<endl;
    cin>>x>>y;

    cout<<XOR(x,y);
    
    
}