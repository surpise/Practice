#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> a;
    set<int> b;
    int n, m, x, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n + m; i++) {
        cin >> x;
        if(i < n) a.insert(x);
        else b.insert(x);
    }
    for(auto e = a.begin(); e != a.end(); e++){
        if(b.find(*e) == b.end()) ans++;
    }
    for(auto e = b.begin(); e != b.end(); e++){
        if(a.find(*e) == a.end()) ans++;
    }
    cout << ans;
}