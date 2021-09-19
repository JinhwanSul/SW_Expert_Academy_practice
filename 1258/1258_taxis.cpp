// freopen("input.txt", "r", stdin);
#include <iostream>

using namespace std;

int main(){
    int TC, n, oTC;
    int i, j, k;
    int row, col;
    int garo, sero;
    int plate[101][101];
    int submatrix[20][3];
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
        k=0;
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
        //printf("submatrix[%d]: %d, %d\n",i,submatrix[i][0],submatrix[i][1]);
        printf("#%d %d ",oTC-TC,k);
        for(i=0; i<k; i++){
            printf("%d %d ",submatrix[i][0],submatrix[i][1]);
        }
        printf("\n");
    }
    return 0;
}