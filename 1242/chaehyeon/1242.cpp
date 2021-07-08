/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<bool> transfer(string);
int totalResult(string curr, string prev);
vector<int> checkLength(vector<bool>);
int getNumber(vector<bool>, int, int);
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
        int m=0,n=0;
        cin>>m>>n;
        string prevLine="";
        string currentLine;
        string zeros= "";
        vector<string> differLines;
        int length=0;
        bool isFirst=true;
        int result=0;
        for(int i =0; i<n;i++){
            zeros+="0";
        }
        prevLine=zeros;
        getline(cin, currentLine);
        for(int i = 0; i<m;i++){
            getline(cin, currentLine);
            if(currentLine!=zeros){
                if(currentLine!=prevLine){
                    result+= totalResult(currentLine, prevLine);
                }
            }
            prevLine=currentLine;
        }
        printf("#%d %d\n",test_case,result);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int getResult(vector<bool> boolCodes, vector<int> pair ){
    int length = pair.front();
    int last = pair.back();
    int codes[8]={0,};
    int k =7;
    int sum_odd=0;
    int sum_even=0;
    for(int i=last;i>last-length*8;i-=length){
        codes[k]=getNumber(boolCodes,i, length);
        if(k%2==0){
            sum_odd+=codes[k];
        }
        else{
            sum_even+=codes[k];
        }
        k--;
    }
    if((sum_odd*3+sum_even)%10==0){
        return sum_even+sum_odd;
    }
    else return 0;


}
int totalResult(string curr, string prev){
    static vector<string> differSet;
    differSet.clear();
    string s="0";
    int i = curr.size()-1;
    int results=0;
    while (i>=0){
        if(curr[i]!='0' && prev[i]=='0'){
            string target = curr.substr(0,i+1);
            vector<bool> boolCodes =transfer(curr.substr(0,i+1));
            vector<int> pair = checkLength(boolCodes);
            int length = pair.front()*2+1;
            i-=length;
            results+= getResult(boolCodes, pair); //
        }
        i--;
    }
    return results;
}
vector<int> checkLength(vector<bool> codes){
    int count = -1;
    int last=0;
    int start=0;
    for(int i = codes.size()-1;i>1;i--){
        if(count==-1 && codes[i]==true){
            last = i;
            count++;
        }
        else if(count==2 && codes[i]==true){
            start = i;
            break;
        }
        if(codes[i]==true && codes[i-1]==false) count++;
    }
    vector<int> pair;
    pair.push_back(last-start);
    pair.push_back(last);
    return pair;
}
int change(int ratio){
    switch(ratio){
        case 3211:
            return 0;
        case 2221:
            return 1;
        case 2122:
            return 2;
        case 1411:
            return 3;
        case 1132:
            return 4;
        case 1231:
            return 5;
        case 1114:
            return 6;
        case 1312:
            return 7;
        case 1213:
            return 8;
    }
    return 9;
}
int getNumber(vector<bool> codes, int position, int length){
    vector<int> numbers;
    int count = 1;
    for(int i=position;i>position-length;i--){
        if(i==position-length+1 || codes[i]!=codes[i-1]){
            numbers.push_back(count);
            count=0;

        }
        count++;
    } // numbers 는 역순으로 저장되어 있음
    int min =100;
    for(int i =0; i<4; i++){
        if(min>numbers[i]){
            min =numbers[i];
        }
    }
    count=0;
    for(int i =0; i<4; i++){
        if(min!=1) numbers[3-i] /= min;
        count= count*10+ numbers[3-i];
    }
    return change(count);
}

vector<bool> transfer(string line){
    static vector<bool> vector;
    bool temp[4];
    int k;
    for(char c: line){
        if(c>='0'&& c<='9'){
            k= c-'0';
        }
        else{
            k = c-'A'+10;
        }
        for(int i =0; i<4;i++){
            if(k%2==1) temp[3-i]=true;
            else temp[3-i]=false;
            k=k/2;
        }
        for(int i = 0; i<4;i++){
            vector.push_back(temp[i]);
        }
    }
    return vector;
}
