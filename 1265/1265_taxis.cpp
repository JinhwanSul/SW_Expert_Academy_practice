#include <iostream>

using namespace std;

int main(){
    int TC, N, P;
    int i, j, k;
    
    cin >> TC;
    for(i=1;i<=TC;i++){
        cin >> N >> P;
        int quotient = N/P;
        int remainder = N - quotient*P; 
        long long int answer = 1;
        while(P){
            while(remainder){
                answer *= quotient+1;
                P--;
                remainder--;
            }
            answer *= quotient;
            P--;
        }
        printf("#%d %lld\n",i,answer);
    }
    return 0;
}
