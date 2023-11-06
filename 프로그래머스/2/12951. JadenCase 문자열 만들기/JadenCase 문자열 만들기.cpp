#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ' && isFirst){
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')){
                answer += s[i];
            }
            else{
                answer += s[i] + ('A' - 'a');
            }
            isFirst = false;
        }
        else{
            if(s[i] >= 'A' && s[i] <= 'Z'){
                answer += s[i] - ('A' - 'a');
            }
            else{
                answer += s[i];
            }
            if(s[i] == ' '){
                isFirst = true;
            }
        }
    }
    return answer;
}