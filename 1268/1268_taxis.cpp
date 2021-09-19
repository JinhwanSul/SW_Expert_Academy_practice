#include <iostream>

using namespace std;

int GCD(int a, int b);
void quick_sort(int *data, int start, int end);

int robot[5000][2];
int unique[5000][2];
//int isExist[5000][5000][4];
int A[10000];
int B[10001];
int C[5000];
int main(){
    int T, R, N, K;
    int i, j, k, l;
    cin >> T;
    // printf("%d\n",GCD(0,15));
    for(i=1;i<=T;i++){
        cin >> R >> N >> K;
        for(j=0;j<N;j++) cin >> robot[j][0] >> robot[j][1];

        //for(j=0;j<N;j++) A[j] = 0;
        for(j=0;j<N;j++){
            int a = 0;
            for(k=0;k<N;k++){
                unique[k][0] = 0;
                unique[k][1] = 0;
            }
            for(k=0;k<N;k++){
                if(j==k) continue;
                int x = robot[j][0] - robot[k][0];
                int y = robot[j][1] - robot[k][1];
                int gcd = GCD(x,y);
                int isUnique = 1;
                x = x/gcd;
                y = y/gcd;
                for(l=0;l<a;l++){
                    if(x==unique[l][0] && y==unique[l][1]){
                        isUnique = 0;
                        break;
                    }
                }
                if(isUnique){
                    unique[a][0] = x;
                    unique[a][1] = y;
                    a++;
                }
            } 
            A[j] = a;
        }
        //printf("hey\n");
        int sum = 0;
        for(j=0;j<N;j++){
            //printf("A[%d]=%d\n",j,A[j]);
            sum += A[j];
        }

        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                A[k] = ((A[k] *K + (k+1)) % N) + 1; // 상수 K는 입력으로 주어짐
                A[N + k] =((A[k] * (k+1) + K) % N) + 1;
            }
            //for(k=0;k<2*N;k++) printf("A[%d] is %d\n",k,A[k]);
            quick_sort(A,0,2*N-1);
            //printf("After sorting...\n");
            //for(k=0;k<2*N;k++) printf("A[%d] is %d\n",k,A[k]);
            B[0] = 1;
            for(k=1;k<=2*N;k++){
                B[k] = ((B[k-1]* A[k-1] + k) % N) + 1;
            }
            C[j] = B[2*N];
        }

        int csum = 0;
        for(j=0;j<N;j++){
            //printf("A[%d]=%d\n",j,A[j]);
            csum += C[j];
        }
        printf("#%d %d %d\n",i,sum,csum);
    }
    return 0;
}

void quick_sort(int *data, int start, int end){ 
    if(start >= end){ // 원소가 1개인 경우 
    return; } 
    int pivot = start; 
    int i = pivot + 1; // 왼쪽 출발 지점 
    int j = end; // 오른쪽 출발 지점 
    int temp; 
    while(i <= j){ // 포인터가 엇갈릴때까지 반복 
        while(i <= end && data[i] <= data[pivot]){
            i++; 
            } 
        while(j > start && data[j] >= data[pivot]){ 
            j--; 
            } 
        if(i > j){ // 엇갈림 
        temp = data[j]; 
        data[j] = data[pivot]; 
        data[pivot] = temp; 
        }
        else{ // i번째와 j번째를 스왑 
        temp = data[i]; 
        data[i] = data[j]; 
        data[j] = temp; 
        } 
    } // 분할 계산 
    quick_sort(data, start, j - 1); 
    quick_sort(data, j + 1, end); 
}


int GCD(int a, int b){
    int p, q;
    p = a>0? a:-a;
    q = b>0? b:-b;
    if(p < q) return GCD(q, p);
    else if(q == 0) return p;
    else return GCD(q, p % q); 
}