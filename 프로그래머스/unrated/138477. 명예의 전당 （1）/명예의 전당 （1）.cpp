#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int> q, t;
    for(int i = 0; i < score.size(); i++){
        q.push(score[i]);
        while(!q.empty() && t.size() < k - 1){
            t.push(q.top());
            q.pop();
        }
        answer.push_back(q.top());
        while(!t.empty()) {
            q.push(t.top());
            t.pop();
        }
    }

    return answer;
}