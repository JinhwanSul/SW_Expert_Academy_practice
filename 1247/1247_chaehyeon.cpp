#include<iostream>
using namespace std;
class Point
{
public:
    int x;
    int y;
    static int getDistance(Point i, Point j){
        int dx = i.x - j.x;
        int dy = i.y - j.y;
        if(dx<0) dx *= -1;
        if(dy<0) dy *= -1;
        return dx+dy;
    }
};

int getTotalDistance(Point, int);
Point origin;
Point destination;
Point* houses;
bool* check;
int number=0;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>number;
        houses = (Point*)malloc(sizeof(Point)*number);
        check = (bool *)malloc(sizeof(bool)*number);
        cin>>origin.x>>origin.y;
        cin>>destination.x>>destination.y;
        for(int i=0;i<number;i++){
            Point point;
            cin>>point.x>>point.y;
            houses[i]=point;
            check[i]= true;
        }
        int minDistance = getTotalDistance(origin, number);
        printf("#%d %d\n",test_case,minDistance);

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int getTotalDistance(Point start, int count){
    if(count==0) return Point::getDistance(start,destination);
    else{
        int finalDistance=1e7;
        for(int i =0; i<number;i++){
            if(check[i]){
                check[i]=false;
                int distance= Point::getDistance(start,houses[i]);
                distance += getTotalDistance(houses[i], count-1);
                if(distance<finalDistance){
                    finalDistance=distance;
                }
                check[i]=true;
            }
        }
        return finalDistance;
    }
}