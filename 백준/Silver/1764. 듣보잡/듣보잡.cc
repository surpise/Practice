#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    map<string, int> hear;
    vector<string> ans;
    string str;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        hear.insert({str, i});
    }

    for(int i = 0; i < m; i++){
        cin >> str;
        if(hear.find(str) != hear.end()) ans.push_back(str);
    }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
}