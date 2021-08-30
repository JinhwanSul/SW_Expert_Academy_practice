#include<iostream>

using namespace std;

struct point {
    int i;
    int j;
};

struct point bots[5000];
int shot[10000];
int B[20001];

void quick_sort(int start, int end)
{
    if(start >= end) {
        return;
    }

    int pivot = shot[end];
    int smaller = start-1;
    int temp;
    for(int j = start; j < end; j++) {
        if(shot[j] <= pivot) {
            smaller++;
            temp = shot[smaller];
            shot[smaller] = shot[j];
            shot[j] = temp;
        }
    }
    temp = shot[smaller+1];
    shot[smaller+1] = shot[end];
    shot[end] = temp;
    quick_sort(start, smaller);
    quick_sort(smaller+2, end);
}

int gcd(int p, int q)
{
    if (p < q) {
        return gcd(q, p);
    } else if (q == 0) {
        return p;
    } else {
        return gcd(q, p%q);
    }
}

int abs(int x)
{
    return x>=0 ? x : -1 * x;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int R, N, K, tmp1, tmp2, big_j, small_j, big_i, small_i, cnt_shot, total_shot, sum_c;
        cin>>R>>N>>K;
        for(int i = 0; i < N; i++) {
            cin>>tmp1>>tmp2;
            struct point p;
            p.i = tmp1;
            p.j = tmp2;
            bots[i] = p;
        }

        total_shot = 0;
        for(int i = 0; i < N; i++) {
            cnt_shot = 0;
            big_i=0; big_j=0; small_i=0; small_j=0;
            for(int j = 0; j < N; j++) {
                if(i == j) { // same bot
                    continue;
                } else if (bots[i].i == bots[j].i) { // two bots are in same horizontal line
                    if (bots[i].j < bots[j].j) {
                        big_j++;
                    } else {
                        small_j++;
                    }
                } else if (bots[i].j == bots[j].j) { // two bots are in same vertical line
                    if (bots[i].i < bots[j].i) {
                        big_i++;
                    } else {
                        small_i++;
                    }
                } else { // cross line
                    if(gcd(abs(bots[i].i-bots[j].i), abs(bots[i].j-bots[j].j)) == 1) {
                        cnt_shot++;
                    } else {
                    }
                }
            }
            if(big_i != 0) cnt_shot++;
            if(big_j != 0) cnt_shot++;
            if(small_i != 0) cnt_shot++;
            if(small_j != 0) cnt_shot++;
            shot[i] = cnt_shot;
            total_shot += cnt_shot;
        }

        sum_c = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                shot[j] = (shot[j] * K + j + 1) % N + 1;
                shot[N+j] = ((shot[j] * (j + 1) + K) % N) + 1;
            }
            quick_sort(0, 2*N-1);
            B[0] = 1;
            for(int j = 1; j < 2*N+1; j++) {
                B[j] = (B[j-1]*shot[j-1] + j) % N + 1;
            }
            sum_c += B[2*N];
        }

        printf("#%d %d %d\n", test_case, total_shot, sum_c);
	}
	return 0;
}