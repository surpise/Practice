#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, a, b;
    vector<pair<int, int>> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    int ans = 0, s = v[0].first, e = v[0].second;
    for(int i = 1; i < v.size(); i++){
        if(v[i].first >= s && v[i].first <= e){
            if(v[i].second >= e) e = v[i].second;
        }
        else if(v[i].first > e){
            ans += e - s;
            s = v[i].first;
            e = v[i].second;
        }
    }
    ans += e - s;
    cout << ans;
}