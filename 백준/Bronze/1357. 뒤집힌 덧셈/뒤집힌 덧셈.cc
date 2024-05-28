#include <iostream>

using namespace std;

int getRev(int n){
  int res = 0;

  while(n > 0){
    res *= 10;
    res += n % 10;
    n /= 10;
  }

  return res;
}

int main(){
  int x , y;
  cin >> x >> y;

  cout << getRev(getRev(x) + getRev(y));
}