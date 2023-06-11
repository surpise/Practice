#include <iostream>

using namespace std;

int main(){
    int t, x, ans = 0;
    cin >> t;
    for(int i = 0; i < 5; i++){
        cin >> x;
        if(t == x) ans++;
    }
    cout << ans;
}