#include <iostream>
#include <stdlib.h>

using namespace std;

// Using String Match, Rabin-Karp Algorithm

int compare_value(int value)
{
    switch (value) {
        case 13:
            return 0;
        case 25:
            return 1;
        case 19:
            return 2;
        case 61:
            return 3;
        case 35:
            return 4;
        case 49:
            return 5;
        case 47:
            return 6;
        case 59:
            return 7;
        case 55:
            return 8;
        case 11:
            return 9;
        default:
            return -1;
    }
}

int validation(int *candidate)
{
    int i, sum = 0;
    if (((candidate[0] + candidate[2] + candidate[4] + candidate[6]) * 3 
        + candidate[1] + candidate[3] + candidate[5] + candidate[7]) % 10 == 0) {
            for(i = 0; i < 8; i++) {
                sum += candidate[i];
            }
            return sum;
        } 
    else {
        return 0;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M, i, num, value_cnt, check_point, k, cand_idx, result = 0;
    char num_ch;
    int input[5000];
    int candidate[8];
    unsigned int value, value_backup;
    int matched;
	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N>>M;
        value_cnt = 0;
        value = 0;
        cand_idx = 0;
        check_point = 0;
        // Get all the input
        for(i = 0; i < M * N; i++) {
            cin>>num_ch;
            input[i] = atoi(&num_ch);
        }
        // Handle first 7 numbers
        for(i = 0; i < 7; i++) {
            if (value >= 64) {
                value = ((value-64)<<1) + input[i];
            } else {
                value = (value<<1) + input[i];
            }
            value_cnt++;
        }
        matched = compare_value(value);
        if (matched >= 0) {
            check_point = i;
            value_backup = value;
            value_cnt = 0;
            value = 0;
            candidate[cand_idx] = matched;
            cand_idx++;
        } else {
            value_cnt--;
        }
        // Handle rest of inputs
        for (i = 7; i< M * N; i++) {
            if (value >= 64) {
                value = ((value-64)<<1) + input[i];
            } else {
                value = (value<<1) + input[i];
            }

            if (value_cnt < 7) {
                value_cnt++;
            }
            // Case 1: Matched pattern exists and 7 new inputs are accumulated
            if (check_point != 0 && value_cnt == 7) {
                matched = compare_value(value);
                if (matched >= 0) { 
                    check_point = i;
                    value_cnt = 0;
                    value_backup = value;
                    candidate[cand_idx] = matched;
                    cand_idx++;
                } else {
                    i = check_point;
                    check_point = 0;
                    cand_idx = 0;
                    check_point = 0;
                    value = value_backup;
                    value_cnt = 7;
                    continue;
                }
                if (cand_idx == 8) {
                    result = validation(candidate);
                    break;
                }
            }
            // Case 2: No pattern has matched yet, value is full with inputs
            if(check_point == 0 && value_cnt == 7) {
                matched = compare_value(value);
                if (matched >= 0) {
                    check_point = i;
                    value_backup = value;
                    value_cnt = 0;
                    value = 0;
                    candidate[cand_idx] = matched;
                    cand_idx++;
                }
            }
        }
        printf("#%d %d\n", test_case, result);
	}
	return 0;
}