#include <iostream>

using namespace std;

int main(){
    unsigned long long n, ans;
    cin >> n;
    if(n == 1) ans = 1;
    else if(n < 4) ans = 2;
    else if(n < 7) ans = 3;
    else if(n < 11) ans = 4;
    else if(n < 16) ans = 5;
    else if(n < 22) ans = 6;
    else if(n < 29) ans = 7;
    else{
        ans = n / 7 + 3;
        if(n % 7 != 0) ans++;
    }
    cout << ans;
}