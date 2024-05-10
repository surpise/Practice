#include <iostream>

using namespace std;

int main(){
  int n, ans = 0;
  cin >> n;

  while(n >= 0){
    if(n % 5 == 0){
      ans += n / 5;
      cout << ans;
      return 0;
    }

    n -= 3;
    ans++;
  }

  cout << -1;
}