#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> v) {
    int answer = 0, cnt;
    sort(v.begin(), v.end(), greater<int>());
    for(int i = v[0]; i >= 0; i--){
        cnt = 0;
        for(int j = 0; j < v.size(); j++){
            if(i <= v[j]) cnt++;
            else break;
        }
        if(i <= cnt && answer < i) answer = i;
    }
    return answer;
}