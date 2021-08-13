#include<iostream>

using namespace std;

struct screw {
    int m;
    int f;
};

int rear_answer[60], front_answer[60];
int rear_num, front_num;
bool united[30];
struct screw screws[30];

void initiate(void)
{
    rear_num = 0;
    front_num = 0;
    for(int i = 0; i < 60; i++) {
        rear_answer[i] = 0;
        front_answer[i] = 0;
    }
    for(int i = 0; i < 30; i++) {
        united[i] = false;
    }
}

bool connect_new(struct screw* connected, struct screw* new_one)
{
    if (connected->f == new_one->m) {
        rear_answer[rear_num] = new_one->m;
        rear_num++;
        rear_answer[rear_num] = new_one->f;
        rear_num++;
        connected->f = new_one->f;
        return true;
    } else if(connected->m == new_one->f) {
        front_answer[front_num] = new_one->f;
        front_num++;
        front_answer[front_num] = new_one->m;
        front_num++;
        connected->m = new_one->m;
        return true;
    }
    return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, female, male;
    int number_front = 0;

	freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        initiate();
        for(int i = 0; i < N; i++) {
            cin>>male>>female;
            screws[i].m = male;
            screws[i].f = female;
        }

        struct screw conn = screws[0];
        united[0] = 1;       
        for(int i = 1; i < N; i++) {
            for(int j = 1; j < N; j++) {
                if(united[j] == 0 && connect_new(&conn, &(screws[j]))) {
                    united[j] = 1;
                    break;
                }
            }
        }
        
        printf("#%d", test_case);
        for(int j = front_num-1; j >= 0; j--) {
            printf(" %d", front_answer[j]);
        }
        printf(" %d %d", screws[0].m, screws[0].f);
        for(int i = 0; i < rear_num; i++) {
            printf(" %d", rear_answer[i]);
        }
        printf("\n");
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}