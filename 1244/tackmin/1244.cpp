#include <iostream>
#include <string>

using namespace std;

int possible_numbers[1000000][11];

void Search(string N, int M);

int main(){
    int TC, M;
    string N;
    int i, j;
    int max_num;

    /* initialize array */
    
    cin >> TC;
    for(i=0; i<TC; i++){
        for(j=0; j<1000000; j++){
            possible_numbers[j][0] = 0;
        }
        cin >> N >> M;
        Search(N, M);
        max_num = atoi(N.c_str());
        for(j=999999; j>=0; j--){
            if(possible_numbers[j][0] == 1){
                max_num = j;
                break;
            }
        }
        cout << "#" << i+1 << " " << max_num << endl;
    }
}

void Search(string N, int M){
    
    if(M <= 0){
        //cout << "number is " << N << endl;
        possible_numbers[atoi(N.c_str())][0] = 1;
        return;
    }

    if(possible_numbers[atoi(N.c_str())][M] == 1){
        return;
    }

    possible_numbers[atoi(N.c_str())][M] = 1;

    int i, j;
    char temp;
    
    for(i=0; i<N.size(); i++){
        for(j=0; j<N.size(); j++){
            if(i != j){
                temp = N[j];
                N[j] = N[i];
                N[i] = temp;
                //cout << "number is " << N << ", " << M-1 << "times left" << endl;
                Search(N,M-1);
                temp = N[j];
                N[j] = N[i];
                N[i] = temp;
            }
        }
    }
}