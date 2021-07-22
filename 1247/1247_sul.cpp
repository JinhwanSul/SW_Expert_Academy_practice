#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

bool visited[10] = {false, };
int dist[12][12];
int x[12] = {-1,};
int y[12] = {-1,};
int N, answer;
int calc_dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] -y[j]);
}

void DFS(int v, int cnt, int distance)
{
    // printf("v= %d, cnt= %d, distance= %d, N=%d\n", v, cnt, distance, N);
    int i;
    if(cnt == N) {
        distance += calc_dist(v, N+1);
        if(distance < answer) {
            answer = distance;
        }
        return;
    }
    for(i = 1; i <= N; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            distance += dist[v][i];
            cnt++;
            DFS(i, cnt, distance);
            visited[i] = false;
            cnt--;
            distance -= dist[v][i];
        }
    }
    return;
}

int main(int argc, char** argv)
{
	int test_case;
	int i, j, T;
	cin>>T;
	freopen("input copy.txt", "r", stdin);

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        cin>>x[0]>>y[0]>>x[N+1]>>y[N+1]; // 0 is company, N+1 is home
        for(i = 1; i < N+1; i++) {
            cin>>x[i]>>y[i];
        }

        for(i = 0; i < N+2; i++) {
            for (j = 0; j < N+2; j++) {
                if(i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = calc_dist(i, j);
            }
        }
        answer = INT32_MAX;
        visited[0] = true;
        DFS(0, 0, 0);
        printf("#%d %d\n", test_case, answer);
	}
	return 0;
}