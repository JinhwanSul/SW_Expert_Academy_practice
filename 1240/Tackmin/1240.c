#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define D0 "0001101"
#define D1 "0011001"
#define D2 "0010011"
#define D3 "0111101"
#define D4 "0100011"
#define D5 "0110001"
#define D6 "0101111"
#define D7 "0111011"
#define D8 "0110111"
#define D9 "0001011"

int decode(char* s);

int main(){
    int TC, N, M;
    int i, j, k;
    char* s;
    char* ptr;
    char* last1 = NULL;
    int isValid = 0;
    int code[8];
    int answer[10];

    scanf("%d",&TC);
    for(i=0; i<TC; i++){
        answer[i] = 0;
        scanf("%d %d",&N,&M);
        
        for(j=0; j<N; j++){
            
            s = (char*)malloc(sizeof(char)*(M+1));
            scanf("%s",s);
            if(isValid == 1) continue;    
            ptr = strstr(s, "1");
            while(ptr != NULL){ // finding position of the last "1" 
                last1 = ptr;
                ptr = strstr(ptr+1,"1");
            }
            
            if(last1 != NULL){
                last1 += 1;
                for(k=0; k<8; k++){
                    *last1 = '\0';
                    last1 -= 7;
                    code[7-k] = decode(last1);
                }
                if( ((code[0]+code[2]+code[4]+code[6])*3 + code[1]+code[3]+code[5]+code[7]) % 10 == 0){
                    isValid = 1;
                    answer[i] = code[0]+code[1]+code[2]+code[3]+code[4]+code[5]+code[6]+code[7];
                }
            }
            last1 = NULL;
        }
        isValid = 0;
    }

    for(i=0; i<TC; i++){
        printf("#%d %d\n",i+1,answer[i]);
    }
    return 0;
}

int decode(char* s){
    if(strcmp(s, D0) == 0){
        return 0;
    }
    if(strcmp(s, D1) == 0){
        return 1;
    }
    if(strcmp(s, D2) == 0){
        return 2;
    }
    if(strcmp(s, D3) == 0){
        return 3;
    }
    if(strcmp(s, D4) == 0){
        return 4;
    }
    if(strcmp(s, D5) == 0){
        return 5;
    }
    if(strcmp(s, D6) == 0){
        return 6;
    }
    if(strcmp(s, D7) == 0){
        return 7;
    }
    if(strcmp(s, D8) == 0){
        return 8;
    }
    if(strcmp(s, D9) == 0){
        return 9;
    }
    return -1;
}