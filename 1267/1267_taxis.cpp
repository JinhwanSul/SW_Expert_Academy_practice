#include <iostream>

using namespace std;

int graph[1001][1001]; // [][0] index means isAfterExist 
int temporal[10000];
int answer[1001];
int visited[1001];
int l;

void compute_answer(int n);

int main(){
    int V, E;
    int i, j, k, temp;
    int start, end;
    // freopen("input.txt", "r", stdin);
    for(i=1;i<=10;i++){
        cin >> V >> E;
        for(j=1;j<=V;j++) for(k=0;k<=V;k++) graph[j][k] = 0;
        for(j=1;j<=V;j++) visited[j] = 0;
        for(j=1;j<=E;j++){
            cin >> start >> end;
            graph[start][0] = 1;
            k = 1;
            while(graph[end][k]) k++;
            graph[end][k] = start;
        }
        printf("#%d",i);
        for(j=1;j<=V;j++){
            if(graph[j][0] == 0){
                for(k=0;k<10000;k++) temporal[k] = 0;
                l = 0;
                compute_answer(j);
                for(k=l-1;k>=0;k--){
                    if(visited[temporal[k]]==0){
                        visited[temporal[k]] = 1;
                        printf(" %d",temporal[k]);
                    }
                } 
            } 
        }
        printf("\n");
    }
    return 0;
}

void compute_answer(int n){
    temporal[l] = n;
    l++;
    int i = 1;
    while(graph[n][i]){
        compute_answer(graph[n][i]);
        i++;
    } 
}
