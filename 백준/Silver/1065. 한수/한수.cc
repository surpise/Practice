#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n < 100) cout << n;
    else{
        int ans = 99, t, a, b, diff;
        for(int i = n; i > 99; i--){
            t = i;
            a = 999;
            diff = 10;
            while(t > 0){
                if(a == 999) {
                    a = t % 10;
                    t /= 10;
                }
                else{
                    if(diff == 10){
                        b = t % 10;
                        t /= 10;
                        diff = b - a;
                    }
                    else{
                        a = t % 10;
                        if(b + diff != a) break;
                        t /= 10;
                    }
                }   
            }
            if(t == 0) ans++;
        }
        cout << ans;
    }
}

