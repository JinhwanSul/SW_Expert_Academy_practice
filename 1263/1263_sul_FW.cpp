#include<iostream>

using namespace std;

int conn[1000][1000];
int short_path[1000][1000];

int main(int argc, char** argv)
{
	int test_case;
	int T, N, sum, temp;
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

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == j) {
                    short_path[i][j] = 0;
                } else if (conn[i][j] == 1) {
                    short_path[i][j] = 1;
                } else {
                    short_path[i][j] = 99999;
                }
            }
        }

        for (int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    temp = short_path[i][k] + short_path[k][j];
                    if(short_path[i][j] > temp) {
                        short_path[i][j] = temp;
                    }
                }
            }
        }

        int min_cc = INT32_MAX;
        sum = 0; 
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                sum += short_path[i][j];
            }
            if(sum < min_cc) {
                min_cc = sum;
            }
            sum = 0;
        }

        printf("#%d %d\n",test_case, min_cc);
	}
	return 0;
}