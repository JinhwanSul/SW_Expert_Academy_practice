#include<iostream>
#include<string>
using namespace std;
int n=0;
int length=0;
string line="";
string* lines;
void doQuickSort(int start, int end){
    int biggerStart=start;
    int length=end-start+1;
    if(length<=1) return;
    else{
        string last=lines[end];
        for(int i=start;i<end;i++){
            if(lines[i]<last){
                string temp = lines[biggerStart];
                lines[biggerStart]=lines[i];
                lines[i]=temp;
                biggerStart++;
            }
        }
        lines[end]=lines[biggerStart];
        lines[biggerStart]=last;
        doQuickSort(start,biggerStart-1);
        doQuickSort(biggerStart+1,end);
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;

//    freopen("input.txt", "r", stdin);
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        cin>>line;
        length=line.length();
        int size=length*(length+1)/2;
        lines=new string[size];
        int index=0;
        for(int l=1;l<=length;l++){
            for(int i=0;i<=length-l;i++){
                lines[index]=line.substr(i,l);
                index++;
            }
        }

        doQuickSort(0,size-1);
        index=0;
        string past="";
        while (index!=n-1){
            if(lines[index]==past) n++;
            past=lines[index];
            index++;
        }
        cout<<"#"<<test_case<<" "+lines[index]<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
