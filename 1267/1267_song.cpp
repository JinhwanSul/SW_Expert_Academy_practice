#include<iostream>

using namespace std;
int *numOfParents;
int V;
int N;
int** graph;
int findNoPredecessor();
int main(int argc, char** argv)
{
//    freopen("input.txt", "r", stdin);
    for(int test_case = 1; test_case <= 10; ++test_case)
    {
        cin>>V>>N;
        // graph 초기화
        graph=(int**)malloc(sizeof(int*)*V);
        numOfParents=(int*)malloc(sizeof(int)*V);
        for(int i=0;i<V;i++){
            graph[i]=(int*)malloc(sizeof(int)*V);
            numOfParents[i]=0;
            for(int j=0;j<V;j++){
                graph[i][j]=0;
            }
        }
        //입력
        for(int i=0;i<N;i++){
            int parents;
            int child;
            cin>>parents>>child;
            graph[parents-1][child-1]=1;
            numOfParents[child-1]++;
        }
        cout<<"#"<<test_case;
        for(int i=0;i<V;i++){
            int k=findNoPredecessor();
            cout<<" "<<k+1;
        }
        cout<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int findNoPredecessor(){
    for(int i=0;i<V;i++){
        if(numOfParents[i]==0){
            for(int j=0;j<V;j++){
                if(graph[i][j]==1) numOfParents[j]--;
            }
            numOfParents[i]=-1;
            return i;
        }
    }
}