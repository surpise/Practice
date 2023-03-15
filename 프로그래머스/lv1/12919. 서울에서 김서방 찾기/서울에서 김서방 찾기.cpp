#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int cnt = 0;
    for(auto e = seoul.begin(); e != seoul.end(); e++){
        if(seoul[cnt] == "Kim") break;
        cnt++;
    }
    string answer = "김서방은 " + to_string(cnt) + "에 있다";
    return answer;
}