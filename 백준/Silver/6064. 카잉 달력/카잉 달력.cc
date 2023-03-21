#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t, m, n, x, y;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> m >> n >> x >> y;

        int s = 1;
        for(int i = 2; i <= min(m, n); i++){
            if(m % i == 0 && n % i == 0){
                if(i > s) s == i;
            }
        }
        s = m * n / s;
        
        int ans = -1;
        if(y == n) y = 0;
        for(int i = x; i <= s; i += m){
            if(i % n == y){
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
}