#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, c, x;
    cin >> n >> c;

    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int left = 1, right = v.back() - v.front(), mid;
    int prev_house, cnt, ans = 0;
    while(left <= right){
        mid = (left + right) / 2;
        prev_house = v[0];
        cnt = 1;
        for(int i = 1; i < n; i++){
            if(v[i] - prev_house >= mid){
                cnt++;
                prev_house = v[i];
            }
        }

        if(cnt >= c){
            ans = max(mid, ans);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;
}