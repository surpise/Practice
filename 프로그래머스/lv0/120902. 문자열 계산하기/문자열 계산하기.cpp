#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    vector<string> vec;
    int tmp = 0;
    for(int i = 0; i < my_string.size(); i++){
        if(my_string[i] == ' '){
            vec.push_back(my_string.substr(tmp, i - tmp));
            tmp = i + 1;
        }
    }
    vec.push_back(my_string.substr(tmp));
    for(int i = 0; i < vec.size(); i += 2){
        tmp = 0;
        for(int j = 0; j < vec[i].size(); j++){
            tmp *= 10;
            tmp += vec[i][j] - '0';
        }
        if(i == 0) answer = tmp;
        else{
            if(vec[i - 1] == "+") answer += tmp;
            else answer -= tmp;
        }
    }
    return answer;
}