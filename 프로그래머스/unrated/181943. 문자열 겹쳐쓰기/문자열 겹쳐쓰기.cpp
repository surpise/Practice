#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    for(int i = 0; i < my_string.size(); i++){
        if(i == s){
            for(int j = 0; j < overwrite_string.size(); j++){
                answer += overwrite_string[j];
            }
            i += overwrite_string.size() - 1;
        }
        else answer += my_string[i];
    }
    return answer;
}