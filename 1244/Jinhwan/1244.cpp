#include<iostream>

using namespace std;

void print_digit(int *digit, int n_digits)
{
    int i;
    for(i = n_digits-1; i >= 0; i--) {
        printf("%d", digit[i]);
    }
    printf("\n");
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input-2.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int *digit = new int[6];
        int i, num, sw, undetermined, n_digits = 0, max_dig, max_loc, swap_cnt, temp;
        int same_number_check[10] = {0,};
        bool is_sorted = true, is_same_number = false;
        cin >> num >> sw;
        // printf("input %d %d\n", num, sw);
        while(num != 0) {
            digit[n_digits] = num % 10;
            same_number_check[num%10]++;
            if(same_number_check[num%10] > 1) {
                is_same_number = true;
            }
            num = num/10;
            n_digits++;
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
            // printf("max digit[%d]~digit[0] is digit[%d] = %d\n", undetermined-2, max_loc, max_dig);
            // Check swap or not
            if(digit[undetermined-1] < max_dig) {
                digit[max_loc] = digit[undetermined-1];
                digit[undetermined-1] = max_dig;
                undetermined--;
                swap_cnt++;
                // printf("swap1 undetermined = %d, swap_cnt = %d\n", undetermined, swap_cnt);
            } else {
                // check if sorted
                if(undetermined == 1) {
                    is_sorted = true;
                }
                for(i = 1; i < undetermined; i++) {
                    is_sorted = is_sorted && (digit[i] >= digit[i-1]);
                }
                // yes sorted: check if(rest_cnt %2 == 0 -> 끝) else (swap(digit[0], sigit[1]) ))
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