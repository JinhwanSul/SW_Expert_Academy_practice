#include <iostream>

using namespace std;

int am[1000][1000];
int mark[1000];
int dist[1000];
int cc[1000];

class Queue{
private:
    
public:
    int element[1001];
    int rear;
    int front;
    void enqueue(int n){
        element[rear] = n;
        rear++;
    };
    int dequeue(){
        front++;
        return element[front-1];
    };
    int isEmpty(){
        if(rear == front) return 1;
        else return 0;
    }
    Queue(){
        rear = 0;
        front = 0;
    };
};

int main(){
    int TC, N;
    int i, j, k;
    //int** am;
    
    cin >> TC;
    for(i=1; i<=TC; i++){
        
        cin >> N;
        //am = (int**)malloc(sizeof(int*)*N);
        //for(j=N-1;j>=0;j--) am[j] = (int*)malloc(sizeof(int)*N);
        for(j=0;j<N;j++) for(k=0;k<N;k++) cin >> am[j][k];
        for(j=0;j<N;j++) cc[j] = 0;
        // cout << "hey1" << endl;
        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                mark[k] = 0;
                dist[k] = -1;
            } 
            Queue q;
            q.enqueue(j);
            mark[j] = 1;
            dist[j] = 0;
            // cout << "hey3" << endl;
            while(q.isEmpty() == 0){
                int temp = q.dequeue();
                for(k=0;k<N;k++){
                    if(am[temp][k] == 1 && mark[k] == 0){
                        q.enqueue(k);
                        mark[k] = 1;
                        dist[k] = dist[temp] + 1;
                    }
                }
                // cout << "q.front is " << q.front << " q.rear is " << q.rear << endl;
            }
            // cout << "hey4" << endl;
            for(k=0;k<N;k++){
                if(dist[k] > 0) cc[j] += dist[k];
            }
        }
        // cout << "hey2" << endl;
        int min = cc[0];
        for(j=1; j<N; j++){
            if(min > cc[j]) min = cc[j];
        }
        printf("#%d %d\n",i,min);
        // for(j=N-1;j>=0;j--) free(am[j]);
    }
    return 0;
}