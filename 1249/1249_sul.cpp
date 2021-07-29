#include <iostream>

#define MAXQUEUE 1000
using namespace std;

int board[100][100];
int visited[100][100];
int RT[100][100];
int N;

struct item {
    int i;
    int j;
    int T;
};
struct item queue[MAXQUEUE];
int rear = 0, front = 0;


void enqueue(struct item it)
{
    int next = (rear + 1) % MAXQUEUE; 
    if(next == front) {
        printf("[Error] enqueueing when queue is full\n");
        return;
    }
    queue[rear] = it;
    rear = next;
}

struct item dequeue()
{
    struct item ret = queue[front];
    if(front == rear) {
        printf("[Error] dequeueing when queue is empty\n");
        struct item dum;
        return dum;
    }
    front = (front + 1) % MAXQUEUE;
    return ret;
}

int is_Qempty(void) 
{
    if(front == rear) {
        return 1; // queue is empty
    }
    return 0;
}

void clear_board(void) {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            board[i][j] = -1;
            visited[i][j] = 0;
            RT[i][j] = 0;
        }
    }
}

void BFS(int start_i, int start_j)
{
    visited[start_i][start_j] = 1;
    struct item S = {.i = start_i, .j = start_j, .T = 0};
    struct item temp;
    enqueue(S);
    while(!is_Qempty()) {
        temp = dequeue();
        if (temp.i+1 < N) {
            if (visited[temp.i+1][temp.j] == 0 || 
                (visited[temp.i+1][temp.j] == 1 && RT[temp.i+1][temp.j] > RT[temp.i][temp.j] + board[temp.i+1][temp.j])) {
                
                visited[temp.i+1][temp.j] = 1;
                RT[temp.i+1][temp.j] = RT[temp.i][temp.j] + board[temp.i+1][temp.j];
                struct item new_one;
                new_one.i = temp.i+1;
                new_one.j = temp.j;
                new_one.T = board[temp.i+1][temp.j];
                enqueue(new_one);
            }
        }

        if (temp.i-1 >= 0) {
            if (visited[temp.i-1][temp.j] == 0 || 
                (visited[temp.i-1][temp.j] == 1 && RT[temp.i-1][temp.j] > RT[temp.i][temp.j] + board[temp.i-1][temp.j])) {
                
                visited[temp.i-1][temp.j] = 1;
                RT[temp.i-1][temp.j] = RT[temp.i][temp.j] + board[temp.i-1][temp.j];
                struct item new_one;
                new_one.i = temp.i-1;
                new_one.j = temp.j;
                new_one.T = board[temp.i-1][temp.j];
                enqueue(new_one);
            }
        }

        if (temp.j+1 < N) {
            if (visited[temp.i][temp.j+1] == 0 || 
                (visited[temp.i][temp.j+1] == 1 && RT[temp.i][temp.j+1] > RT[temp.i][temp.j] + board[temp.i][temp.j+1])) {
                
                visited[temp.i][temp.j+1] = 1;
                RT[temp.i][temp.j+1] = RT[temp.i][temp.j] + board[temp.i][temp.j+1];
                struct item new_one;
                new_one.i = temp.i;
                new_one.j = temp.j+1;
                new_one.T = board[temp.i][temp.j+1];
                enqueue(new_one);
            }
        }

        if (temp.j-1 >= 0) {
            if (visited[temp.i][temp.j-1] == 0 || 
                (visited[temp.i][temp.j-1] == 1 && RT[temp.i][temp.j-1] > RT[temp.i][temp.j] + board[temp.i][temp.j-1])) {
                
                visited[temp.i][temp.j-1] = 1;
                RT[temp.i][temp.j-1] = RT[temp.i][temp.j] + board[temp.i][temp.j-1];
                struct item new_one;
                new_one.i = temp.i;
                new_one.j = temp.j-1;
                new_one.T = board[temp.i][temp.j-1];
                enqueue(new_one);
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input copy.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        clear_board();
        char c;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin>>c;
                board[i][j] = c - '0';
            }
        }

        BFS(0, 0);
        printf("#%d %d\n", test_case, RT[N-1][N-1]);
	}
	return 0;
}