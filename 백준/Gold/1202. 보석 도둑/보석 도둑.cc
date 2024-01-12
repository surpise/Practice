#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> gems;
  int m, v;
  for(int i = 0; i < n; i++){
    cin >> m >> v;
    gems.push_back({m, v});
  }
  sort(gems.begin(), gems.end());

  vector<int> bags;
  int c;
  for(int i = 0; i < k; i++){
    cin >> c;
    bags.push_back(c);
  }
  sort(bags.begin(), bags.end());

  int gIdx = 0;
  unsigned long ans = 0;
  priority_queue<int, vector<int>, less<int>> pq;

  for(int bIdx = 0; bIdx < k; bIdx++){
    while(gIdx < n && gems[gIdx].first <= bags[bIdx]){
      pq.push(gems[gIdx].second);
      gIdx++;
    }

    if(!pq.empty()){
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans;
}