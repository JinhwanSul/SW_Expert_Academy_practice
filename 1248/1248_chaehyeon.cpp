#include<iostream>

using namespace std;
class Vertex{
public:
    int item;
    int numberOfChild;
    Vertex* parent;
    Vertex(){
        item=-1000;
        numberOfChild=0;
        parent=NULL;

    }
    static void makeEdge(Vertex* parent, Vertex* child){
        child->parent=parent;
        Vertex *curr = parent;
        while (curr!=NULL){
            curr->numberOfChild+=child->numberOfChild+1;
            curr=curr->parent;
        }
    }
};
int totalVertex=-1;
int currVertexNumber;
int totalEdge=-1;
int first;
int second;
Vertex **root;
Vertex* findVertex(int);
int main(int argc, char** argv)
{
    int test_case;
    int T;
    freopen("input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        currVertexNumber=0;
        int parentNumber, childNumber;
        cin>>totalVertex>>totalEdge>>first>>second;
        root = (Vertex**)malloc(sizeof(Vertex*)*totalVertex);
        for(int i =0;i<totalVertex;i++){
            root[i]= new Vertex();
        }
        for(int i=0;i<totalEdge;i++){
            scanf("%d %d",&parentNumber,&childNumber);
            Vertex::makeEdge(findVertex(parentNumber),findVertex(childNumber));
        }
        Vertex* curr1 = findVertex(first);
        Vertex* curr2 = findVertex(second);
        while (curr1!=NULL){
            Vertex *temp=curr2;
            while (temp!=NULL){
                if(curr1->item==temp->item) break;
                temp=temp->parent;
            }
            if(temp!=NULL){
                printf("#%d %d %d\n",test_case,temp->item,temp->numberOfChild+1);
                break;
            }
            curr1=curr1->parent;
        }
        for(int i =0;i<totalVertex;i++){
            delete root[i];
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
Vertex* findVertex(int item){
    for(int i =0;i<currVertexNumber;i++){
        if(root[i]->item == item) return root[i];
    }
    root[currVertexNumber]->item=item;
    currVertexNumber++;
    return root[currVertexNumber-1];
}
