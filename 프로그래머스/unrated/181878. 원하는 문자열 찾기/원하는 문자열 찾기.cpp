#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0, s;
    if(pat.size() > myString.size()) return answer;
    for(int i = 0; i < myString.size(); i++){
        if(myString[i] >= 'A' && myString[i] <= 'Z') myString[i] += 'a' - 'A';
    }
    for(int i = 0; i < pat.size(); i++){
        if(pat[i] >= 'A' && pat[i] <= 'Z') pat[i] += 'a' - 'A';
    }
    for(int i = 0; i <= myString.size() - pat.size(); i++){
        s = 0;
        if(myString[i] == pat[0]){
            for(int j = 1; j < pat.size(); j++){
                if(myString[i + j] != pat[j]) s = 1;
            }
            if(!s) answer = 1;
        }
    }
    return answer;
}