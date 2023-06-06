#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0, s;
    if(target.size() > my_string.size()) return 0;
    for(int i = 0; i <= my_string.size() - target.size(); i++){
        s = 0;
        if(my_string[i] == target[0]){
            for(int j = 1; j < target.size(); j++){
                if(my_string[i + j] != target[j]) s = 1;
            }
            if(!s) {
                answer = 1;
                break;
            }
        }
    }
    return answer;
}