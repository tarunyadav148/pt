#include <iostream>
using namespace std;

class BeeColony
{
    public:
    int n=150;
    bool employedBee;
    bool escortBee;
    bool onlookerBee;

    BeeColony(bool emp, bool esc, bool on)
    {
        employedBee = emp;
        escortBee = esc;
        onlookerBee = on;
    }

    void Employee()
    {
        if (employedBee)
        {
            cout<<"Employed Bee found some food."<<endl;
        }
        
        else
        {
            cout<<"Employed Bee has now become Unemployed Bee."<<endl;
            employedBee = false;
        }
    }

    void UnemployeeEscort()
    {
        if(escortBee)
        {
            cout<<"Unemployed Bee has now become Employed Bee."<<endl;
            escortBee = true;
        }

        else
        {
            cout<<"Escort Bee has not found any food."<<endl;
        }
    }

    void UnemployeeOnlooker()
    {
        if(onlookerBee)
        {
            cout<<"Onlooker Bee passes the information of food to the Employed Bee."<<endl;
        }

        else
        {
            cout<<"Onlooker Bee has no information about food."<<endl;
        }
    }
};


int main()
{
    BeeColony Bee1(true, false, false);
    Bee1.Employee();
    Bee1.UnemployeeEscort();
    Bee1.UnemployeeOnlooker();

    cout<<endl<<endl;

    BeeColony Bee2(false, false, true);
    Bee2.Employee();
    Bee2.UnemployeeEscort();
    Bee2.UnemployeeOnlooker();

    cout<<endl<<endl;

    BeeColony Bee3(false, true, false);
    Bee3.Employee();
    Bee3.UnemployeeEscort();
    Bee3.UnemployeeOnlooker();

    cout<<endl<<endl;

    BeeColony Bee4(false, false, false);
    Bee4.Employee();
    Bee4.UnemployeeEscort();
    Bee4.UnemployeeOnlooker();
}