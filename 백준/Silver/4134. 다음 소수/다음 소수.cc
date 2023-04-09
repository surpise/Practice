#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long tc, n, m, ans;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        cin >> n;
        bool p = (n < 3) ? 1 : 0;
        ans = (n < 3) ? 2 : n;
        while(!p){
            m = sqrt(n) + 1;
            for(int i = 2; i <= m; i++){
                if(n % i == 0) break;
                if (i == m) {
                    ans = n;
                    p = 1;
                }
            }
            n++;
        }
        cout << ans << '\n';
    }
}