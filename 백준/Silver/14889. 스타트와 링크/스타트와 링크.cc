#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
int power[20][20];
bool v[20];

void init(){
  cin >> n;
  for(int row = 0; row < n; row++){
    for(int col = 0; col < n; col++) cin >> power[row][col];
  }
}

void calcPower(){
  vector<int> t1, t2;
  for(int i = 0; i < n; i++){
    if(v[i]) t1.push_back(i);
    else t2.push_back(i);
  }

  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < t1.size(); i++){
    for(int j = 0; j < t1.size(); j++){
      if(i == j) continue;
      sum1 += power[t1[i]][t1[j]];
    }
  }

  for(int i = 0; i < t2.size(); i++){
    for(int j = 0; j < t2.size(); j++){
      if(i == j) continue;
      sum2 += power[t2[i]][t2[j]];
    }
  }

  int diff = abs(sum1 - sum2);
  if(ans > diff) ans = diff;
}

void makeTeam(int start, int cnt){
  if(cnt == n / 2){
    calcPower();
    return;
  }

  for(int i = start; i < n; i++){
    if(!v[i]){
      v[i] = true;
      makeTeam(i + 1, cnt + 1);
      v[i] = false;
    }
  }
}

int main(){
  init();

  makeTeam(0, 0);

  cout << ans;
}