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
int gdc(int a,int b);
int decode_each(char* s);
int check_valid(int* code);

int main(){
    int TC, N, M;
    int i, j, k, l, m;

    char* s;
    char* ptr;
    char* itr;
    char* last1 = NULL;
    char* first1 = NULL;
    char* code;

    int isValid = 0;
    int decoded_value = 0;
    int valid_value[80];
    int temp_value[80];
    int prev_value[80];
    int curr_value[80];
    int values[40];
    //int code[8];
    int answer[20];

    scanf("%d",&TC);
    for(i=0; i<TC; i++){
        answer[i] = 0;
        scanf("%d %d",&N,&M);
        
        for(k=0; k<80; k++){
            prev_value[k] = 0;
            curr_value[k] = 0;
        }

        for(j=0; j<N; j++){
            
            s = (char*)malloc(sizeof(char)*(M+1));
            scanf("%s",s);
            //if(isValid == 1) continue;    
            ptr = s;
            last1 = NULL;
            first1 = NULL;
            
            while(*ptr != '\0'){ // finding position of the last nonzero
                if(*ptr != '0'){
                    if(first1 == NULL){
                        first1 = ptr;
                    }
                    last1 = ptr; 
                }
                ptr++;    
            }
            if(last1 != NULL){
                code = (char*)malloc(sizeof(char)*((last1-first1+1)*4+1));
                
                ptr = first1;
                itr = code;
                // convert hexadecimal code into binary code, saved in variable "code"
                while(ptr <= last1){
                    switch(*ptr){
                        case '0': sprintf(itr, "0000"); break;
                        case '1': sprintf(itr, "0001"); break;
                        case '2': sprintf(itr, "0010"); break;
                        case '3': sprintf(itr, "0011"); break;
                        case '4': sprintf(itr, "0100"); break;
                        case '5': sprintf(itr, "0101"); break;
                        case '6': sprintf(itr, "0110"); break;
                        case '7': sprintf(itr, "0111"); break;
                        case '8': sprintf(itr, "1000"); break;
                        case '9': sprintf(itr, "1001"); break;
                        case 'A': sprintf(itr, "1010"); break;
                        case 'B': sprintf(itr, "1011"); break;
                        case 'C': sprintf(itr, "1100"); break;
                        case 'D': sprintf(itr, "1101"); break;
                        case 'E': sprintf(itr, "1110"); break;
                        case 'F': sprintf(itr, "1111"); break;
                        default: break;
                    }
                    ptr++;
                    itr += 4;
                }
                //printf("size of code is %d\n",strlen(code));
                //printf("code is %s\n",code);
                
                for(k=0;k<80;k++){
                    curr_value[k] = 0;
                }

                l = 0;

                while(decoded_value != -2){
                    decoded_value = decode(code);
                    if(decoded_value > 0){
                        //curr_value[decoded_value]++;
                        curr_value[l++] = decoded_value;
                    }
                }
                int newly_added = 1;
                int dec;
                for(k=0; k<l; k++){
                    for(m=0; m<40; m++){
                        if(curr_value[k] == prev_value[m]){
                            newly_added = 0;
                            break;
                        }
                    }
                    if(newly_added == 1){
                        dec = curr_value[k];
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                        dec /= 10;
                        answer[i] += dec%10;
                    }
                    newly_added = 1;
                }
                for(k=0; k<40; k++){
                    prev_value[k] = curr_value[k];
                }
                /*
                for(k=0;k<80;k++){
                    if(prev_value[k] < curr_value[k]){
                        answer[i] += k*(curr_value[k] - prev_value[k]); 
                    }
                    prev_value[k] = curr_value[k];
                }
                */
                decoded_value = 0;

                //check if code is valid
                free(code);
            }
            else{
                for(k=0; k<80; k++){
                    prev_value[k] = 0;
                }
            }
            free(s);
        }
        //isValid = 0;

    }
    
    for(i=0; i<TC; i++){
        printf("#%d %d\n",i+1,answer[i]);
    }
    
    return 0;
}

int decode(char *s){
    int is_one = 0;
    int is_zero = 1;
    int change_cnt = 0;
    int cnt_one_front = 0;
    int cnt_one_back = 0;
    int cnt_zero = 0;
    int mul;
    char* appended_code = NULL;
    char* compact_code;
    int i;
    int code[8];
    char* temp;

    char *ptr = strrchr(s, '1');
    if(ptr == NULL) return -2;
    while(ptr > s){
        if(*ptr == '1'){
            if(change_cnt == 0){
                *(ptr+1) = '\0';
                change_cnt++; 
            }
            if(change_cnt == 1){
                cnt_one_back++;
            }
            if(change_cnt == 2){
                change_cnt++;
            }
            if(change_cnt == 3){
                cnt_one_front++;
            }
        }
        if(*ptr == '0'){
            if(change_cnt == 1){
                change_cnt++;
            }
            if(change_cnt == 2){
                cnt_zero++;
            }
            if(change_cnt == 3){
                break;
            }
        }
        ptr--;
    }

    mul = gdc(gdc(cnt_one_back,cnt_one_front),cnt_zero);
    ptr = strrchr(s, '1');
    *(ptr+1) = '\0';
    ptr -= (56*mul);
    
    if(ptr < s){
        appended_code = (char*)malloc(sizeof(char)*56*mul+1);
        *(appended_code+56*mul) = '\0';
        for(i = 0; i < 56*mul - strlen(s); i++){
            appended_code[i] = '0';
        }
        appended_code[56*mul - strlen(s)] = '\0';
        strcat(appended_code,s);
        //printf("appended code is %s\n",appended_code);
        ptr = appended_code;
        compact_code = (char*)malloc(sizeof(char)*56+1);
        
        for(i = 0; i < 56; i++){
            compact_code[i] = *ptr;
            ptr += mul;
        }
        ptr = compact_code + 56;
        *ptr = '\0';
        //printf("compact code is %s\n",compact_code);
        
        for(i = 0; i < 8; i++){
            *ptr = '\0';
            ptr -= 7;
            code[7-i] = decode_each(ptr);
            // printf("code[%d] is %d\n",7-i,code[7-i]);
        }
        *s = '\0';
        free(compact_code);

        free(appended_code);
    }
    else{
        *ptr = '\0';
        ptr++;

        compact_code = (char*)malloc(sizeof(char)*56+1);
        
        for(i = 0; i < 56; i++){
            compact_code[i] = *ptr;
            ptr += mul;
        }
        ptr = compact_code + 56;
        *ptr = '\0';
        //printf("compact code is %s\n",compact_code);
        
        for(i = 0; i < 8; i++){
            *ptr = '\0';
            ptr -= 7;
            code[7-i] = decode_each(ptr);
            // printf("code[%d] is %d\n",7-i,code[7-i]);
        }
        
        free(compact_code);
    }
    
    return check_valid(code);
    // return 10000000*code[0]+1000000*code[1]+100000*code[2]+10000*code[3]+1000*code[4]+100*code[5]+10*code[6]+code[7];
}

int decode_each(char* s){

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

int check_valid(int* code){
    if( ((code[0]+code[2]+code[4]+code[6])*3 + code[1]+code[3]+code[5]+code[7]) % 10 == 0)
        // return code[0]+code[1]+code[2]+code[3]+code[4]+code[5]+code[6]+code[7];
        return 10000000*code[0]+1000000*code[1]+100000*code[2]+10000*code[3]+1000*code[4]+100*code[5]+10*code[6]+code[7];
    else return -1;
}

int gdc(int a,int b) 
{         
           int i,j;
           int temp; 
           j = (a<b)?a:b; 

           for(i=j;i>=1;i--) {
                if(a%i==0 && b%i==0){
                    temp = i;
                    break;
                }
           }
           return temp;
}

