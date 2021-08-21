#include<iostream>

using namespace std;
int n;
int** matrix;
int count;
void fillBoard(int);
int main(int argc, char** argv)
{
    int test_case;
    int T;

//    freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        matrix=(int**)malloc(sizeof(int*)*n);
        count=0;
        for(int i=0;i<n;i++){
            matrix[i]=(int*)malloc(sizeof(int)*n);
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
                if(i==j) matrix[i][j]=-1;
                else if(matrix[i][j]==0){
                    count++;
                }
            }
        }
        int number=2;
        while (count>0){
            fillBoard(number++);
        }
        int min=INT32_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
            }
            if(min>sum){
                min=sum;
            }
        }
        printf("#%d %d\n",test_case,min+1);

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void fillBoard(int number){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==number-1){
                for(int k=0;k<n;k++){
                    if(matrix[j][k]==1&&matrix[i][k]==0){
                        matrix[i][k]=number;
                        matrix[k][i]=number;
                        count=count-2;
                    }
                }
            }
        }
    }
}