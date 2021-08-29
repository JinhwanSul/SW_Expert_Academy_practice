#include<iostream>

using namespace std;
double p1;
double p2;
double getProbability(double);
int prime[7]={2,3,5,7,11,13,17};
double combination[19]={0,};
int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin>>T;
    combination[0]=1;
    for(int i=1;i<19;i++){
        combination[i]=combination[i-1]*(19-i)/i;
    }
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>p1>>p2;
        p1=p1/100;
        p2=p2/100;
        double answer1= getProbability(p1);
        double answer2= getProbability(p2);
        double answer= 1-(1-answer1)*(1-answer2);
        printf("#%d %.6f\n",test_case,answer);

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
double getProbability(double p){
    double q=1-p;
    double answer=0;
    double pSeries[19]={0,};
    double qSeries[19]={0,};
    pSeries[0]=1;
    qSeries[18]=1;
    for(int i=1;i<19;i++){
        pSeries[i]=pSeries[i-1]*p;
        qSeries[18-i]=qSeries[19-i]*q;
    }
    for(int i=0;i<7;i++){
        int index=prime[i];
        answer+=combination[index]*pSeries[index]*qSeries[index];
    }
    return answer;
}