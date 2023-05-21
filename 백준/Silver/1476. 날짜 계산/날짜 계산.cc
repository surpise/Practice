#include <iostream>

using namespace std;

int main(){
    int e, s, m, ans = 1;
    int ae = 1, as = 1, am = 1;
    cin >> e >> s >> m;
    while(1){
        if(ae == e && as == s && am == m) break;
        ae++;
        as++;
        am++;
        if(ae > 15) ae = 1;
        if (as > 28) as = 1;
        if (am > 19) am = 1;
        ans++;
    }
    cout << ans;
}