#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    float sum = 0;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    float ft = round(n * 0.15);
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = ft; i < n - ft; i++) sum += v[i];
    cout << round(sum / (n - (2 * ft))); 
}