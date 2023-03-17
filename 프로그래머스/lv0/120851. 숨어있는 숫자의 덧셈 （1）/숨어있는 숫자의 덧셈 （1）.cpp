#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0, tmp;
    for(int i = 0; i < my_string.size(); i++){
        tmp = my_string[i] - '0';
        if(tmp < 10) answer += tmp;
    }
    return answer;
}