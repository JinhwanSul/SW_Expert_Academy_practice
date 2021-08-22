#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, P;
        cin>>N;
        cin>>P;
        int base = N/P;
        int remain = N%P;
        long result = 1;
        for(int i = 0; i < remain; i++) {
            result *= (base+1);
        }
        for(int j = 0; j < (P-remain); j++) {
            result *= base;
        }
        printf("#%d %ld\n", test_case, result);
	}
	return 0;
}