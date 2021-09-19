#include <iostream>

using namespace std;
 
int lcs[502][502];

int main()
{
    int TC, N;
    int i, j, k;
    char* word1;
    char* word2;

    cin >> TC;
    for(i=1;i<=TC;i++){
        cin >> N;
        word1 = (char*)malloc(sizeof(char*)*(N+2));
        word2 = (char*)malloc(sizeof(char*)*(N+2));
        word1[0] = '0';
        word2[0] = '0';
        for(j=1;j<=N;j++) cin >> word1[j];
        for(j=1;j<=N;j++) cin >> word2[j];
        // for(j=0;j<=N;j++) for(k=0;k<=N;k++) lcs[j][k] = 0;

        for(j=0; j<=N; j++){
            for(k=0; k<=N; k++){
                if(j==0 || k==0){
                    lcs[j][k] = 0;
                }
                else if(word1[j] == word2[k]) lcs[j][k] = lcs[j-1][k-1] + 1;
                else{
                    if(lcs[j-1][k] > lcs[j][k-1]) lcs[j][k] = lcs[j-1][k];
                    else lcs[j][k] = lcs[j][k-1];
                }
            }
        }
        /*
        for(j=0;j<=N;j++){
            for(k=0;k<=N;k++){
                printf("%d ",lcs[j][k]);
            }
            printf("\n");
        }
        */
        printf("#%d %.2f\n",i,(double)lcs[N][N]/(double)N*100);
    }
    return 0;
}
