#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 2;
    for(int i = 0; i < str1.size(); i ++){
        for(int j = 0; j < str2.size(); j++){
            if(str1[j + i] != str2[j]) {
                answer = 2;
                break;
            }
            else answer = 1;
        }
        if(answer == 1) break;
    }
    return answer;
}