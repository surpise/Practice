#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vec[2000];
bool visited[2000];
int ans = 0;

void init(){
  cin >> n >> m;

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
}

void search(int cur, int cnt){
  if(cnt == 4){
    ans = 1;
    return;
  }

  visited[cur] = 1;
  
  for(int idx = 0; idx < vec[cur].size(); idx++){
    int next = vec[cur][idx];
    if(!ans && !visited[next]) search(next, cnt + 1);
  }

  visited[cur] = 0;
}

int main(){
  init();

  for(int idx = 0; idx < n; idx++) {
    search(idx, 0);

    if(ans) break;
  }

  cout << ans;
}