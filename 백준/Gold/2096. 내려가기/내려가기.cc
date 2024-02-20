#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int dpMax[3] = {0, };
  int dpMin[3] = {0, };

  cin >> n;

  int a, b, c;
  cin >> a >> b >> c;
  dpMax[0] = a;
  dpMax[1] = b;
  dpMax[2] = c;

  dpMin[0] = a;
  dpMin[1] = b;
  dpMin[2] = c;

  int tmpDp[3] = {0, };
  for(int line = 1; line < n; line++){
    cin >> a >> b >> c;

    tmpDp[0] = a + max(dpMax[0], dpMax[1]);
    tmpDp[1] = b + max({dpMax[0], dpMax[1], dpMax[2]});
    tmpDp[2] = c + max(dpMax[1], dpMax[2]);

    dpMax[0] = tmpDp[0];
    dpMax[1] = tmpDp[1];
    dpMax[2] = tmpDp[2];

    tmpDp[0] = a + min(dpMin[0], dpMin[1]);
    tmpDp[1] = b + min({dpMin[0], dpMin[1], dpMin[2]});
    tmpDp[2] = c + min(dpMin[1], dpMin[2]);
    
    dpMin[0] = tmpDp[0];
    dpMin[1] = tmpDp[1];
    dpMin[2] = tmpDp[2];
  }

  cout << max({dpMax[0], dpMax[1], dpMax[2]}) << " " << min({dpMin[0], dpMin[1], dpMin[2]});
}