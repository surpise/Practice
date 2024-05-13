#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[15], res[15];
char mo[5] = {'a', 'e', 'i', 'o', 'u'};

bool check(){
  int moCnt = 0, jaCnt = 0;
  for(int idx = 0; idx < L; idx++){
    if(find(mo, mo + 5, res[idx]) != mo + 5) moCnt++;
    else jaCnt++;
  }

  if(moCnt >= 1 && jaCnt >= 2) return true;
  else return false;
}

void search(int depth, int cnt){
  if(depth >= C){
    if(cnt == L && check()){
      for(int idx = 0; idx < L; idx++) cout << res[idx];
      cout << '\n';
    }
    return;
  }

  res[cnt] = arr[depth];
  search(depth + 1, cnt + 1);
  search(depth + 1, cnt);
}

int main(){
  cin >> L >> C;
  for(int idx = 0; idx < C; idx++) cin >> arr[idx];

  sort(arr, arr + C);

  search(0, 0);
}