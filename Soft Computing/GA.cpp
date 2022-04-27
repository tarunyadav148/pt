#include <iostream>
#include <algorithm>


using namespace std;

void Mutation(int newInitialization[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        // if()
        // {
            cout<<"Enter the new values of x1 and x2 for test case "<<i+1<<endl;
            for (int j = 0; j < 2; j++)
            {
                cout<<"Enter value of x"<<j+1<<": "<<endl;
                cin>>newInitialization[i][j];
            }
        // }
    }

}

void Crossover(int selected[][2], int t1, int t2)
{
    
    int temp=selected[t1][0];
    selected[t1][0]=selected[t2][1];
    selected[t2][1]=temp;
}

void Evoluation(int *f, int initialization[][2], int n)
{
     for (int i = 0; i < n; i++)
    {
        
        f[i]=initialization[i][0]*initialization[i][0]-2*initialization[i][1]+30;
        
    }
}
void init(int initialization[][2],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the values of x1 and x2 for test case "<<i+1<<endl;
        for (int j = 0; j < 2; j++)
        {
            // if((initialization[i][0]>=3&&initialization[i][0]<=10)||(initialization[i][1]>=8&&initialization[i][1]<=15))
            // {
                cout<<"Enter value of x"<<j+1<<": "<<endl;
                cin>>initialization[i][j];
            // }
            // else
            // {
            //     cout<<"Invalid Input!"<<endl;
            //     i=i-1;
            // }
        }
        
    }
    
}

int main()
{
    int x1, x2, n;
    cout<<"Enter the number of pairs of x1 and x2 to be inserted: "<<endl;
    cin>>n;
    int f[100];
    int initialization[100][2];

    // int initialization[7][2]={{3, 8},
    //                           {3, 9},
    //                           {4, 12},
    //                           {9, 8},
    //                           {10, 8},
    //                           {6, 13},
    //                           {5, 11}};

    init(initialization, n);

    // for (int i = 0; i < 7; i++)
    // {
        
    //     f[i]=initialization[i][0]*initialization[i][0]-2*initialization[i][1]+30;
        
    // }

    Evoluation(f, initialization, n);
    
    

    // sort(f,f+7);

    int max=f[0], t1, max2=f[0], t2;
    
    for (int i = 1; i < n; i++)
    {
        if(max<f[i])
        {
            max=f[i];
            t1=i;

        }
    }

    
    for (int i = 1; i < n; i++)
    {
        if(max2<f[i]&&i!=t1)
        {
            max2=f[i];
            t2=i;

        }
    }

    // cout<<max<<"    "<<t1<<endl;
    // cout<<max2<<"    "<<t2<<endl;

    // cout<<"Maximum value of f: "<<max<<" ,at: x1="<<initialization[t1][0]<<" and x2="<<initialization[t1][1]<<endl;

    int selected[2][2]={{initialization[t1][0],initialization[t1][1]},
                        {initialization[t2][0],initialization[t2][1]}};                                            
 
    // int temp=selected[t1][0];
    // selected[t1][0]=selected[t2][1];
    // selected[t2][1]=temp;
    Crossover(selected, t1, t2);

    for (int i = 0; i < 2; i++)
    {
        
        f[i]=selected[i][0]*selected[i][0]-2*selected[i][1]+30;
        
    }

    // for (int i = 0; i < 2; i++)
    // {
    //     cout<<f[i]<<endl;
    // }



    if(f[0]>f[1])
    cout<<"Fittest for: x1="<<selected[0][0]<<" and x2="<<selected[0][1]<<" Value: "<<f[0]<<endl;

    else if(f[0]<f[1])
    cout<<"Fittest for: x1="<<selected[1][0]<<" and x2="<<selected[1][1]<<" Value: "<<f[1]<<endl;

    else
    Mutation(initialization, n);
    

    
}