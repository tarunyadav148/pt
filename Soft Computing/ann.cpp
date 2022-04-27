
#include <bits/stdc++.h>
using namespace std;
int lowerX = 3,upperX = 10,lowerY = 8,upperY  = 15;

int eval(vector<int> &a)
{
    return a[0]*a[0]-2*a[1]+30;
}
int rand_val(int lower,int upper)
{
    return lower+rand()%(upper-lower+1);
}
void initializePopulation(vector<vector<int>> &a,int size)
{
    srand(time(0));

    for(int i =0;i<size;i++)
    {
        a.push_back({rand_val(lowerX,upperX),rand_val(lowerY,upperY),0});
    }
}
bool com(vector<int> &a,vector<int>&b)
{
    return a[2]>b[2];
}
void selection(vector<vector<int>> &a)
{
    for(auto &x:a)
    {
        x[2]=eval(x);
    }
    sort(a.begin(),a.end(),com);
}
void cross(vector<vector<int>> &a)
{
    for(int i =0;i<a.size()/2;i++)
    {
        a[a.size()/2+i+1]={a[i+1][0],a[i][1],0};
    }
    a[a.size()-1]={rand_val(lowerX,upperX),rand_val(lowerY,upperY),0};
}

vector<int> generateGenerations(vector<vector<int>> &a,int iterations)
{
    initializePopulation(a,100);
   
    for(int i =0;i<iterations;i++)
    {
        selection(a);
        cross(a);
        
    }
    selection(a);
    return a[0];
}
int main()
{
    vector<vector<int>> a;
    vector<int> ans = generateGenerations(a,100);

    cout<<"x1 :"<<ans[0]<<"\nx2 : "<<ans[1]<<"\nFinal value of equations:"<<ans[2]<<endl;
}
Show quoted text
