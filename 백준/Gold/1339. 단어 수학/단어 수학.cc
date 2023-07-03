#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){
    if(a.second > b.second) return true;
    else return false;
}

int main(){
    int n, tmp;
    string str[10];
    vector<pair<char, int>> vec(26);
    for(int i = 0; i < 26; i++){
        vec[i].first = 'A' + i;
        vec[i].second = 0;
    }

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        tmp = 1;
        for(int j = str[i].size() - 1; j >= 0; j--){
            vec[str[i][j] - 'A'].second += tmp;
            tmp *= 10;
        }
    }

    sort(vec.begin(), vec.end(), cmp);

    int alpha[26] = {0, }, num = 9;
    for(int i = 0; i < 10; i++){
        alpha[vec[i].first - 'A'] = num;
        num--;
    }

    long long ans = 0, t;
    for(int i = 0; i < n; i++){
        t = 0;
        for(int j = 0; j < str[i].size(); j++){
            t *= 10;
            t += alpha[str[i][j] - 'A'];
        }
        ans += t;
    }
    cout << ans;
}