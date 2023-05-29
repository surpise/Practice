#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector<pair<int, int>> tree[10001];
bool v[10001];
void dfs(int node, int sum){
    v[node] = 1;
    for(int i = 0; i < tree[node].size(); i++){
        if(!v[tree[node][i].first]){
            dfs(tree[node][i].first, sum + tree[node][i].second);
        }
    }
    if(sum > ans) ans = sum;
}

int main(){
    cin >> n;
    int a, b, c;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) v[j] = 0;
        dfs(i, 0);
    }
    cout << ans;
}