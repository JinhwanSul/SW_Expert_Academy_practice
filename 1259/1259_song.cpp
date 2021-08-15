#include<iostream>

using namespace std;
int* males;
int* females;
int* order;
bool* check;
int n;
int main(int argc, char** argv)
{
    int test_case;
    int T;

//    freopen("input.txt", "r", stdin);
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        males=(int*)malloc(sizeof(int)*n);
        females=(int*)malloc(sizeof(int)*n);
        order=(int*)malloc(sizeof(int)*2*n);
        check=(bool *)malloc(sizeof(bool )*n);
        for(int i=0; i<n;i++){
            cin>>males[i]>>females[i];
            check[i]=true;
        }
        // 뒤에 있기
        order[0]=0;
        int male=males[0];
        int female=females[0];
        check[0]=false;
        int backNum=1;
        int frontNum=n;
        bool finish=true;
        while (finish){
            finish= false;
            for(int j=0; j<n;j++){
                if(check[j]){
                    if(males[j]==female){
                        order[backNum++]=j;
                        check[j]=false;
                        female=females[j];
                        finish=true;
                    }
                    else if(females[j]==male){
                        order[frontNum++]=j;
                        check[j]=false;
                        male=males[j];
                        finish=true;
                    }
                }
            }
        }
        printf("#%d", test_case);
        for(int i=frontNum-1;i>=n;i--){
            printf(" %d %d",males[order[i]],females[order[i]]);
        }
        for(int i=0;i<backNum;i++){
            printf(" %d %d",males[order[i]],females[order[i]]);
        }
        printf("\n");
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}