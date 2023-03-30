#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool cmp(int a, int b){
    return a < b;
}
int solution(vector<int> scoville, int K) {
    int answer = 0, a, b;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < scoville.size(); i++) q.push(scoville[i]);
    while(q.top() < K){
        a = -1, b = -1;
        a = q.top();
        if(!q.empty())q.pop();
        else break;
        b = q.top() * 2;
        if(!q.empty())q.pop();
        else break;
        q.push(a + b);
        answer++;
    }
    
    if(q.empty() || q.top() < K) answer = -1;
    return answer;
}