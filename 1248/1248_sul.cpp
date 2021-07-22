#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

int T, N;
map<int, vector<int> > tree;

int tree_size(int node)
{
    int result;
    switch(tree[node].size()) {
        case 1:
            result = 1;
            break;
        case 2:
            result = tree_size(tree[node][1]) + 1;
            break;
        case 3:
            result = tree_size(tree[node][1]) + tree_size(tree[node][2]) + 1;
            break;
        default:
            printf("Something wrong with tree\n");
            result = -1;
            break;
    }
    return result;
}

int main(int argc, char** argv)
{
    int test_case, V, E, num1, num2, i, parent, child, common, answer;
	stack<int> stk1;
    stack<int> stk2;

    freopen("input.txt", "r", stdin);
    cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>V>>E>>num1>>num2;
        
        // Build tree
        tree.clear();
        for (i = 0; i < E; i++) {
            cin>>parent>>child;
            if(tree[parent].size() == 0) {
                tree[parent].push_back(-1);
                tree[parent].push_back(child);
                // printf("new parent node=%d child=%d\n", parent, child);
            } else {
                tree[parent].push_back(child);
                // printf("alreay parent=%d. child=%d.\n", parent, child);
            }

            if (tree[child].size() == 0) {
                tree[child].push_back(parent);
            } else {
                tree[child][0] = parent;
            }
        }

        // Find common ancestor
        while(!stk1.empty()) stk1.pop();
        while(!stk2.empty()) stk2.pop();

        child = num1;
        stk1.push(child);
        // printf("child %d\n", child);
        while(child != 1) {
            child = tree[child].at(0);
            // printf("child %d\n", child);
            stk1.push(child); 
        }

        child = num2;
        stk2.push(child);
        while(child != 1) {
            child = tree[child][0];
            stk2.push(child); 
        }

        while(stk1.top() == stk2.top()) {
            common = stk1.top();
            stk1.pop(); stk2.pop();
        }

        answer = tree_size(common);
        printf("#%d %d %d\n", test_case, common, answer);
    }
    return 0;
}