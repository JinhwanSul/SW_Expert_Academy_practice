#include <iostream>

using namespace std;

int main(){
    int TC, n;
    int i, j, k, check;
    int left, right;
    int a[20][2];   // screw head thickness
    cin >> TC;
    for(i=1; i<=TC; i++){
        cin >> n;
        for(j=0; j<n; j++){
            cin >> a[j][0] >> a[j][1];
        }
        for(j=0; j<n; j++){
            check = 0;
            for(k=0; k<n; k++){
                if(a[j][0] == a[k][1]){
                    check = 1;
                    break;
                }
            }
            if(check)   continue;
            else    break;
        }
        left = a[j][0];
        right = a[j][1];
        printf("#%d %d %d ",i,left,right);
        for(j=0; j<n-1; j++){
            for(k=0; k<n; k++){
                if(right == a[k][0]){
                    left = a[k][0];
                    right = a[k][1];
                    break;
                }
            }
            printf("%d %d ",left,right);
        }
        printf("\n");
    }
    return 0;
}