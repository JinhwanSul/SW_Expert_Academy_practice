#include <iostream>
#include <string>
using namespace std;

int main(){
    int TC, K;
    int i, j, k, l, iter, len, temp_i, count, remain, start, end;
    string original_word, word, temp_s;
    int order[401];

    cin >> TC;
    for(i=1; i<=TC; i++){
        cin >> K;
        cin >> original_word;

        word = original_word;
        len = word.length();

        count = 0;
        for(j=0; j<len; j++){
            order[j] = j;
        }
        for(j=0; j<len-1; j++){
            for(k=len-2; k>=j; k--){
                if(word.substr(k,1) > word.substr(k+1,1)){
                    temp_s = word.substr(k,1);
                    word.replace(k,1,word.substr(k+1,1));
                    word.replace(k+1, 1, temp_s);
                    temp_i = order[k];
                    order[k] = order[k+1];
                    order[k+1] = temp_i;
                }
                else if(word.substr(k,1) == word.substr(k+1,1) && order[k] < order[k+1]){
                    temp_i = order[k];
                    order[k] = order[k+1];
                    order[k+1] = temp_i;
                }
            }
        }
        // cout << "word is " << word << endl;
        j = 0;
        while(count < K){
            remain = K - count;
            start = j;
            temp_s = word.substr(j,1);
            while(word.substr(j,1) == temp_s){
                j++;
            }
            end = j-1;
            count++;  // for one letter words
            // cout << "start is " << start << ", end is " << end << endl;
            // cout << "temp_s is " << temp_s << endl;
            // cout << "order[start] is " << order[start] << endl;
            // cout << "order[end] is " << order[end] << endl;
            // naive code, needs optimization (count can be added totally at the beginning)
            for(iter=2; iter<=len-order[end]; iter++){
                for(k=start; k<=end; k++){
                    if(original_word.substr(order[k],iter).length() != iter)  continue;
                    // cout << "sub string is " << original_word.substr(order[k],iter) << endl;
                    count++;
                    for(l=k+1; l<=end; l++){
                        if(original_word.substr(order[k],iter) == original_word.substr(order[l],iter)){
                            count--;
                            break;
                        }
                    }
                }
                // cout << "count is " << count << endl;
            }
        }

        // insertion sort
        string* sorted = new string[count + remain - K];

        int sizeofsorted = 0;
        sorted[0] = temp_s;
        sizeofsorted++;
        for(j=start; j<=end; j++){
            for(iter=2; iter<=len-order[j]; iter++){
                k = 0;
                while(original_word.substr(order[j],iter) > sorted[k] && k < sizeofsorted){
                    k++;
                }
                if(sorted[k] != original_word.substr(order[j],iter)){
                    sizeofsorted++;
                    for(l=sizeofsorted-1; l>k; l--){
                        sorted[l] = sorted[l-1];
                    }
                    sorted[k] = original_word.substr(order[j],iter);
                }
            }
        }

        cout << "#" << i << " " << sorted[remain - 1] << endl;    
        delete sorted;
    }
    return 0;
}