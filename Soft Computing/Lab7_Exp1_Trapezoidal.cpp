#include <iostream>
using namespace std;

int main()
{
    float a=0.3, b=0.5, c=0.7, d=0.9, x;
    
    cout<<"Enter a number"<<endl;
    cin>>x;

    float mf1=(x-a)/(b-a), mf2=1 ,mf3=(x-c)/(b-c), mf4=0;

    if(x>a&&x<b)
        cout<<"Fuzziness: "<<mf1<<endl;

    else if(x>b&&x<c)
        cout<<"Fuzziness: "<<mf2<<endl;

    else if(x>c&&x<d)
        cout<<"Fuzziness: "<<mf3<<endl;

    else
        cout<<"Fuzziness: "<<mf4<<endl;

    

    return 0;
}