#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

using namespace std;

void Search(double num, int decimal, int n_th);

int N, x[10], m[10];
double balance_point[10];

int main(){
    int TC;
    int i,j;

    cin >> TC;
    
    for(i=0; i<TC; i++){
        cin >> N;
        for(j=0; j<N; j++){
            cin >> x[j];
        }
        for(j=0; j<N; j++){
            cin >> m[j];
        }
        for(j=0; j<N-1; j++){
            Search((double)x[j],1,j);
        }
        printf("#%d ",i+1);
        for(j=0; j<N-1; j++){
            printf("%.10f ",balance_point[j]);
        }
        printf("\n");
    }
    return 0;
}

void Search(double num, int decimal, int n_th){
    if(decimal >= 13){
        balance_point[n_th] = num;
        return;
    }
    //printf("num is %f, decimal is %d, n_th is %d, ",num,decimal,n_th);
    double step = pow(0.1,decimal);
    //printf("step is %f\n",step);
    double force = -1;
    int i;
    while(force <= 0){
        num += step;
        if(num >= x[n_th+1]) break;
        force = 0;
        for(i=0; i<N; i++){
            if(x[i] < num)  force -= m[i]/(x[i]-num)/(x[i]-num);
            else            force += m[i]/(x[i]-num)/(x[i]-num);
        }
        //printf("force is %f\n", force);
    }
    Search(num-step, decimal+1, n_th);
}