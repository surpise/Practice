#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
queue<int> q;
bool vis[100001];
int ans[100001];

void bfs(){
    int t = q.front();
    q.pop();
    if(!vis[t]){
        vis[t] = 1;
        for(int i = 0; i < v[t].size(); i++){
            if(!vis[v[t][i]]){
                ans[v[t][i]] = t;
                q.push(v[t][i]);
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    while(!q.empty()) bfs();

    for(int i = 2; i <= n; i++) cout << ans[i] << '\n';  
}