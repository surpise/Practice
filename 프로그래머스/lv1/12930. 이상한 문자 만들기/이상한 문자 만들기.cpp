#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        answer += s[i];
        if(answer[i] == ' ') c = -1;
        else if(c % 2 == 0 && answer[i] - 'a' >= 0) answer[i] -= 'a' - 'A';
        else if(c % 2 != 0 && answer[i] - 'a' < 0) answer[i] += 'a' - 'A';
        c++;
    }
    return answer;
}