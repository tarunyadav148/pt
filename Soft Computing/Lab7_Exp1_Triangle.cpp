#include <iostream>
using namespace std;

int main()
{
    float a=0.3, b=0.5, c=0.9, x;
    
    cout<<"Enter a number"<<endl;
    cin>>x;

    float mf1=(x-a)/(b-a), mf2=(x-c)/(b-c);

    if(x>a&&x<b)
        cout<<"Fuzziness: "<<mf1<<endl;

    else if(x>b&&x<c)
        cout<<"Fuzziness: "<<mf2<<endl;

    else if(x==b)
        cout<<"Fuzziness: 1"<<endl;

    else
        cout<<"Fuzziness: 0"<<endl;

    

    return 0;
}