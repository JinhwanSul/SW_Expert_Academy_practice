#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print_digit(int *digit, int n_digits)
{
    int i;
    for(i = n_digits-1; i >= 0; i--) {
        printf("%d", digit[i]);
    }
    printf("\n");
}

int change(int num, int s1, int s2)
{
    int tens[6] = {1, 10, 100, 1000, 10000, 100000};
    int a = (num % tens[s1+1]) / tens[s1];
    int b = (num % tens[s2+1]) / tens[s2];
    int result = num - a * tens[s1] + b * tens[s1] - b *tens[s2] + a * tens[s2];
    // printf("change %d to %d s1=%d s2=%d\n",num, result, s1, s2);
    return result;
}

int backtrack(int num, int sw, int len)
{
    vector<set<int> > state_space;
    set<int> init;
    set<int>::iterator iter;
    init.insert(num);
    // printf("%d\n", num);
    state_space.push_back(init);
    int s, i, j, changed, source, max = -1;
    for(s = 0; s <= sw; s++) {
        set<int> next_swap;
        for(iter = state_space[s].begin(); iter != state_space[s].end(); iter++) {
            // printf("level %d, num = %d\n", s, *iter);
            for(i = 0; i < len-1; i++){
                for(j = i; j < len; j++) {
                    changed = change(*iter, i, j);
                    next_swap.insert(changed);
                }
            }
        }
        state_space.push_back(next_swap);
    }

    for(iter = state_space[sw].begin(); iter != state_space[sw].end(); iter++) {
        if( *iter > max) {
            max = *iter;
        }
    }
    return max;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input-2 copy.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int *digit = new int[6];
        int i, num, dup_num, sw, undetermined, n_digits = 0, max_dig, max_loc, swap_cnt, temp, result;
        int same_number_check[10] = {0,};
        bool is_sorted = true, is_same_number = false;
        cin >> num >> sw;
        dup_num = num;
        while(num != 0) {
            digit[n_digits] = num % 10;
            same_number_check[num%10]++;
            if(same_number_check[num%10] > 1) {
                is_same_number = true;
            }
            num = num/10;
            n_digits++;
        }

        if(is_same_number) {
            result = backtrack(dup_num, sw, n_digits);
            printf("#%d %d\n", test_case, result);
            delete[] digit;
            continue;
        }

        undetermined = n_digits;
        swap_cnt = 0;
        while(swap_cnt < sw) {
            // Find max
            max_dig = -1;
            max_loc = -1;
            for(i = 0; i < undetermined-1; i++) {
                if(digit[i] > max_dig) {
                    max_dig = digit[i];
                    max_loc = i;
                }
            }
            // Check swap or not
            if(digit[undetermined-1] < max_dig) {
                digit[max_loc] = digit[undetermined-1];
                digit[undetermined-1] = max_dig;
                undetermined--;
                swap_cnt++;
            } else {
                // check if sorted
                if(undetermined == 1) {
                    is_sorted = true;
                }
                for(i = 1; i < undetermined; i++) {
                    is_sorted = is_sorted && (digit[i] >= digit[i-1]);
                }
                // if sorted: check if(rest_cnt %2 == 0 -> end) else (swap(digit[0], sigit[1]) ))
                if(is_sorted) {
                    if((sw - swap_cnt) % 2 == 0 || is_same_number) {
                        printf("#%d ", test_case);
                        print_digit(digit, n_digits);
                        break;
                    } else {
                        temp = digit[0];
                        digit[0] = digit[1];
                        digit[1] = temp;
                        printf("#%d ", test_case);
                        print_digit(digit, n_digits);
                        break;
                    }
                } else {
                    undetermined--;
                }
            }
        }
        if(swap_cnt == sw) {
            printf("#%d ", test_case);
            print_digit(digit, n_digits);
        }
	    delete[] digit;
	}
    return 0;
}