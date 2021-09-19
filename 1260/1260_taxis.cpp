// freopen("input.txt", "r", stdin);
#include <iostream>

using namespace std;

int min(int x, int y);

int main(){
    int TC, n, oTC;
    int i, j, k, iter;
    int row, col;
    int garo, sero;
    int plate[101][101];
    int submatrix[20][3];
    int a[20][2];
    int dp[20][20];
    int left, right, check;
    freopen("input.txt", "r", stdin);
    cin >> TC;
    oTC = TC;
    while(TC--){
        cin >> n;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cin >> plate[i][j];
            }
        }
        /* 1. finding submatrices */
        k=0;    // k : number of matrices
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(plate[i][j]){
                    if(i==0){
                        if(j==0){
                            submatrix[k][0] = i;
                            submatrix[k][1] = j;
                            k++;
                        }
                        else if(!plate[i][j-1]){
                            submatrix[k][0] = i;
                            submatrix[k][1] = j;
                            k++;
                        }
                    }
                    else if(!plate[i-1][j]){
                        if(j==0){
                            submatrix[k][0] = i;
                            submatrix[k][1] = j;
                            k++;
                        }
                        else if(!plate[i][j-1]){
                            submatrix[k][0] = i;
                            submatrix[k][1] = j;
                            k++;
                        }
                    }
                }
            }
        }
        for(i=0; i<k; i++){
            row = submatrix[i][0];
            col = submatrix[i][1];
            while(plate[row][col] && row < n){
                row++;
            }
            sero = row - submatrix[i][0];
            row--;
            while(plate[row][col] && col < n){
                col++;
            }
            garo = col - submatrix[i][1];      
            submatrix[i][0] = sero;
            submatrix[i][1] = garo;
            submatrix[i][2] = sero * garo;
            // printf("garo: %d, sero: %d\n",garo, sero);      
        }  
        
        /* sorting submatrices */
        int temp; 
        for(i=0; i<k; i++){
            for(j=k-1; j>i; j--){
                if(submatrix[j][2] < submatrix[j-1][2]){
                    temp = submatrix[j][0];
                    submatrix[j][0] = submatrix[j-1][0];
                    submatrix[j-1][0] = temp;
                    temp = submatrix[j][1];
                    submatrix[j][1] = submatrix[j-1][1];
                    submatrix[j-1][1] = temp;
                    temp = submatrix[j][2];
                    submatrix[j][2] = submatrix[j-1][2];
                    submatrix[j-1][2] = temp;
                }
                else if(submatrix[j][2] == submatrix[j-1][2] && submatrix[j][0] < submatrix[j-1][0]){
                    temp = submatrix[j][0];
                    submatrix[j][0] = submatrix[j-1][0];
                    submatrix[j-1][0] = temp;
                    temp = submatrix[j][1];
                    submatrix[j][1] = submatrix[j-1][1];
                    submatrix[j-1][1] = temp;
                    temp = submatrix[j][2];
                    submatrix[j][2] = submatrix[j-1][2];
                    submatrix[j-1][2] = temp;
                }
            }
        }
        // 쏘리 ㅎㅎ 귀찮았음 ㅎㅎ 버블쏘트 짱!
        //printf("submatrix[%d]: %d, %d\n",i,submatrix[i][0],submatrix[i][1]);
        //printf("#%d %d ",oTC-TC,k);
        for(i=0; i<k; i++){
            //printf("%d %d ",submatrix[i][0],submatrix[i][1]);
        }
        //printf("\n");

        /* 2. arranging submatrices to be multiplied well */
        for(i=0; i<k; i++){
            check = 0;
            for(j=0; j<k; j++){
                if(submatrix[i][0] == submatrix[j][1]){
                    check = 1;
                    break;
                }
            }
            if(check)   continue;
            else    break;
        }

        left = submatrix[i][0];
        right = submatrix[i][1];
        temp = 0;
        a[temp][0] = left;
        a[temp][1] = right;
        //printf("#%d %d %d ",oTC-TC,left,right);
        for(i=0; i<k-1; i++){
            for(j=0; j<k; j++){
                if(right == submatrix[j][0]){
                    left = submatrix[j][0];
                    right = submatrix[j][1];
                    a[++temp][0] = left;
                    a[temp][1] = right;
                    break;
                }
            }
            //printf("%d %d ",left,right);
        }
        //printf("\n");
        /*
        for(i=0; i<k; i++){
            printf("%d %d ",a[i][0],a[i][1]);
        }
        printf("\n");
        */

        /* 3. calcultae the smallest multiplication operation */
        for(i=0;i<k;i++) for(j=0;j<k;j++) dp[i][j] = 0;
        for(i=1;i<k;i++){
            for(j=0;j<k-i;j++){
                dp[j][j+i] = 9999999; 
                for(iter=j;iter<j+i;iter++){
                    dp[j][j+i] = min(dp[j][j+i], dp[j][iter] + dp[iter+1][j+i] + (a[j][0]*a[iter][1]*a[j+i][1]));
                }
            }
        }
        printf("#%d %d\n",oTC-TC,dp[0][k-1]);
    }
    return 0;
}

int min(int x, int y){
    return x < y ? x : y;
}