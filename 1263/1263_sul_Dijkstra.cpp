#include<iostream>

using namespace std;

int conn[1000][1000];
int dist[1000];
bool visited[1000];

void Dijkstra(int src, int N);
int extract_min(void);

int main(int argc, char** argv)
{
	int test_case;
	int T, N, sum;
	freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin>>conn[i][j];
            }
        }

        int min_cc = INT32_MAX;
        for (int src = 0; src < N; src++) {
            for(int i = 0; i < N; i++) {
                dist[i] = INT32_MAX;
                visited[i] = false;
            }
            Dijkstra(src, N);
            sum = 0;
            for(int i = 0; i < N; i++) {
                sum += dist[i];
            }
            if(sum < min_cc) {
                min_cc = sum;
            }
        }
        printf("#%d %d\n",test_case, min_cc);
	}
	return 0;
}

int extract_min(int N)
{
    int min_u = -1, min_dist = INT32_MAX;
    for(int i = 0; i < N; i++) {
        if(visited[i] == false) {
            if(dist[i] < min_dist) {
                min_u = i;
                min_dist = dist[i];
            }
        }
    }
    return min_u;
}

void Dijkstra(int src, int N)
{
    int u;
    dist[src] = 0;
    for(int i = 0; i < N; i++) {
        u = extract_min(N);
        visited[u] = true;
        for (int j = 0; j < N; j++) {
            if (conn[u][j] == 1 && visited[j] == false) {
                if(dist[j] > dist[u] + 1) {
                    dist[j] = dist[u] + 1;
                }
            }
        }
    }
}