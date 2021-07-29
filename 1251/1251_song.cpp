#include<iostream>
#include <vector>
using namespace std;
struct Point{
    int x=0;
    int y=0;
    double distance=0;
};
int n;
Point *map;
bool *check;

int findMinPoint();
double getDistance(int, int);
void changeDistance(int);
int main(int argc, char** argv)
{
    int test_case;
    int T;
//    freopen("input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        double cost=0;
        double e;
        cin>>n;
        check = (bool*)malloc(sizeof(bool)*n);
        map = (Point*)malloc(sizeof(Point)*n);
        for(int i=0;i<n;i++){
            check[i]=true;
            cin>>map[i].x;
        }
        for(int i=0;i<n;i++){
            cin>>map[i].y;
        }
        cin>>e;
        for(int i=1;i<n;i++){
            map[i].distance= getDistance(i,0);
        }
        for(int i=1;i<n;i++){
            int pointID = findMinPoint();
            cost+=map[pointID].distance;
            check[pointID]= false;
            changeDistance(pointID);
//            printf("finish: %d\n",i);
        }
        printf("#%d %.0f\n",test_case,cost*e);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int findMinPoint(){
    double min=1e13;
    int target;
    for(int i =1; i<n;i++){
        if(check[i]&&map[i].distance<min){
            target=i;
            min=map[i].distance;
        }
    }
    return target;
}
double getDistance(int i, int j){
    double dx= map[i].x-map[j].x;
    double dy = map[i].y-map[j].y;
    double distance = dx*dx+dy*dy;
    return distance;
}
void changeDistance(int id){
    for(int i =1; i<n;i++){
        if(check[i]){
            double newDistance = getDistance(id, i);
            if(map[i].distance>newDistance) map[i].distance=newDistance;
        }
    }
}
