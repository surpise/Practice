#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, n, m;
    vector<pair<int, int>> vec;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> n >> m;
        vec.push_back({m, n});
    }
    sort(vec.begin(), vec.end());

    int cnt = 1;
    int t = vec[0].first;
    for(int i = 1; i < N; i++){
        if (vec[i].second >= t){
            cnt++;
            t = vec[i].first;
        }
    }
    cout << cnt;
}