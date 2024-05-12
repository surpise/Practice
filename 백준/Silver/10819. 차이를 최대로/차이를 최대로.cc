#include <iostream>
#include <vector>

using namespace std;

int N, ans;
int arr[8];
bool visited[8];

int calc(vector<int> vec){
  int sum = 0;

  for(int idx = 0; idx < N - 1; idx++){
    sum += abs(vec[idx] - vec[idx + 1]);
  }
  return sum;
}

void search(int depth, vector<int> vec){
  if(depth == N){
    int res = calc(vec);
    if(ans < res) ans = res;
    return;
  }

  for(int idx = 0; idx < N; idx++){
    if(!visited[idx]){
      vec[depth] = arr[idx];
      visited[idx] = 1;
      search(depth + 1, vec);
      visited[idx] = 0;
    }
  }
}

int main(){
  cin >> N;

  for(int idx = 0; idx < N; idx++) cin >> arr[idx];

  vector<int> tmp(N);
  search(0, tmp);

  cout << ans;
}