#include<bits/stdc++.h>
using namespace std;

// ANN

typedef long long ll;

void errorAnalysis(float o[2], float op, float acOp, float error[3], float v[2] ){

    error[2] = op*(1-op)*(acOp-op);
    error[0] = o[0]*(1-o[0])*(v[0]*error[2]);
    error[1] = o[1]*(1-o[1])*(v[1]*error[2]);

}

void updateWeight(float weight[][2], float mul, float ip[2], float v[2], float error[3], float o[2] ){

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            weight[i][j] += mul*error[j]*ip[i];
        }
    }

    for(int i=0; i<2; i++){
        v[i] += mul*error[2]*o[i];
    }
}

void calculate(float sum[2], float ip[2], float weight[][2], float bias[2], float o[2], float &op, float x0, float v[2], float acOp, float mul, float error[2] ){

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            sum[i] += ip[i]*weight[i][j];
        }

        sum[i] += x0*bias[0];
    }

    for(int i=0; i<2; i++){
        o[i] = (float)(1.0/(1.0 + exp(-sum[i]) ));
    }

    for(int i=0; i<2; i++){
        op += o[i]*v[i];
    }

    op += x0*bias[1];
    float temp = -op;
    op = (float)(1.0/(1.0 + exp(temp) ));

    float com =0;
    if(acOp > op) com = acOp-op;
    else com = op-acOp;

    while(com >= 0.01){

        for(int i=0; i<2; i++) sum[i] = 0;
        
        cout << fixed << setprecision(6) << op << "\t\t\t" << acOp << "\n";
        errorAnalysis(o, op, acOp, error, v);
        updateWeight(weight, mul, ip, v, error, o);
        calculate(sum, ip, weight, bias, o, op, x0, v, acOp, mul, error);

        if(acOp > op) com = acOp-op;
        else {
            com = op-acOp;    
        }
    }
}


int main(){

    float ip[2]={0.1,0.9}, acOp=0.9, bias[2]={0.1,0.2}, mul=0.25, 
        weight[2][2] = {{-0.2, -0.1}, {0.1, .03}}, v[2] = {0.2, 0.3}, x0 = 1;

    float v13[2]={0}, v23[2]={0}, sum[2] ={0}, o[2] ={0}, op=0, error[3] = {0};

    cout << "Received Output" << "\t\t\tExpected Output\n";

    calculate(sum, ip, weight, bias, o, op, x0, v, acOp, mul, error);

    cout << fixed << setprecision(6) << op << "\t\t\t" << acOp << "\n";

}