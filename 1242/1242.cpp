#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

// Using String Match, Rabin-Karp Algorithm

int decrypt(int *one_number)
{
    int i, value = 0;
    for (i = 0; i < 7; i++) {
        // printf("%d ", one_number[i]);
        value = value + one_number[i] * (1<<(6-i));
    }
    // printf("\nvalue %d\n", value);
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

int min3(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    if(c <= a && c <= b) return c;
    return -1;
}

// Check last (1, 0, 1) pattern to find out code thickness 
int find_ratio(int **input_bi, int n, int m) {
    int i = m;
    int cnt_front1 = 0, cnt0 = 0, cnt_rear1 = 0;
    while(input_bi[n][i] == 1) {
        cnt_rear1++;
        i--;
    }
    while(input_bi[n][i] == 0) {
        cnt0++;
        i--;
    }
    while(input_bi[n][i] == 1) {
        cnt_front1++;
        i--;
    }
    return min3(cnt_rear1, cnt0, cnt_front1);
}


void change2binary(int **input2, int n, int m, char num)
{
    int k = 4*m;
    if(num != '0'){
        // printf("not 0 and %c (%d, %d) goes to %d~%d\n",num,  n, m, k, k+3);
    }
    // // printf("%d %c\n", num, num);
    switch (num) {
        case '0':
            input2[n][k] = 0; input2[n][k+1] = 0; input2[n][k+2] = 0; input2[n][k+3] = 0;
            break;
        case '1':
            input2[n][k] = 0; input2[n][k+1] = 0; input2[n][k+2] = 0; input2[n][k+3] = 1;
            break;
        case '2':
            input2[n][k] = 0; input2[n][k+1] = 0; input2[n][k+2] = 1; input2[n][k+3] = 0;
            break;
        case '3':
            input2[n][k] = 0; input2[n][k+1] = 0; input2[n][k+2] = 1; input2[n][k+3] = 1;
            break;
        case '4':
            input2[n][k] = 0; input2[n][k+1] = 1; input2[n][k+2] = 0; input2[n][k+3] = 0;
            break;
        case '5':
            input2[n][k] = 0; input2[n][k+1] = 1; input2[n][k+2] = 0; input2[n][k+3] = 1;
            break;
        case '6':
            input2[n][k] = 0; input2[n][k+1] = 1; input2[n][k+2] = 1; input2[n][k+3] = 0;
            break;
        case '7':
            input2[n][k] = 0; input2[n][k+1] = 1; input2[n][k+2] = 1; input2[n][k+3] = 1;
            break;
        case '8':
            input2[n][k] = 1; input2[n][k+1] = 0; input2[n][k+2] = 0; input2[n][k+3] = 0;
            break;
        case '9':
            input2[n][k] = 1; input2[n][k+1] = 0; input2[n][k+2] = 0; input2[n][k+3] = 1;
            break;
        case 'A':
            input2[n][k] = 1; input2[n][k+1] = 0; input2[n][k+2] = 1; input2[n][k+3] = 0;
            break;
        case 'B':
            input2[n][k] = 1; input2[n][k+1] = 0; input2[n][k+2] = 1; input2[n][k+3] = 1;
            break;
        case 'C':
            input2[n][k] = 1; input2[n][k+1] = 1; input2[n][k+2] = 0; input2[n][k+3] = 0;
            break;
        case 'D':
            input2[n][k] = 1; input2[n][k+1] = 1; input2[n][k+2] = 0; input2[n][k+3] = 1;
            break;
        case 'E':
            input2[n][k] = 1; input2[n][k+1] = 1; input2[n][k+2] = 1; input2[n][k+3] = 0;
            break;
        case 'F':
            input2[n][k] = 1; input2[n][k+1] = 1; input2[n][k+2] = 1; input2[n][k+3] = 1;
            break;
    }
}

int is_new_block(vector<vector<int> > &code_blocks, int n, int m)
{
    vector<vector<int> >::iterator iter;
    for (iter = code_blocks.begin(); iter != code_blocks.end(); iter++) {
        // printf("(%d, %d) (%d, %d)\n", (*iter)[0], (*iter)[1],(*iter)[2],(*iter)[3]);
        if((*iter)[0] <= n && n <= (*iter)[2] && (*iter)[3] <= m && (*iter)[1]) {
            return 0; // (n,m) in same block
        }
    }
    return 1; // new block same block
}

void add_new_block(vector<vector<int> > &code_blocks, int n, int m, int ratio, int** input_bi)
{
    int i = n;
    vector<int> new_block;
    while(input_bi[i][m] != 0) {
        i++;
    }
    new_block.push_back(n);
    new_block.push_back(m);
    new_block.push_back(i-1);
    new_block.push_back(m-56*ratio+1);
    printf("new block! ratio=%d, (%d, %d) (%d, %d)\n",ratio,n,m,i-1,m-56*ratio+1);
    code_blocks.push_back(new_block);
}

int get_code(int **input_bi, int ratio, int n, int m)
{
    // printf("argument? n = %d m = %d\n", n, m);
    int i, j, num_cnt = 0, read = m, k;
    int one_number[7];
    int *data = (int *) malloc(sizeof(int) * 8);
    for(j = 7; j >= 0; j--) {
        for (i = read; i > (read - 7 * ratio); i = i - ratio) {
            one_number[6-num_cnt] = input_bi[n][i];
            num_cnt++;
        }

        // printf("one number!\n");
        // for(k = 0; k < 7; k++) {
            // printf("%d", one_number[k]);
        // }
        // printf("\n");

        data[j] = decrypt(one_number);
        // printf("data[j] = %d\n", data[j]);
        read = i;
        num_cnt = 0;
    }
    // if (is_dup(data, code_cnt, codes)) {
    //     return -1;
    // } else {
    return validation(data);
    // }
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M, i, j, ratio, code_cnt = 0, valid = 0, result = 0;
    char num_ch;
    int candidate[8];
    unsigned int value, value_backup;
    vector<vector<int> > code_block;
    int matched;
	freopen("sample_input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N>>M;
        result = 0;
        code_block.clear();
        int **input_bi = (int **) malloc(N * sizeof(int *));
        for (i = 0; i < N; i++) {
            input_bi[i] = (int *) calloc(4* M, sizeof(int));
        }
        for (i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                cin>>num_ch;
                change2binary(input_bi, i, j, num_ch);
            }
        }

        FILE *fd = fopen("input_bi.txt", "w");
        for(i = 0; i < N; i++) {
            for(j = 0; j < 4*M; j++){
                fputc(input_bi[i][j]+'0', fd);
            }
            fputc('\n', fd);
        }
        fclose(fd);

        for(i = 0; i < N; i++) {
            for(j = 4*M-1; j >= 0; j--) {
                if(input_bi[i][j] == 1 && is_new_block(code_block, i, j)) { // Encrypted code detected
                    code_cnt++;
                    ratio = find_ratio(input_bi, i, j);
                    // printf("ratio = %d\n", ratio);
                    add_new_block(code_block, i, j, ratio, input_bi);
                    valid = get_code(input_bi, ratio, i, j);
                    printf("code_cnt= %d, valid = %d\n",code_cnt, valid);
                    if (valid > 0) {
                        result += valid;
                    }
                }
            }
        }
        printf("#%d %d\n", test_case, result);
	}
	return 0;
}