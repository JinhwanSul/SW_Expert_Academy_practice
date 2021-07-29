#include<iostream>
#include <vector>
using namespace std;
int n;
int **board;
int **answer;
bool **check;

void relaxation(int , int );
int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        board = (int**)malloc(sizeof(int*)*n);
        answer = (int**)malloc(sizeof(int*)*n);
        check = (bool**)malloc(sizeof(bool*)*n);
        for(int i=0;i<n;i++){
            char c;
            board[i]=(int*)malloc(sizeof(int)*n);
            answer[i]=(int*)malloc(sizeof(int)*n);
            check[i]=(bool*)malloc(sizeof(bool)*n);
            for(int j =0; j<n;j++){
                cin>>c;
                board[i][j]=c-'0';
                answer[i][j]=0;
                check[i][j]=false;
            }
        }

        check[0][0]=true;
        for(int i =0;i<n;i++){
            int k =i;
            for(int j =0; j<=i;j++){
                relaxation(k,j);
                k--;
            }
        }
        for(int i=1; i<n;i++){
            int k =n-1;
            for(int j=i;j<n;j++){
                relaxation(k,j);
                k--;
            }
        }
        printf("#%d %d\n", test_case,answer[n-1][n-1]);
        // distructor
        for(int i=0;i<n;i++){
            delete board[i];
            delete answer[i];
        }
        delete board;
        delete answer;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void relaxation(int x, int y){
    if(x==n-1 && y==n-1) return;
    else{
        if(x>0){
            int value = answer[x][y]+board[x-1][y];
            if(check[x-1][y]){
                if(answer[x-1][y]>value){
                    answer[x-1][y]=value;
                    relaxation(x-1,y);
                }
            }
            else{
                check[x-1][y]=true;
                answer[x-1][y]=value;
            }
        }
        if(x<n-1){
            int value = answer[x][y]+board[x+1][y];
            if(check[x+1][y]){
                if(answer[x+1][y]>value){
                    answer[x+1][y]=value;
                    relaxation(x+1,y);
                }
            }
            else{
                check[x+1][y]=true;
                answer[x+1][y]=value;
            }
        }
        if(y>0){
            int value = answer[x][y]+board[x][y-1];
            if(check[x][y-1]){
                if(answer[x][y-1]>value){
                    answer[x][y-1]=value;
                    relaxation(x,y-1);
                }
            }
            else{
                check[x][y-1]=true;
                answer[x][y-1]=value;
            }
        }
        if(y<n-1){
            int value = answer[x][y]+board[x][y+1];
            if(check[x][y+1]){
                if(answer[x][y+1]>value){
                    answer[x][y+1]=value;
                    relaxation(x,y+1);
                }
            }
            else{
                check[x][y+1]=true;
                answer[x][y+1]=value;
            }
        }
    }
}