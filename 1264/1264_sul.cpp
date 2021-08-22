#include <iostream>
#include <string>

using namespace std;

int lcs[501][501];

void LCS(string &x, string &y, int x_n, int y_n)
{
    for(int i = 0; i < x_n; i++) {
        lcs[i][0] = 0;
    }
    for(int i = 0; i < y_n; i++) {
        lcs[0][i] = 0;
    }

    for(int i = 1; i <= x_n; i++) {
        for(int j = 1; j <= y_n; j++) {
            if(x[i-1] == y[j-1]) {
                lcs[i][j] = lcs[i-1][j-1]+1;
            } else if (lcs[i-1][j] > lcs[i][j-1]) {
                lcs[i][j] = lcs[i-1][j];
            } else {
                lcs[i][j] = lcs[i][j-1];
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N;

	freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        string x, y;
        cin>>N;
        cin>>x;
        cin>>y;
        LCS(x, y, N, N);
        printf("#%d %.2f\n", test_case, (double)lcs[N][N] * 100.0/(double)N);
	}
	return 0;
}