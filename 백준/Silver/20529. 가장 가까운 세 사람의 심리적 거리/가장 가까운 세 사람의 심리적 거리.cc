#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int diff(string s1, string s2){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        if(s1[i] != s2[i]) cnt++;
    }
    return cnt;
}

int main(){
    int t, n, ans, tmp;
    string str;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> n;
        vector<string> v;
        ans = 12;
        for(int i = 0; i < n; i++){
            cin >> str;
            v.push_back(str);
        }
        for(int a = 0; a < v.size() - 2; a++){
            for(int b = a + 1; b < v.size() - 1; b++){
                for(int c = b + 1; c < v.size(); c++){
                    tmp = diff(v[a], v[b]) + diff(v[b], v[c]) + diff(v[a], v[c]);
                    if(tmp < ans) ans = tmp;
                    if (ans == 0) break;
                }
                if(ans == 0) break;
            }
            if(ans == 0) break;
        }
        cout << ans << '\n';
    }
}