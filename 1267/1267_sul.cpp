#include<iostream>

using namespace std;

struct adad
{
    int cnt;
    int *ad_list;
};

struct adad adad_list[1001];
bool visited[1001];
int ts[1001];
int ts_cnt;

void init(void)
{
    for(int i = 0; i < 1001; i++) {
        adad_list[i].ad_list = NULL;
        adad_list[i].cnt = 0;
        visited[i] = false;
        ts[i] = -1;
        ts_cnt = 0;
    }
}

void DFS(int v)
{
    visited[v] = true;
    int count = adad_list[v].cnt;
    int adj;
    if(adad_list[v].ad_list == NULL) {
        ts[ts_cnt++] = v;
        return;
    } else {
        for(int i = 0; i < count; i++) {
            adj = adad_list[v].ad_list[i];
            if(visited[adj] == false) {
                DFS(adj);
            }
        }
        ts[ts_cnt++] = v;
    }
}

void print_rev_ts(void)
{
    for (int i = ts_cnt-1; i >= 0; i--) {
        printf(" %d",ts[i]); 
    }
    printf("\n");
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);

	// cin>>T;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int V, E, st, des, temp;
        cin>>V>>E;
        init();
        for (int i = 0; i < E; i++) {
            cin>>st>>des;
            if (adad_list[st].ad_list == NULL) {
                adad_list[st].ad_list = new int[1000];
                adad_list[st].ad_list[0] = des;
                adad_list[st].cnt++;
            } else {
                temp = adad_list[st].cnt;
                adad_list[st].ad_list[temp] = des;
                adad_list[st].cnt++;
            }
        }

        for(int i = 1; i <= V; i++) {
            if (visited[i] == false) {
                DFS(i);
            }
        }

        printf("#%d", test_case);
        print_rev_ts();

        for(int i = 0; i <= V; i++) {
            if(adad_list[i].ad_list != NULL) {
                delete[] adad_list[i].ad_list;
            }
        }
	}
	return 0;
}