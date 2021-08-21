#include<iostream>

using namespace std;
int totalD;
int n;
long long ** board;
void fillBoard(int,int);
int main(int argc, char** argv)
{
    int test_case;
    int T;
//    freopen("input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>totalD>>n;
        board=(long long**)malloc(sizeof(long long*)*n);
        for(int i=0;i<n;i++){
            board[i]=(long long*)malloc(sizeof(long long)*totalD);
            for(int j=i;j<totalD;j++){
                fillBoard(i,j);
            }
        }
        printf("#%d %lld\n",test_case,board[n-1][totalD-1]);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void fillBoard(int i, int j){
    int numberOfMul=i;
    int dalant=j+1;
    if(numberOfMul==0) board[i][j]=dalant;
    else{
        long long max=0;
        for(int first=1;first<=dalant-numberOfMul;first++){
            long long temp= first * board[numberOfMul-1][dalant-first-1];
            if(temp>max) max=temp;
        }
        board[i][j]=max;
    }

}