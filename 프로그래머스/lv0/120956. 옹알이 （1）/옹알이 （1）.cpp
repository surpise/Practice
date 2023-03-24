#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = babbling.size();
    string arr[4] = {"aya", "ye", "woo", "ma"};
    for(int i = 0; i < babbling.size(); i++){
        for(int j = 0; j < 4; j++){
            if(babbling[i].find(arr[j]) != string::npos){
                babbling[i].replace(babbling[i].find(arr[j]), arr[j].length(), "1");
            }
        }
        for(int j = 0; j < babbling[i].size(); j++){
            if(babbling[i][j] != '1') {
                answer--;
                break;
            }
        }
    }
    return answer;
}