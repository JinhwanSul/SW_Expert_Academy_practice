#include<iostream>

using namespace std;
int ** board;
int n;
struct Point{
    int x;
    int y;
    int size;
    int compareTo(Point point){
        if(size>point.size) return 1;
        else if(size<point.size) return -1;
        else return x-point.x;
    }
};
Point points[20];
int findPoint();
Point makePoint(int,int);
void doQuickSort(int , int );
int main(int argc, char** argv)
{
    int test_case;
    int T;
    freopen("input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        board=(int**)malloc(sizeof(int*)*n);
        for(int i=0;i<n;i++){
            board[i]=(int*)malloc(sizeof(int)*n);
            for(int j=0;j<n;j++){
                cin>>board[i][j];
            }
        }
        int length=findPoint();
        doQuickSort(0,length-1);
        printf("#%d %d",test_case,length);
        for(int i=0;i<length;i++){
            printf(" %d %d",points[i].x,points[i].y);
        }
        printf("\n");

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int findPoint(){
    int length=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]!=0){
                points[length++] =makePoint(i,j);
            }
        }
    }
    return length;
}
Point makePoint(int i, int j){
    int x=i;
    int y;
    while (x<n && board[x][j]!=0){
        y=j;
        while (y<n && board[x][y]!=0){
            board[x][y]=0;
            y++;
        }
        x++;
    }
    return Point{x-i,y-j, (x-i)*(y-j)};
}
void doQuickSort(int start, int end){
    int biggerStart=start;
    int length=end-start+1;
    if(length<=1) return;
    else{
        Point last=points[end];
        for(int i=start;i<end;i++){
            if(points[i].compareTo(last)<0){
                Point temp = points[biggerStart];
                points[biggerStart]=points[i];
                points[i]=temp;
                biggerStart++;
            }
        }
        points[end]=points[biggerStart];
        points[biggerStart]=last;
        doQuickSort(start,biggerStart-1);
        doQuickSort(biggerStart+1,end);
    }
}