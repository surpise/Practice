#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, idx = 0, cur = 0;
    queue<pair<int, int>> q;
    while(1){
        answer++;
        if(!q.empty() && answer - q.front().second == bridge_length){
            cur -= q.front().first;
            q.pop();
            if(q.empty() && idx == truck_weights.size()) break;
        }
        if(idx < truck_weights.size()){
            if(q.size() < bridge_length && cur + truck_weights[idx] <= weight){
                q.push({truck_weights[idx], answer});
                cur += truck_weights[idx];
                idx++;
            }
        }
    }
    
    return answer;
}