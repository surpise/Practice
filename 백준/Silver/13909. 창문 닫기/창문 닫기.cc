#include <iostream>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i * i <= n; i++) ans++;
    cout << ans;
}