#include <iostream>
#include <vector>

using namespace std;

int v, nd, ans = 0;
bool vis[100001];
vector<pair<int, int>> tree[100001];

void dfs(int node, int sum){
    if(sum > ans) {
        ans = sum;
        nd = node;
    }
    vis[node] = 1;

    int cnt = 0;
    for(int i = 0; i < tree[node].size(); i++){
        if(!vis[tree[node][i].first]){
            dfs(tree[node][i].first, sum + tree[node][i].second);
            cnt++;
        }
    }
}

int main(){
    cin >> v;

    int n, x, d;
    for(int i = 0; i < v; i++){
        cin >> n;
        while(1){
            cin >> x;
            if(x == -1) break;
            cin >> d;
            tree[n].push_back({x, d});
        }
    }

    dfs(1, 0);
    for(int i = 1; i <= v; i++) vis[i] = 0;
    dfs(nd, 0);
    cout << ans;
}