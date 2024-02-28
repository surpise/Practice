#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, last;
int t[1001], inN[1001], res[1001];
vector<int> building[1001];
queue<int> q;

void init(){
  cin >> n >> k;
  for(int idx = 1; idx <= n ; idx++) {
    inN[idx] = 0;
    res[idx] = 0;
    building[idx].clear();
    cin >> t[idx];
  }

  int s, e;
  for(int idx = 0; idx < k; idx++){
    cin >> s >> e;
    building[s].push_back(e);
    inN[e]++;
  }

  for(int idx = 1; idx <= n; idx++){
    if(!inN[idx]) {
      q.push(idx);
      inN[idx] = -1;
      res[idx] = t[idx];
    }
  }
 
  cin >> last;
}

void acmSort(){
  while(!q.empty()){
    int tmp = q.front();
    q.pop();

    for(int idx = 0; idx < building[tmp].size(); idx++){
      int nextIdx = building[tmp][idx];
      inN[nextIdx]--;
      if(!inN[nextIdx]){
        q.push(nextIdx);
        inN[nextIdx] = -1;
      }

      if(res[nextIdx] < t[nextIdx] + res[tmp]) res[nextIdx] = t[nextIdx] + res[tmp];
    }    
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T;
  while(T--){
    init();

    acmSort();

    cout << res[last] << '\n';
  }
}