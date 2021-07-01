#include <stdio.h>

int main(){
    int score[101];
    int result[10];
    int i, j, T, dum;
    int maxcnt = 0;
    int most_frequent;

    for(i=0; i<101; i++){
        score[i] = 0;
    }
    setbuf(stdout, NULL);
    scanf("%d",&T);
    for(i=0; i<T; i++){
        scanf("%d",&dum);
        for(j=0; j<1000; j++){
            scanf("%d",&dum);
            score[dum]++;
        }
        for(j=0; j<101; j++){
            if(maxcnt <= score[j]){
                maxcnt = score[j];
                most_frequent = j;
            }
            score[j] = 0;
        }
        result[i] = most_frequent;
        maxcnt = 0;
    }

    for(i=0; i<T; i++){
        printf("#%d %d\n",i+1,result[i]);
    }
    return 0;
}