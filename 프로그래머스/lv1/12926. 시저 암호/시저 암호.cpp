#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    char t;
    for(int i = 0; i < s.size(); i++){
        t = s[i];
        if(s[i] >= 'a' && s[i] <= 'z') {
            if(s[i] - 'a' + n >= 26) t = s[i] + (n - 26);
            else t += n;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            if(s[i] - 'A' + n >= 26) t = s[i] + (n - 26);
            else t += n;
        }
        answer += t;
    }
    return answer;
}