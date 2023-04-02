#include <iostream>
#include <string>
using namespace std;

int main(){
    string n;
    int b, ans = 0, tmp;
    cin >> n >> b;

    for(int i = 0; i < n.size(); i++){
        if(n[i] - 'A' >= 0) tmp = n[i] - 'A' + 10;
        else tmp = n[i] - '0';
        ans *= b;
        ans += tmp;
    }
    cout << ans;
}