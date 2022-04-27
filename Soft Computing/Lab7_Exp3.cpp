#include <iostream>

using namespace std;

string FuzzyWeather(string city)
{
    if(city=="Mumbai")
    return "Mostly Humid";

    else if(city=="Delhi")
    return "Humid in summers and Freezing in winters";

    else if(city=="Jaipur")
    return "Hot-Dry winds in summers and Freezing in winters";

    else if(city=="Hyderabad")
    return "Mostly rainy";

    else
    return "Weather not defined";
}

float CrispWeather(string city)
{
    if(city=="Mumbai")
    return 25.5;

    else if(city=="Delhi")
    return 21.7;

    else if(city=="Jaipur")
    return 28.9;

    else if(city=="Hyderabad")
    return 31.04;

   
}

string FuzzyPollution(string city)
{
    if(city=="Mumbai")
    return "Usually high level of pollution";

    else if(city=="Delhi")
    return "Usually very high level of pollution";

    else if(city=="Jaipur")
    return "Usually medium level of pollution";

    else if(city=="Hyderabad")
    return "Usually low level of pollution";

    else
    return "Weather not defined";
}

float CrispPollution(string city)
{
    if(city=="Mumbai")
    return 205.6;

    else if(city=="Delhi")
    return 281.7;

    else if(city=="Jaipur")
    return 154.7;

    else if(city=="Hyderabad")
    return 104.04;

   
}



 int main()
 {
     string cities[]={"Mumbai","Delhi","Jaipur","Hyderabad"};

     int n;
     cout<<"Enter city number from 0 to 3:"<<endl;

     cin>>n;

     cout<<"Fuzzy Weather condition of "<<cities[n]<<" is: "<<FuzzyWeather(cities[n])<<endl;
     cout<<"Crisp Weather condition of "<<cities[n]<<" is: "<<CrispWeather(cities[n])<<" C"<<endl;


 }