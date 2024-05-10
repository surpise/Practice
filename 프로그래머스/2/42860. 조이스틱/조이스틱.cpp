#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, sz = name.size(), minMove = sz - 1;
        
    for(int idx = 0; idx < sz; idx++){
        int alpha = name[idx] - 'A';
        answer += min(alpha, 26 - alpha);
        
        int t = idx + 1;
        while(t < sz && name[t] == 'A') t++;

        int tt = sz - t;
        minMove = min({minMove, idx + idx + tt, tt + tt + idx});
    }
    
    answer += minMove;
    
    return answer;
}