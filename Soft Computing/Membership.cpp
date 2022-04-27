#include<bits/stdc++.h>
using namespace std;

// Membership function

typedef long long ll;

void triangular(float x, float a, float b, float c){

    cout << "Enter 4 numbers : ";
    cin >> x >> a >> b >> c;

    if(x<=a) cout << 0 << "\n";
    else if(a<x && x<=b) cout <<((x-a)/(b-a)) << "\n";
    else if(b<x && x<=c) cout <<((c-x)/(c-b)) << "\n";
    else cout << "Output : " << 0 << "\n";
}

void trapezoidal(float x, float a, float b, float c, float d){

    cout << "Enter 5 numbers : ";
    cin >> x >> a >> b >> c >> d;

    if(x<=a) cout << 0 << "\n";
    else if(a<x && x<=b) cout <<((x-a)/(b-a)) << "\n";
    else if(b<x && x<=c) cout << 1 << "\n";
    else if(c<x && x<=d) cout <<((d-x)/(d-c)) << "\n";
    else cout << "Output : " << 0 << "\n";
}

void gaussian(float x, float c, float s){

    cout << "Enter 3 numbers : ";
    cin >> x >> c >> s;

    float ans = exp((-1.0/2.0)*((x-c)/s)*((x-c)/s));
    cout << "Output : " << ans << "\n";
}

void generalisedBell(float x, float a, float b, float c){

    cout << "Enter 4 numbers : ";
    cin >> x >> a >> b >> c;

    float ans = 1.0/(1.0 + pow(abs((x-c)/a), 2*b) );
    cout << "Output" << ans << "\n";
}

void sigmoid(float x, float a, float c){

    cout << "Enter 3 numbers : ";
    cin >> x >> a >> c;

    float ans = 1.0/(1.0 + exp(-a*(x-c)));
    cout << "Output" << ans << "\n";
}

int main(){

    float x,a,b,c,d,s;
    int num;
    cout << "Enter \n1 for triangular MFs \n2 for trapezoidal MFs \n3 for gaussian MFs \n4 for generalisedBell MFs \n5 for sigmoid MFs \nEnter input : ";

    cin >> num;

    if(num == 1) triangular(x,a,b,c);
    else if(num == 2) trapezoidal(x,a,b,c,d);
    else if(num == 3) gaussian(x,c,s);
    else if(num == 4) generalisedBell(x,a,b,c);
    else if(num == 5) sigmoid(x,a,c);
    else cout << "Incorrect input";
}