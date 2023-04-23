#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, cnt = 0, diff = 0;
    char t = s[0];
    for(int i = 0; i < s.size(); i++){
        if(s[i] == t) cnt++;
        else diff++;
        
        if(cnt == diff){
            answer++;
            cnt = 0;
            diff = 0;
            if(i < s.size() - 1) t = s[i + 1];
        }
    }
    if(cnt != diff) answer++;
    return answer;
}