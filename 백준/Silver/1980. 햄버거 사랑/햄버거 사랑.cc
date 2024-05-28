#include <iostream>

using namespace std;

int main(){
  int n, m, t;
  cin >> n >> m >> t;

  int bb = 0, coke = 0;
  int bigB = max(n, m);
  int smallB = min(n, m);
  
  while(1){
    int tt = t - bigB * bb;

    if(tt < 0) {
      t--;
      coke++;
      bb = 0;

      continue;
    }

    if(tt % smallB == 0) {

      cout << tt / smallB + bb << " " << coke;
      return 0;
    }

    bb++;
  }
}
