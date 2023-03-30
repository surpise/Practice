#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, c = 0, idx = 0;
    if(s[0] == '-') c = 1;
    else if(s[0] == '+') c = 2;
    
    if(c != 0) idx = 1;
    while(idx < s.size()){
        answer *= 10;
        answer += s[idx++] - '0';
    }
    if(c == 1) answer *= -1;
    return answer;
}