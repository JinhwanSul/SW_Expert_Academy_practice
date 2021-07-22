#include <iostream>

using namespace std;

int node[10001][3]; // 0 is parent, 1 is child1, 2 is child2

int subtree_size(int _node);

int main(){
    int TC, V, E;
    int i, j;    
    int node1, node2;
    int parent, child;
    int depth1, depth2;
    int parent1[10001]; // parents of node1
    int parent2[10001]; // parents of node2
    int common_parent, subtree;

    cin >> TC;
    for(i=1; i<=TC; i++){
        // initializing
        for(j=0; j<10001; j++){
            node[j][0] = 0;
            node[j][1] = 0;
            node[j][2] = 0;
            parent1[j] = 0;
            parent2[j] = 0;
        }
        depth1 = 0;
        depth2 = 0;

        // input
        cin >> V >> E >> node1 >> node2;

        for(j=0; j<E; j++){
            cin >> parent >> child;
            node[child][0] = parent;
            if(node[parent][1] == 0){
                node[parent][1] = child;
            }
            else{
                node[parent][2] = child;
            }
        }

        // compute depth
        j = 0;
        while(node[node1][0] != 0){
            node1 = node[node1][0];
            parent1[j++] = node1;
        }
        depth1 = j;
        j = 0;
        while(node[node2][0] != 0){
            node2 = node[node2][0];
            parent2[j++] = node2;
        }
        depth2 = j;

        // compute common parent
        if(depth1 > depth2){
            for(j=0; j<10001; j++){
                if(parent1[j+depth1-depth2] == parent2[j]){
                    common_parent = parent2[j];
                    break;
                } 
            }

        }
        else if(depth1 == depth2){
            for(j=0; j<10001; j++){
                if(parent2[j] == parent1[j]){
                    common_parent = parent1[j];
                    break;
                } 
            }
        }
        else{
            for(j=0; j<10001; j++){
                if(parent2[j+depth2-depth1] == parent1[j]){
                    common_parent = parent1[j];
                    break;
                } 
            }
        }

        // compute subtree size
        subtree = subtree_size(common_parent);

        cout << "#" << i << " " << common_parent << " " << subtree << endl; 
    }
}

int subtree_size(int _node){
    if(node[_node][1] == 0) return 1;
    if(node[_node][1] != 0 && node[_node][2] == 0) return 1 + subtree_size(node[_node][1]);
    if(node[_node][2] != 0) return 1 + subtree_size(node[_node][1]) + subtree_size(node[_node][2]);
}