/*
    using bubble sort
*/
#include <iostream>
// #include <string>

using namespace std;
int string_compare(char* word1, char* word2);
int string_length(char* word);

int main(){
    int TC, K;
    int i, j, k, word_length, temp;
    int order[400];
    char word[400];
    cin >> TC;
    //printf("TC=%d\n",TC);
    for(i=1; i<=TC; i++){
        
        cin >> K;
        cin >> word;
        //printf("K=%d, word=%s\n",K,word);
        
        word_length = string_length(word);
        //printf("word_length is %d\n", word_length);
        
        for(j=0; j<word_length; j++){
            order[j] = j;
        }
        
        // bubble sort
        for(j=0; j<word_length-1; j++){
            
            for(k=word_length-2; k>=j; k--){
                if(string_compare(word+order[k], word+order[k+1]) < 0){
                    temp = order[k];
                    order[k] = order[k+1];
                    order[k+1] = temp;
                }
            }
        }

        cout <<"#" << i << " " << word+order[K-1] << endl;
    }
    return 0;
}

// string compare function
int string_compare(char* word1, char* word2){
    int length1, length2;
    int min_length;
    int i;
    
    length1 = string_length(word1);
    length2 = string_length(word2);
    
    min_length = length1 < length2 ? length1 : length2; 

    for(i=0; i<min_length; i++){
        if(word1[i] > word2[i]) return -1;
        else if(word1[i] == word2[i])   continue;
        else return 1;
    }
    if(length1 > length2) return -1;
    // else if(length1 == length2)  return 0;
    else return 1;
}

// strlen function
int string_length(char* word){
    char* temp = word;
    int len = 0;
    while(*temp != '\0'){
        len++;
        temp += 1;
    }
    return len;
}
