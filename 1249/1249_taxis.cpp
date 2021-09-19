/*
    using BFS algorithm
*/
#include <iostream>
#include <string>
using namespace std;

void Search(int level);
int max(int a, int b);
int min(int a, int b);

int map[100][100];
int dist[100][100];
int N;

int main(){
    int TC;
    int i, j, k;
    string line;

    cin >> TC;
    for(i=1; i<=TC; i++){
        cin >> N;

        // initialization
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                dist[j][k] = 1000000;
            }
        }   

        // input
        for(j=0; j<N; j++){
            cin >> line;
            for(k=0; k<N; k++){
                map[j][k] = line[k] - '0';
            }
        }
        /*
        for(j=0; j<2*N-2; j++){
            Search(j);
        }
        */
       Search(0);
       /*
        cout << endl;
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                cout << dist[j][k] << " ";
            }
            cout << endl;
        }
        */
        cout << "#" << i << " " << dist[N-1][N-1] << endl;
    }
    return 0;
}

void Search(int n){
    int i, temp, backward = 0;
    if(n == 0){
        dist[0][0] = 0;
        dist[0][1] = map[0][1];
        dist[1][0] = map[1][0];
        Search(1);
    }
    if(n >= 2*N-2)    return;
    
    for(i=0; i<=n; i++){
        // dist[i][n-i]
        
        // inside map
        if(i<N && n-i<N){
            // up side, may be back to small level
            if(i-1 >= 0){
                if(dist[i][n-i]+map[i-1][n-i] < dist[i-1][n-i]){
                    //printf("when level is %d, up\n",n);
                    dist[i-1][n-i] = dist[i][n-i]+map[i-1][n-i];
                    backward = 1;
                }
            }
            // down side
            if(i+1 <= N-1){
                if(dist[i][n-i]+map[i+1][n-i] < dist[i+1][n-i]){
                    //printf("when level is %d, down\n",n);
                    dist[i+1][n-i] = dist[i][n-i]+map[i+1][n-i];
                }
            }
            // right side
            if(n-i+1 <= N-1){
                if(dist[i][n-i]+map[i][n-i+1] < dist[i][n-i+1]){
                    //printf("when level is %d, right\n",n);
                    dist[i][n-i+1] = dist[i][n-i]+map[i][n-i+1];
                }
            }
            // left side, may be back to small level
            if(n-i-1 >= 0){
                if(dist[i][n-i]+map[i][n-i-1] < dist[i][n-i-1]){
                    //printf("when level is %d, left\n",n);
                    dist[i][n-i-1] = dist[i][n-i]+map[i][n-i-1];
                    backward = 1;
                }
            }
        }
    }
    if(backward == 1)   Search(n-1);
    else Search(n+1);
}

int max(int a, int b){
    return a>b ? a:b; 
}

int min(int a, int b){
    return a>b ? b:a; 
}