#include<iostream>

using namespace std;
int n;
char* first;
char* second;
int** board;
void fillBoard(int, int);
int main(int argc, char** argv)
{
    int test_case;
    int T;

//    freopen("input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        first=(char*)malloc(sizeof(char)*n);
        second=(char*)malloc(sizeof(char)*n);
        board=(int**)malloc(sizeof(int*)*(n+1));
        for(int i=0;i<n;i++){
            board[i]=(int*)malloc(sizeof(int)*(n+1));
            board[i][n]=0;
            cin>>first[i];
        }
        board[n]=(int*)malloc(sizeof(int)*(n+1));
        for(int i=0;i<n;i++){
            board[n][i]=0;
            cin>>second[i];
        }
        board[n][n]=0;
        //lower triangle
        for(int start=n-1;start>=0;start--){
            for(int i=0;i<n-start;i++){
                fillBoard(n-1-i,start+i);
            }
        }
        //upper triangle
        for(int start=n-2;start>=0;start--){
            for(int i=0;i<start+1;i++){
                fillBoard(start-i,i);
            }
        }
        double ratio=(board[0][0]+0.0)/((double)n)*100;
        printf("#%d %.2f\n",test_case,ratio);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void fillBoard(int i, int j){
    char pivot1=first[i];
    char pivot2=second[j];
    int maxvalue=board[i+1][j+1];
    for(int k=j;k<n;k++){
        if(pivot1==second[k]){
            int temp =1+board[i+1][k+1];
            if(maxvalue<temp) maxvalue=temp;
        }
    }
    for(int k=i;k<n;k++){
        if(pivot2==first[k]){
            int temp = 1+board[k+1][j+1];
            if(maxvalue<temp) maxvalue=temp;
        }
    }
    board[i][j]=maxvalue;
}