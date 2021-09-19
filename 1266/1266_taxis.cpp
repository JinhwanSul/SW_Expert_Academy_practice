#include <iostream>

using namespace std;

double prime_number(double s);
long long int combination18(int n);

int main(){
    int TC, sa, sb;
    int i,j;
    cin >> TC;
    for(i=1;i<=TC;i++){
        cin >> sa >> sb;
        //printf("sa is %f\n",prime_number(sa/100.));
        //printf("sb is %f\n",prime_number(sb/100.));
        printf("#%d %f\n",i,1-(1-prime_number(sa/100.))*(1-prime_number(sb/100.)));
    }
    return 0;
}

double prime_number(double s){
    int prime[7] = {2,3,5,7,11,13,17};
    int i, j;
    double p = 0.;
    for(i=0;i<7;i++){
        double temp;
        temp = (double)(combination18(prime[i]))*1000000.;
        //printf("temp1 %d is %f\n",prime[i],temp);
        for(j=1;j<=prime[i];j++) temp *= s;
        //printf("temp2 %d is %f\n",prime[i],temp);
        for(j=1;j<=18-prime[i];j++) temp *= (1-s);
        //printf("last temp %d is %f\n",prime[i],temp);
        p += temp; 
    }
    p /= 1000000.;
    return p;
}

long long int combination18(int n){
    int i;
    long long int c = 1;
    for(i=1;i<=18;i++) c *= i;
    for(i=1;i<=n;i++) c /= i;
    for(i=1;i<=(18-n);i++) c /= i;
    return c;
}