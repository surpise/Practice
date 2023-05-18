#include <iostream>

using namespace std;

int main(){
    string str, ans;
    int n, a, b;
    int alpha[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    cin >> n;
    for(int i = 0; i < n; i++){
        ans = "YES";
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            if(str[j] < 'a') a = alpha[str[j] - 'A'];
            else a = alpha[str[j] - 'a'];
            if(str[str.size() - j - 1] < 'a') b = alpha[str[str.size() - j - 1] - 'A'];
            else b = alpha[str[str.size() - j - 1] - 'a'];

            if(a != b){
                ans = "NO";
                break;
            }
        }
        cout << ans <<'\n';
    }
}