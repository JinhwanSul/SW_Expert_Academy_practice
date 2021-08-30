#include<iostream>

using namespace std;

int comb[19][19] = {0,};

int combin(int a, int b)
{
    if(b == 0) {
        comb[a][0] = 1;
        return 1;
    }
    if(a == b) {
        comb[a][b] = 1;
        return 1;
    } else if(comb[a][b] != 0) {
        return comb[a][b];
    } else {
        int result = combin(a-1, b-1) + combin(a-1, b);
        comb[a][b] = result;
        return result;
    }
}

double prob(int n, int som, int base)
{
    double result = (double) base;
    double p = som/100.0;
    for(int i = 0; i < n; i++) {
        result = result * p;
    }
    for(int i = 0; i < 18-n; i++) {
        result = result * (1-p);
    }
    return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int soma, somb;
        cin>>soma>>somb;
        double proba = prob(2, soma, combin(18,2)) +
                        prob(3, soma, combin(18, 3)) +
                        prob(5, soma, combin(18, 5)) +
                        prob(7, soma, combin(18, 7)) +
                        prob(11, soma, combin(18, 11)) +
                        prob(13, soma, combin(18, 13)) +
                        prob(17, soma, combin(18, 17));
                        
        double probb = prob(2, somb, combin(18,2)) +
                        prob(3, somb, combin(18, 3)) +
                        prob(5, somb, combin(18, 5)) +
                        prob(7, somb, combin(18, 7)) +
                        prob(11, somb, combin(18, 11)) +
                        prob(13, somb, combin(18, 13)) +
                        prob(17, somb, combin(18, 17));
        
        printf("#%d %.6f\n", test_case, 1.0 - (1.0-proba) * (1.0-probb));
	}
	return 0;
}