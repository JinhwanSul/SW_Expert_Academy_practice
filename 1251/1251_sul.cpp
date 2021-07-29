#include <iostream>
#include <float.h>

using namespace std;

double dist[1000];
double cost[1000][1000];
int connected[1000];
int N;

void initialize(void)
{
    for(int i = 0; i < 1000; i++) {
        dist[i] = DBL_MAX;
        connected[i] = 0;
    }
}

bool is_all_conn() 
{
    for(int i = 0; i < N; i++) {
        if(connected[i] == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, i, j;
    double E;
	freopen("input copy.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        int X[1000];
        int Y[1000];
        int process_point, closest;
        double min_dist, result = 0.0;
        initialize();
        for(i = 0; i < N; i++) {
            cin>>X[i];
        }
        for(i = 0; i < N; i++) {
            cin>>Y[i];
        }
        cin>>E;
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                cost[i][j] = E * (double)((double)(X[i] - X[j]) * (double)(X[i] - X[j]) + (double)(Y[i] - Y[j]) * (double)(Y[i] - Y[j]));
            }
        }

        process_point = 0;
        connected[0] = 1;
        dist[0] = 0.0;
        closest = -1;
        while(!is_all_conn()) {
            min_dist = DBL_MAX;
            for(i = 0; i < N; i++) {
                if(connected[i] == 0) {
                    if(cost[process_point][i] < dist[i]) {
                        dist[i] = cost[process_point][i];
                    }
                }
            }
            for(i = 0; i < N; i++) {
                if(connected[i] == 0) {
                    if(min_dist > dist[i]) {
                        min_dist = dist[i];
                        closest = i;
                    }
                }
            }
            connected[closest] = 1;
            process_point = closest;
        }

        for(i = 0; i < N; i++) {
            result += dist[i];
        }
        printf("#%d %.0f\n", test_case, result);
	}
	
    return 0;
}