#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second > b.second) return true;
    else if(a.second == b.second){
        if(a.first.size() > b.first.size()) return true;
        else if(a.first.size() == b.first.size()){
            if(a.first < b.first) return true;
        }
    }
    return false;
}

int main(){
    cin.tie();
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string str;
    map<string, int> dic;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str.size() < m) continue;
        if(dic.find(str) != dic.end()) dic.find(str) -> second++;
        else dic.insert({str, 0});
    }

    vector<pair<string, int>> v;
    for(auto e = dic.begin(); e != dic.end(); e++) v.push_back(*e);
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) cout << v[i].first << '\n';
}