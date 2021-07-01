#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, i, score, max_freq, max_score, test_case_number;
    int freq[101] = {0,};

	freopen("1204input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        max_freq = 0;
        max_score = -1;
        for(i = 0; i < 101; i++) {
            freq[i] = 0;
        }
        cin >> test_case_number;
        for(i = 0; i < 1000; i++) {
            cin>>score;
            freq[score]++;
            if (score == max_score) {
                max_freq++;
            }

            if (freq[score] > max_freq || (freq[score] == max_freq && score > max_score)) {
                max_score = score;
                max_freq = freq[score];
            }
        }

        printf("#%d %d\n", test_case, max_score);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}