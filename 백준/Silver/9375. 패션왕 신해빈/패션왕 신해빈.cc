#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int t, n, ans;
    cin >> t;

    string cname, ctype;
    for(int test = 0; test < t; test++){
        cin >> n;
        map<string, int> closet;
        for(int i = 0; i < n; i++){
            cin >> cname >> ctype;
            if(closet.find(ctype) == closet.end()) closet.insert({ctype, 1});
            else closet.find(ctype)->second++;
        }

        ans = 1;
        for(auto e = closet.begin(); e != closet.end(); e++){
            ans *= e->second + 1;
        }
        cout << ans - 1 << '\n';
    }
}