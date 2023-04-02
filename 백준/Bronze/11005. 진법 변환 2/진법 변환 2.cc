#include <iostream>
#include <string>
using namespace std;

int main(){
    string ans = "";
    int n, b, tmp;
    cin >> n >> b;

    while(n > 0){
        tmp = n % b;
        if(tmp >= 10) ans = (char)('A' + (tmp - 10)) + ans;
        else ans = to_string(tmp) + ans;
        n /= b;
    }
    cout << ans;
}