#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<pair<int, int>> v;
    long long a, b, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a > b) v.push_back({b, a});
    }
    if(v.size()){
        sort(v.begin(), v.end());
        long long s = v[0].first, e = v[0].second;
        for(int i = 1; i < v.size(); i++){
            if(v[i].first <= e && v[i].first >= s){
                if(v[i].second > e) e = v[i].second;
            }
            else if(v[i].first > e){
                ans += e - s;
                s = v[i].first;
                e = v[i].second;
            }
        }
        ans += e - s;
    }
    cout << m + (ans * 2);
}