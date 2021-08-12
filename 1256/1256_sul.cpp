#include <iostream>
#include <string>
#include <cstring>

using namespace std;
void order_strings(string *part_word, int len)
{
    int i, j;
    string temp;
    // printf("before <log>\n");
    // for(i = 0; i < len; i++) {
    //     printf("%s\n", part_word[i].c_str());
    // }

    for(i = len -1; i > 0; i--) {
        for( j = 0; j < i; j++) {
            if (strcmp(part_word[j].c_str(), part_word[j+1].c_str()) > 0) {
                temp = part_word[j];
                part_word[j] = part_word[j+1];
                part_word[j+1] = temp;
            }
        }
    }

    // printf("<log>\n");
    // for(i = 0; i < len; i++) {
    //     printf("%s\n", part_word[i].c_str());
    // }
}

int main(int argc, char** argv)
{
	int test_case;
	int T, K;
    string part_word[400];

	freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string word;
        int pos, i, j, length;

        cin>>K;
        cin>>word;
        length = word.length();
        for(pos = 0; pos < length; pos++) {
            part_word[pos] = word.substr(pos, length-pos);
        }
        order_strings(part_word, length);
        printf("#%d %s\n", test_case, part_word[K-1].c_str());
	}
	return 0;
}