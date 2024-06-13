#include <string>
#include <vector>
#include <queue>

using namespace std;

int sz;
int arr[101][101];

int check(int start){
    bool visited[101] = {0, };
    visited[start] = 1;
    
    queue<int> q;
    q.push(start);
    int cnt = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int idx = 1; idx <= sz; idx++){
            if(!visited[idx] && arr[cur][idx]){
                visited[idx] = 1;
                q.push(idx);
                cnt++;
            }
        }
    }

    return abs((sz - cnt) - cnt);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999999;
    sz = n;
    
    for(int idx = 0; idx < wires.size(); idx++){
        arr[wires[idx][0]][wires[idx][1]] = 1;
        arr[wires[idx][1]][wires[idx][0]] = 1;
    }
    
    for(int idx = 0; idx < wires.size(); idx++){
        arr[wires[idx][0]][wires[idx][1]] = 0;
        arr[wires[idx][1]][wires[idx][0]] = 0;
        
        answer = min(check(wires[idx][0]), answer);
        
        arr[wires[idx][0]][wires[idx][1]] = 1;
        arr[wires[idx][1]][wires[idx][0]] = 1;
    }
    
    
    return answer;
}