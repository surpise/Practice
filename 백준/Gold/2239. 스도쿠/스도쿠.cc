#include <iostream>
#include <vector>

using namespace std;

bool found = 0;
int ans[10][10];
vector<pair<int, int>> vec;

void init(){
  string str;
  for(int row = 1; row <= 9; row++){
    cin >> str;
    for(int idx = 1; idx <= 9; idx++) {
      ans[row][idx] = str[idx - 1] - '0';
      if(ans[row][idx] == 0) vec.push_back({row, idx});
    }
  }
}

bool isPossible(int _r, int _c, int _v){
  for(int idx = 1; idx <= 9; idx++){
    if(idx != _c && ans[_r][idx] == _v) return false;

    if(idx != _r && ans[idx][_c] == _v) return false;

    int nr = (_r - 1) / 3 * 3 + (idx - 1) / 3 + 1;
    int nc = (_c - 1) / 3 * 3 + (idx - 1) % 3 + 1;
    if(nr != _r && nc != _c && ans[nr][nc] == _v) return false;
  }

  return true;
}

void solution(int v){
  if(found) return;

  if(v == vec.size()){
    for(int row = 1; row <= 9; row++){
      for(int col = 1; col <= 9; col++) cout << ans[row][col];
      cout << '\n';
    }
    
    found = 1;
    return;
  }

  int r = vec[v].first;
  int c = vec[v].second;
  for(int value = 1; value <= 9; value++){
    if(isPossible(r, c, value)){
      ans[r][c] = value;
      solution(v + 1);
      ans[r][c] = 0;
    }
  }
}

int main(){
  init();

  solution(0);
}