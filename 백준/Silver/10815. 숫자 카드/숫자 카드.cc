#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    set<int> have;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        have.insert(x);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(have.find(x) != have.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }
}