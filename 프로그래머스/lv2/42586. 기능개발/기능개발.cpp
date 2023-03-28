#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++) q.push(progresses[i]);
    int idx = 0, d = 1, cnt = 0;
    while(!q.empty()){
        while(!q.empty() && q.front() + (d * speeds[idx]) >= 100){
            q.pop();
            cnt++;
            idx++;
        }
        if(cnt > 0){
            answer.push_back(cnt);
            cnt = 0;
        }
        d++;
    }
    return answer;
}