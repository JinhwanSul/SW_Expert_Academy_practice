#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input-2 copy.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, i, finished;
        cin>>N;
        double *loc = new double[N];
        double *mass = new double[N];
        vector<double> answer;
        double error, prev_error, min_loc=9999999.0, max_loc=-99999999.0, step, left_force, right_force, prev_x;
        double epsilon = pow(10.0, -12);
        double x;
        for(i = 0; i < N; i++) {
            cin>>loc[i];
            if(loc[i] < min_loc) {
                min_loc = loc[i];
            }
            if(loc[i] > max_loc) {
                max_loc = loc[i];
            }
        }

        for(i = 0; i < N; i++) {
            cin>>mass[i];
        }

        x = min_loc;
        // printf("init: x = %f, step = %f\n",x, step);
        while(true) {
            step = 0.0001;
            prev_error = 0.0;
            prev_x = 0.0;
            error = 1000.0;
            finished = 0;
            while(true) {
                left_force = 0.0;
                right_force = 0.0;
                for(i = 0; i < N; i++) {
                    if(x < loc[i]) {
                        right_force += mass[i]/pow((loc[i]-x), 2.0);
                    } else {
                        left_force += mass[i]/pow((x-loc[i]), 2.0);
                    }
                }
                error = right_force - left_force;
                if(error > 0) {
                    if(prev_error < 0.0) {
                        step = -step/2.0;
                    }
                    x += step;
                } else {
                    if(prev_error > 0.0) {
                        step = -step/2.0;
                    }
                    x += step;
                }

                if(abs(prev_x - x) < epsilon) {
                    break;
                }

                if(x > max_loc * 5) {
                    finished = 1;
                    break;
                }
                // printf("progress x = %.10f, error = %.10f, step = %.10f, prev_x = %.10f\n", x, error, step, prev_x);
                prev_error = error;
                prev_x = x;
            }

            if (finished) {
                break;
            } else {
                // printf("find! x = %.10f\n", x);
                answer.push_back(x);
                for(i = 0; i < N; i++) {
                    if(loc[i] > x) {
                        x = loc[i]+0.0001;
                        break;
                    }
                }
            }
        }
        vector<double>::iterator iter;
        printf("#%d ", test_case);
        for(iter = answer.begin(); iter != answer.end(); iter++) {
            printf("%.10lf ", *iter);
        }
        printf("\n");
        delete[] loc;
        delete[] mass;
	}
	return 0;
}