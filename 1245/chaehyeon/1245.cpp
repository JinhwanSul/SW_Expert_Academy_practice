#include<iostream>

using namespace std;

double getAnswer(double, double);
double getForce(double);
int location[10];
int mass[10];
int number;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>number;
        for(int i =0;i<number;i++){
            cin>>location[i];
        }
        for(int i =0;i<number;i++){
            cin>>mass[i];
        }
        printf("#%d", test_case);
        for(int i =0; i<number-1;i++){
            double start = (double) location[i];
            double end = (double) location[i+1];
            double result = getAnswer(start,end);
            printf(" %.10f",result);
        }
        printf("\n");
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
double getAnswer(double start, double end){
    double mid = (start+end)/2.0;
    double force = getForce(mid);
    if(end-start<2e-12){
        return mid;
    }
    else if(force>0 ){
        return getAnswer(mid,end);
    }
    else return getAnswer(start, mid);

}
double getForce(double x){
    double totalForce=0;
    for(int i=0;i<number;i++){
        double distance = x-location[i];
        double force= mass[i]/(distance*distance);
        if(distance>0) totalForce+=force;
        else totalForce-=force;
    }
    return totalForce;
}