#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 1;
    if(is_suffix.size() > my_string.size()) return 0;
    for(int i = 1; i <= is_suffix.size(); i++){
        if(my_string[my_string.size() - i] != is_suffix[is_suffix.size() - i]){
            answer = 0;
        }
    }
    return answer;
}