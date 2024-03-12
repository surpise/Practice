#include <iostream>
#include <vector>

using namespace std;

bool fin = false;
vector<vector<int>> sdk(9, vector<int>(9));
vector<pair<int, int>> vec;

void init(){
  for(int r = 0; r < 9; r++){
    for(int c = 0; c < 9; c++) {
      cin >> sdk[r][c];
      if(!sdk[r][c]) vec.push_back({r, c});
    }
  }
}

bool check(vector<vector<int>>& arr, int x, int y){
  for(int i = 0; i < 9; i++){
    if(arr[i][y] == arr[x][y] && i != x) return false;
    if(arr[x][i] == arr[x][y] && i != y) return false;
  }

  int tr = x / 3 * 3;
  int ty = y / 3 * 3;
  for(int i = tr; i < tr + 3; i++){
    for(int j = ty; j < ty + 3; j++){
      if(i == x && j == y) continue;
      if(arr[i][j] == arr[x][y]) return false;
    }
  }

  return true;
}

void dfs(vector<vector<int>>& arr, int cnt){
  if(cnt == vec.size()){
    fin = true;

    for(int r = 0; r < 9; r++){
      for(int c = 0; c < 9; c++) cout << arr[r][c] << " ";
      cout << '\n';
    }

    return;
  }

  int x = vec[cnt].first;
  int y = vec[cnt].second;

  for(int i = 1; i < 10; i++){
    arr[x][y] = i;

    if(check(arr, x, y)){
      dfs(arr, cnt + 1);
    }
    
    if(fin) return;
  }

  arr[x][y] = 0;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  init();

  dfs(sdk, 0);
}