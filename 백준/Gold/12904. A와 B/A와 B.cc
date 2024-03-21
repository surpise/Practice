#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void checkAB(string s, string t){
  queue<string> q;
  q.push(t);

  while(!q.empty()){
    string str = q.front();
    q.pop();
    
    if(str == s) {
      cout << 1;
      return;
    }

    else if(str.size() - 1 < s.size()) continue;
    
    string tmp = str.substr(0, str.size() - 1);
    if(str[str.size() - 1] == 'A') q.push(tmp);
    else{
      reverse(tmp.begin(), tmp.end());
      q.push(tmp);
    }
  }

  cout << 0;
}

int main(){
  string s, t;
  cin >> s >> t;

  checkAB(s, t);
}