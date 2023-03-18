#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    map<string, string> adpw;
    string ad, pw;
    for(int i = 0; i < n; i++){
        cin >> ad >> pw;
        adpw.insert({ad, pw});
    }

    for(int i = 0; i < m; i++){
        cin >> ad;
        cout << adpw.find(ad)->second << '\n';
    }
}