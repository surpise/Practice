#include <string>
#include <vector>
#include <queue>

using namespace std;

class cmp{
    public:
        bool operator()(vector<int> a, vector<int> b){
            return a[1] > b[1];
        }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    int answer = 0, now = 0, cnt = 0;
    bool v[500] = {0, };

    while(cnt < jobs.size()){
        for(int idx = 0; idx < jobs.size(); idx++){
            if(!v[idx] && jobs[idx][0] <= now) {
                v[idx] = true;
                pq.push(jobs[idx]);
            }
        }
        
        if(pq.empty()) {
            now++;
            continue;
        }

        answer += pq.top()[1] + (now - pq.top()[0]);
        now += pq.top()[1];
        pq.pop();       
        cnt++;
    }    
    
    return answer / jobs.size();
}