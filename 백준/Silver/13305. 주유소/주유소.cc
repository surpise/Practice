#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    unsigned long long n, distance, cost, ans = 0;
    vector<unsigned long long> d, c;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> distance;
        d.push_back(distance);
    }

    for(int i = 0; i < n; i++){
        cin >> cost;
        c.push_back(cost);
    }
    unsigned long long int m = c[0];
    for(int i = 0; i < n - 1; i++){
        if(c[i] < m) m = c[i];
        ans += m * d[i];
    }
    cout << ans;
}