#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 0;
bool alpha[26];
vector<string> vec;

void init(){
  cin >> n >> k;

  string str;
  for(int idx = 0; idx < n; idx++) {
    cin >> str;
    vec.push_back(str);
  }

  alpha['a' - 'a'] = 1;
  alpha['c' - 'a'] = 1;
  alpha['i' - 'a'] = 1;
  alpha['n' - 'a'] = 1;
  alpha['t' - 'a'] = 1;
}

bool checkStr(string str){
  for(int idx = 0; idx < str.size(); idx++){
    if(!alpha[str[idx] - 'a']) return false;
  }

  return true;
}

void search(int start, int depth){
  if(depth == k){
    int cnt = 0;

    for(int idx = 0; idx < vec.size(); idx++) {
      if(checkStr(vec[idx])) cnt++;
    }

    ans = max(ans, cnt);

    return;
  }

  for(int idx = start; idx < 26; idx++){
    if(alpha[idx]) continue;

    alpha[idx] = 1;
    search(idx, depth + 1);
    alpha[idx] = 0;
  }
}

int main(){
  init();

  if(k >= 5){
    k -= 5;
    search(0, 0);
  }

  cout << ans;
}