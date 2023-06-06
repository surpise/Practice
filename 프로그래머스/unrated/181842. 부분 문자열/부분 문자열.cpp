#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0, s = 0;
    for(int i = 0; i <= str2.size() - str1.size(); i++){
        s = 0;
        if(str1[0] == str2[i]){
            for(int j = 1; j < str1.size(); j++){
                if(str2[i + j] != str1[j]) s = 1;
            }
            if(!s) answer = 1;
        }
    }
    return answer;
}