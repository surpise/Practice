#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;

    string str;
    set<string> gomgom;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str == "ENTER") {
            ans += gomgom.size();
            gomgom.clear();
        }
        else gomgom.insert(str);
    }
    ans += gomgom.size();
    cout << ans;
}