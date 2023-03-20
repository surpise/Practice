#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int tmp = 0, cnt = 0;
    for(int i = 0; i < my_str.size(); i++){
        cnt++;
        if(cnt == n){
            answer.push_back(my_str.substr(tmp, n));
            tmp = i + 1;
            cnt = 0;
        }
    }
    if(my_str.size() % n != 0) answer.push_back(my_str.substr(tmp));
    return answer;
}