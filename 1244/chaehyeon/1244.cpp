#include<iostream>
#include<algorithm>
using namespace std;

int changeNumber(int, int, int);
void setAnswer(int);
void printNumber(int);
void swap(int, int);

int numbers[6]={0,};
int answer[6]={0,};
bool hasSameNumber;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
//    freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int oneToNine[10]={0,};
        hasSameNumber=false;
        int length =0;
        int numberOfSwap=0;
        char k='0';
        scanf("%c",&k);
        scanf("%c",&k);
        while(k!=' '){
            int i = k-'0';
            numbers[length]=i;
            oneToNine[i]++;
            length++;
            scanf("%c",&k);
        }
        scanf("%d",&numberOfSwap);
        for(int i =0;i<10;i++){
            if(oneToNine[i]>1){
                hasSameNumber= true;
                break;
            }
        }
        setAnswer(length);
        changeNumber(0,length,numberOfSwap);
        printf("#%d ",test_case);
        printNumber(length);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void printNumber(int length){
    for(int i =0; i<length;i++){
        printf("%d",numbers[i]);
    }
    printf("\n");
}
bool compare(int a, int b){
    return a>b;
}
void setAnswer(int length){
    for(int i=0;i<length;i++){
        answer[i]=numbers[i];
    }
    sort(answer,answer+length,compare);
}
int changeNumber(int start, int length, int numberOfSwap){
    if(numberOfSwap!=0) {
        for (int i = start; i < length; i++) {
            if (answer[i] != numbers[i]) {
                int count = 0;
                for (int k = i+1; k <length; k++) {
                    if (answer[i] == numbers[k]) {
                        if (count == 0) {
                            swap(i, k);
                        }
                        count++;
                    }
                }
                if (count > 1) {
                    return changeNumber(i + 1, length, numberOfSwap);
                }
                return changeNumber(i + 1, length, numberOfSwap - 1);
            }
        }
        if(numberOfSwap%2!=0 && !hasSameNumber){
            swap(length-2, length-1);
        }
    }
    return length;
}

void swap(int i, int j){
    int k = numbers[i];
    numbers[i]=numbers[j];
    numbers[j]=k;
}
