#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<pair<int, int>, vector<int>>> bfsq;
bool v[200002];
vector<int> tv;

int n, k;
void bfs(){
    tv.clear();
    int x = bfsq.front().first.first;
    v[x] = 1;
    int cnt = bfsq.front().first.second;
    tv = bfsq.front().second;
    bfsq.pop();
    if(x == k){
        cout << cnt << '\n';
        for(int i = 0; i < tv.size(); i++) cout << tv[i] << " ";
        while(!bfsq.empty()) bfsq.pop();
        return;
    }
    if(x > 0) {
        tv.push_back(x - 1);
        if (!v[x - 1])bfsq.push({{x - 1, cnt + 1}, tv});
        tv.pop_back();
    }
    if(x <= 100000) {
        tv.push_back(x + 1);
        if (!v[x + 1])bfsq.push({{x + 1, cnt + 1}, tv});
        tv.pop_back();
    }
    if(x * 2 <= 200001){
        tv.push_back(x * 2);
        if (!v[x * 2])bfsq.push({{x * 2, cnt + 1}, tv});
    }
}
int main(){
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    if(n > k){
        cout << n - k << '\n';
        for(int i = n; i >= k; i--) cout << i << " ";
    }
    else{
        vector<int> v = {n};
        bfsq.push({{n, 0}, v});
        while(!bfsq.empty()) bfs();
    }
}