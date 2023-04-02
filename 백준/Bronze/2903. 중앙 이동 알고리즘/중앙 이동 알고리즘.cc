#include <iostream>

using namespace std;

int main(){
    int n;
    long long ans = 2;
    cin >> n;

    for(int i = 0; i < n; i++) ans += ans - 1;
    cout << ans * ans;
}