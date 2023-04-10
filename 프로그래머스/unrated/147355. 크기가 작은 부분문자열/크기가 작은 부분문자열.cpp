#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    long long answer = 0, nump = 0, tmp;
    for(int i = 0; i < p.size(); i++){
        nump *= 10;
        nump += p[i] - '0';
    }
    for(int i = 0; i <= t.size() - p.size(); i++){
        tmp = 0;
        for(int j = i; j < i + p.size(); j++){
            tmp *= 10;
            tmp += t[j] - '0';
        }
        if(tmp <= nump) answer++;
    }
    return answer;
}