#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int tmp;
    for(int i = 0; i < s.size(); i++){
        tmp = 1;
        for(int j = i - 1; j >= 0; j--){
            if(s[i] == s[j]) {
                answer.push_back(tmp);
                break;
            }
            tmp++;
        }
        if(tmp == i + 1) answer.push_back(-1);
    }
    return answer;
}