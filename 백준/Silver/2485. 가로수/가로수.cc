#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, x;
    vector<int> v, v2;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 1; i < n; i++) v2.push_back(v[i] - v[i - 1]);
    
    int big, small = v2[0], t;
    for(int i = 1; i < v2.size(); i++){
        if(v2[i] > small) big = v2[i];
        else{
            big = small;
            small = v2[i];
        }
        while(big % small != 0){
            t = big % small;
            big = small;
            small = t;
        }
    }

    int res = 0;
    for(int i = 0; i < v2.size(); i++) res += (v2[i] - small) / small;
    
    cout << res;
}