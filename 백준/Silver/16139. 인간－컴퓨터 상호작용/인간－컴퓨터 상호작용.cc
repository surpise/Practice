#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string str;
    vector<int> v[26];

    cin >> str;
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < 26; j++){
            if(i == 0){
                if(j == str[i] - 'a'){
                    v[j].push_back(1);
                }
                else{
                    v[j].push_back(0);
                }
            }
            else{
                if(j == str[i] - 'a'){
                    v[j].push_back(v[j][i - 1] + 1);
                }
                else{
                    v[j].push_back(v[j][i - 1]);
                }
            }
        }
    }
    
    int n, l, r, t;
    char a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> l >> r;
        t = a - 'a';
        if(l == 0) cout << v[t][r] << '\n';
        else cout << v[t][r] - v[t][l - 1] << '\n';
    }
}