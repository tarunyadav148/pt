#include <iostream>

using namespace std;

int main()
{
    int a[5]={1,2,3,4,5}, b[5]={5,8,9,4,2};
    int crossoverPoint;

cout<<"Parents are:"<<endl;
for (int i = 0; i < 5; i++)
{
    cout<<a[i]<<"   ";

}
cout<<endl;

for (int i = 0; i < 5; i++)
{
    cout<<b[i]<<"   ";

}

  cout<<endl;  
    cout<<"Enter a Crossover Point: "<<endl;
    cin>>crossoverPoint;
cout<<"New Offsprings are:"<<endl;
for (int i = 0; i < 5; i++)
{
    if(i<crossoverPoint)
    cout<<a[i]<<"   ";

    else
    cout<<b[i]<<"   ";

}
cout<<endl;

for (int i = 0; i < 5; i++)
{
    if(i<crossoverPoint)
    cout<<b[i]<<"   ";

    else
    cout<<a[i]<<"   ";

}

}