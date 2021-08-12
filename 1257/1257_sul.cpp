#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string part_word[26][80000];

int main(int argc, char** argv)
{
	int test_case;
	int T, K;

	freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string word, sub;
        int pos, i, j, length, sub_len, check_point, cnt = 0, dup, ret, accum, alp, insert;
        int alp_cnt[26] = {0, };

        cin>>K;
        cin>>word;
        length = word.length();
        check_point = 0;
        cnt = 0;
        sub_len = 1;
        char alphabet;

        for(pos = 0; pos < length; pos++) {
            sub = word.substr(pos, sub_len);
            alphabet = sub[0];
            check_point = alphabet - 'a';
            if(alp_cnt[check_point] != 0) {
                alp_cnt[check_point] = 1;
            } else {
                alp_cnt[check_point] = 1;
                part_word[check_point][0] = sub;
            }
        }
        for(sub_len = 2; sub_len <= length; sub_len++) {
            for(pos = 0; pos <= length - sub_len; pos++) {
                sub = word.substr(pos, sub_len);
                alphabet = sub[0];
                check_point = alphabet - 'a';

                dup = 0;
                insert = 0;
                for(i = 0; i < alp_cnt[check_point]; i++) {
                    ret = strcmp(sub.c_str(), part_word[check_point][i].c_str());
                    if (ret == 0) { // duplicated string
                        dup = 1;
                        insert = 1;
                        break;
                    } else if (ret > 0) { // sub is larger
                    } else { // part_word is larger
                        for(j = alp_cnt[check_point]-1; j >= i; j--) {
                            part_word[check_point][j+1] = part_word[check_point][j];
                        }
                        part_word[check_point][i] = sub;
                        alp_cnt[check_point]++;
                        insert = 1;
                        break;
                    }
                }
                if (insert == 0) { // sub is largest
                    part_word[check_point][i] = sub;
                    alp_cnt[check_point]++;
                    insert = 1;
                }
            }
        }
        alp = 0;
        accum = 0;
        while(K > accum || alp >= 26) {
            if(alp_cnt[alp] != 0) {
            }
            accum += alp_cnt[alp];
            alp++;
        }

        if (alp >= 26) {
            printf("#%d none\n", test_case);
        } else {
            int loc = K - (accum - alp_cnt[alp-1]);
            printf("#%d %s\n", test_case, part_word[alp-1][loc-1].c_str());
        }
	}
	return 0;
}