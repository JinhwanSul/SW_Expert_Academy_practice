/*
    using Prim Algorithm
*/
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;

double x[1000];
double y[1000];
double dist[1000][1000];
int in_graph[1000];
int N;
double total_dist, E;

void Compute_distance();
void Prim();

int main(){
    int TC;
    int i, j, k;
    // freopen("input.txt", "r", stdin);
    cin >> TC;    
    for(i=1; i<=TC; i++){
        // initialization
        total_dist = 0;
        for(j=0; j<1000; j++){
            in_graph[j] = 0;
            for(k=0; k<1000; k++){
                dist[j][k] = 0;
            }
        }   
        in_graph[0] = 1;

        // input
        cin >> N;
        for(j=0; j<N; j++){
            cin >> x[j];
        }
        for(j=0; j<N; j++){
            cin >> y[j];
        }
        cin >> E;
        
        Compute_distance();
        for(j=1; j<=N-1; j++){
            Prim();
        }
        printf("#%d %-13.lf\n",i,total_dist);
    }
    return 0;
}

void Compute_distance(){
    int i, j;
    double temp;
    for(i=0; i<N; i++){
        for(j=i; j<N; j++){
            dist[i][j] = E*(x[i]-x[j])*(x[i]-x[j]) + E*(y[i]-y[j])*(y[i]-y[j]);
            dist[j][i] = dist[i][j];
            //printf("dist[%d][%d] is %-13.lf\n",i,j,dist[i][j]);
        }
    }
    return;
}

void Prim(){
    int i, j;
    double min_dist = -1;
    int next_node;
    for(i=0; i<N; i++){
        if(in_graph[i] != 0){
            for(j=0; j<N; j++){
                if(in_graph[j] == 0){
                    if(min_dist == -1){
                        min_dist = dist[i][j];
                        next_node = j;
                    }
                    else if(min_dist > dist[i][j]){
                        min_dist = dist[i][j];
                        next_node = j;
                    }
                }
            }
        }
    }
    in_graph[next_node] = 1;
    total_dist += min_dist;
    return;
    //printf("next_node = %d, min_dist = %-13.lf\n",next_node,min_dist);
}