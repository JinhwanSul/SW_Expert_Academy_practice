#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

void Search(int level);

int N, dist_min;
int client_x[10], client_y[10];
int workplace_x, workplace_y, home_x, home_y;
int stack[10];  // order of visiting clients
int check[10];  // check if i-th member is in stack

int main(){
    int TC;
    int i, j;

    cin >> TC;

    for(i=0; i<TC; i++){
        dist_min = 2000;

        for(j=0; j<10; j++){
            stack[j] = -1;
            check[j] = 0;
        }
        cin >> N;
        cin >> workplace_x >> workplace_y;
        cin >> home_x >> home_y;
        for(j=0; j<N; j++)  cin >> client_x[j] >> client_y[j];
        Search(0);
        printf("#%d %d\n",i+1,dist_min);
    }
    return 0;
}

void Search(int level){
    int i;

    // all in the stack, compute distance
    if(level >= N){
        int dist = 0;
        dist += abs(workplace_x - client_x[stack[0]]) + abs(workplace_y - client_y[stack[0]]);
        for(i=0; i<N-1; i++)    dist += abs(client_x[stack[i]] - client_x[stack[i+1]]) + abs(client_y[stack[i]] - client_y[stack[i+1]]);
        dist += abs(home_x - client_x[stack[N-1]]) + abs(home_y - client_y[stack[N-1]]);
        /*
        printf("order is ");
        for(i=0; i<N; i++){
            printf("%d ",stack[i]);
        }
        printf("\n");
        
        printf("dist is %d\n",dist);
        */
        if(dist < dist_min){
            dist_min = dist;
        } 
        return;
    }

    // stacking
    for(i=0; i<N; i++){
        if(check[i] == 0){
            check[i] = 1;
            stack[level] = i;
            Search(level+1);
            stack[level] = -1;
            check[i] = 0;
        }
    }
    return;
}