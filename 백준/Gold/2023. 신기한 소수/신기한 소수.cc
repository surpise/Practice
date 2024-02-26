#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;

bool isPrime(int num){
  if(num == 1) return false;
  if(num == 2) return true;

  for(int idx = 2; idx <= (int)sqrt(num) + 1; idx++){
    if(num % idx == 0) return false;
  }

  return true;
}

void dfs(int d, int num){
  if(d == n) {
    if(num / 10 >= pow(10, n - 1)) cout << num / 10 << '\n';
    return;
  }

  for(int cnt = 0; cnt < 10; cnt++){
    int tmp = num + cnt;
    if(isPrime(tmp)) dfs(d + 1, tmp * 10);
  }
}

int main(){
  cin >> n;

  dfs(0, 0);
}