#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int n, m, ans = INF;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

void init(){
  cin >> n >> m;

  int v;
  for(int row = 0; row < n; row++){
    for(int col = 0; col < n; col++) {
      cin >> v;

      if(v == 1) house.push_back({row, col});
      else if(v == 2) chicken.push_back({row, col});
    }
  }
}

void combination(vector<pair<int, int>> comb, int index, int depth){
  if(depth == comb.size()){
    int sum = 0;
    for(int i = 0; i < house.size(); i++) {
      int result = INF;
      for(int j = 0; j < comb.size(); j++){
        int dist = abs(house[i].first - comb[j].first) + abs(house[i].second - comb[j].second);
        
        if(dist < result) result = dist;
      }

      sum += result;
      if(sum > ans) return;
    }

    if(sum < ans) ans = sum;
        
    return;
  }
  else{
    for(int i = index; i < chicken.size(); i++){
      comb[depth] = chicken[i];
      combination(comb, i + 1, depth + 1);
    }
  }
}

int main(){
  init();

  vector<pair<int, int>> c(m);
  combination(c, 0, 0);

  cout << ans;
}