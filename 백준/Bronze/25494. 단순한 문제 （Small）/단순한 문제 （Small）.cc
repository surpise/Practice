#include <iostream>

using namespace std;

int main(){
    int t, a, b, c, ans;
    cin >> t;
    int mod1, mod2, mod3;
    for(int i = 0; i < t; i++){
        ans = 0;
        cin >> a >> b >> c;
        for (int x = 1; x <= a; x++){
            for(int y = 1; y <= b; y++){
                for(int z = 1; z <= c; z++){
                    mod1 = x % y;
                    mod2 = y % z; 
                    mod3 = z % x;
                    if(mod1 == mod2 && mod1 == mod3 && mod2 == mod3) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}