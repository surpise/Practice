#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int l[31] = {0, };
    int r[31] = {0, };
    for(int i = 0; i < lost.size(); i++) l[lost[i]] = 1;
    for(int i = 0; i < reserve.size(); i++) {
        if(l[reserve[i]] == 0) r[reserve[i]] = 1;
        else l[reserve[i]] = 0;
    }
    for(int i = 1; i <= n; i++) {
        if(l[i] == 1){
            if(r[i - 1] == 1) {
                l[i] = 0;
                r[i - 1] = 0;
            }
            else if(r[i + 1] == 1){
                l[i] = 0;
                r[i + 1] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(l[i] == 0) answer++;
    }
    return answer;
}