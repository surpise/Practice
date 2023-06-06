#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    int t = 0;
    for(int i = 0; i < my_string.size(); i++){
        if(my_string[i] == ' '){
            answer.push_back(my_string.substr(t, i - t));
            t = i + 1;
        }
    }
    answer.push_back(my_string.substr(t, my_string.size()));
    return answer;
}