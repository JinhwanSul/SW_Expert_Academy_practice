#include<iostream>
#include<set>
using namespace std;
class Point{
public:
    int x;
    int y;
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
    bool operator<(const Point &point)const{
        if(this->x==point.x) return this->y<point.y;
        else return this->x<point.x;
    }
};
int n;
int r;
int k;
Point* robots;
int *A;
int *B;
int getNumber(int);
Point minimalize(int, int);
int getGCD(int,int);
void quickSort(int*A, int start, int end){
    if(end-start<1) return;
    else{
        int bound=start; // larger start
        int last=A[end];
        for(int i=start;i<end;i++){
            if(A[i]<last){
                int temp=A[bound];
                A[bound]=A[i];
                A[i]=temp;
                bound++;
            }
        }
        A[end]=A[bound];
        A[bound]=last;
        quickSort(A, start,bound-1);
        quickSort(A,bound+1,end);
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>r>>n>>k;
        robots=(Point*)malloc(sizeof(Point)*n);
        A=(int*)malloc(sizeof(int)*2*n);
        B=(int*)malloc(sizeof(int)*2*n);
        int answer1=0;
        int answer2=0;
        for(int i=0;i<n;i++){
            int x;
            int y;
            cin>>x>>y;
            robots[i]=Point(x,y);
        }
        for(int i=0;i<n;i++){
            A[i]=getNumber(i);
            answer1+=A[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[j]=(A[j]*k+j+1)%n+1;
                A[n+j]=(A[j]*(j+1)+k)%n+1;
            }
            quickSort(A,0,2*n-1);
            B[0]=(A[0]+1)%n+1;
            for(int i=1;i<2*n;i++){
                B[i]=(B[i-1]*A[i]+i+1)%n+1;
            }
            answer2+=B[2*n-1];
        }
        printf("#%d %d %d\n",test_case,answer1,answer2);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int getNumber(int origin){
    set<Point> points;
    for(int i=0;i<n;i++){
        if(i==origin) continue;
        else{
            Point minPoint = minimalize(origin,i);
            if(points.end()==points.find(minPoint)){
                points.insert(minPoint);
            }
        }
    }
    return points.size();
}
Point minimalize(int origin, int target){
    int x=robots[target].x-robots[origin].x;
    int y =robots[target].y-robots[origin].y;
    int posx = x>0? x:-x;
    int posy = y>0? y:-y;
    int gcd = getGCD(posx,posy);
    x=x/gcd;
    y=y/gcd;
    return Point(x,y);
}
int getGCD(int x, int y){
    if(x<y) return getGCD(y,x);
    else{
        if(y==0) return x;
        else return getGCD(y,x%y);
    }
}