#include <iostream>
#include <queue>

using namespace std;

vector<int> graph[20001];
int vis[20001];
queue<pair<int, int>> q;
int res = 1;
void bfs(){
    int x = q.front().first, bip = q.front().second;
    int t = (bip == 1) ? -1 : 1;
    vis[x] = bip;
    q.pop();
    for(int i = 0; i < graph[x].size(); i++){
        if(vis[graph[x][i]] == 0){
            q.push({graph[x][i], t});
        }
        else{
            if(vis[graph[x][i]] == bip){
                res = 0;
            }
        }
    }
}

int main(){
    int tc, v , e, a, b;
    cin >> tc;

    for(int t = 0; t < tc; t++){
        cin >> v >> e;
        for(int i = 1; i < 20001; i++) {
            graph[i].clear();
            vis[i] = 0;
        }
        res = 1;
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1; i <= v; i++){
            if(vis[i] == 0){
                q.push({i, 1});
                while(!q.empty()) bfs();
            }
        }
        
        if(res) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}