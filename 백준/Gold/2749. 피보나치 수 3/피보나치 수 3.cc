#include <iostream>

#define INF 1500000
#define MOD 1000000

using namespace std;

long long arr[INF];

void fibo(){
  arr[0] = 0;
  arr[1] = 1;

  for(int idx = 2; idx <= INF; idx++){
    arr[idx] = (arr[idx - 1] + arr[idx - 2]) % MOD;
  }
}

int main(){
  long long n;
  cin >> n;

  fibo();

  cout << arr[n % INF];
}