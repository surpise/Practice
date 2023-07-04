#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x, zero = 0;
    vector<int> v1, v2;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > 0) v1.push_back(x);
        else if(x == 0) zero++;
        else v2.push_back(x);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());
    
    int ans = 0;
    for(int i = 0; i < v1.size(); i++){
        if(i == v1.size() - 1) ans += v1[i];
        else if(v1[i] * v1[i + 1] > v1[i] + v1[i + 1]){
            ans += v1[i] * v1[i + 1];
            i++;
        }
        else ans += v1[i];
    }
    for(int i = 0; i < v2.size(); i += 2){
        if(i == v2.size() - 1) {
            if(zero > 0) zero--;
            else ans += v2[i]; 
        }
        else ans += v2[i] * v2[i + 1];
    }
    cout << ans;
}