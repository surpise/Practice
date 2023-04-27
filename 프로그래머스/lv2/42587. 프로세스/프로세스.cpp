#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, idx = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i});
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    while(1){
        if(q.front().first != priorities[idx]){
            q.push({q.front().first, q.front().second});
            q.pop();
        }
        else{
            if(q.front().second == location){
                answer = idx + 1;
                break;
            }
            idx++;
            q.pop();
        }
    }
    return answer;
}