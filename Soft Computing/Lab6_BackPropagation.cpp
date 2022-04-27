#include <iostream>
using namespace std;
int main()
{
    float i1=0.1, i2=0.9, w11=-0.2, w12=-0.1, w21=-0.1, w22=0.3, v13=0.2, v23=0.3, net1, net2, net3;
    float target1=0.2, target2=0.7, target=0.9, o1, o2, o3, bias=0.1, e1, e2, e3, n=0.25, d=0.9;
    for (int i = 0; ;i++)
    {
       o1=i1*w11+i2*w21+bias;
       e1=(target1-o1)/target1;
        
       o2=i1*w12+i2*w22+bias;
       e2=(target2-o2)/target2;

       o3=o1*v13+o2*v23+bias;
       e3=(target-o3)/target;
       
       w11=w11+n*i1*e1;
       w12=w12+n*i1*e2;
       w22=w22+n*i2*e2;
       w21=w21+n*i2*e1;
       v13=v13+n*o1*e3;
       v23=v23+n*o2*e3;
       bias=bias+0.2;

    //    cout<<"O1:   "<<o1<<"    Error1: "<<e1<<endl<<"O2:  "<<o2<<"    Error2: "<<e2<<endl<<"O3: "<<o3<<"   Error3: "<<e3<<endl<<endl<<endl<<endl;
       

       if(o3>=target)
       break;
    
    }

    e3=o3*(1-o3)*(d-o3);
    e1=o1*(1-o1)*v13*e3;
    e2=o2*(1-o2)*v23*e2;
   
    cout<<"Final O1: "<<o1<<endl<<"Final O2: "<<o2<<endl<<"Final O3: "<<o3<<endl<<endl;
    cout<<"Final Error1: "<<e1<<endl<<"Final Error2: "<<e2<<endl<<"Final Error3: "<<e3<<endl;


    
    
    
    return 0;
}