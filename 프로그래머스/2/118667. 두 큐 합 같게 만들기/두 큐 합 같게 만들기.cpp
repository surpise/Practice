#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> que1, que2;
    long long q1 = 0, q2 = 0;
    for(int i = 0; i < queue1.size(); i++){
        que1.push(queue1[i]);
        que2.push(queue2[i]);
        q1 += queue1[i];
        q2 += queue2[i];
    }
    
    int answer = 0;
  
    while(1){
        if(answer > queue1.size() * 4){
            return -1;
        }
        if(q1 > q2){
            q2 += que1.front();
            q1 -= que1.front();
            que2.push(que1.front());
            que1.pop();
        }
        else if(q2 > q1){
            q1 += que2.front();
            q2 -= que2.front();
            que1.push(que2.front());
            que2.pop();
        }
        else{
            break;
        }
        answer++;
    }
    return answer;
}