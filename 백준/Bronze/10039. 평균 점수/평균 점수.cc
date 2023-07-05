#include <iostream>

using namespace std;

int main(){
    int n, ans = 0;
    for(int i = 0; i < 5; i++){
        cin >> n;
        if(n < 40) ans += 40;
        else ans += n;
    }
    cout << ans / 5;
}