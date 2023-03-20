#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> v;
    map<string, int> strm;
    string str;

    for(int i = 0; i < n + m; i++){
        cin >> str;
        if(i < n) strm.insert({str, i});
        else v.push_back(str);
    }

    for(int i = 0; i < m; i++){
        if(strm.find(v[i]) != strm.end()) ans++;;
    }

    cout << ans;
}