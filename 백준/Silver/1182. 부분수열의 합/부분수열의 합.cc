#include <iostream>

using namespace std;

int N, S, ans;
int arr[20];

void dfs(int depth, int total){
  if(depth == N){
    if(total == S) ans++;

    return;
  }

  dfs(depth + 1, total + arr[depth]);

  dfs(depth + 1, total);
}

int main(){
  cin >> N >> S;
  for(int idx = 0; idx < N; idx++) cin >> arr[idx];

  dfs(0, 0);

  if(S == 0) ans--;

  cout << ans;
}