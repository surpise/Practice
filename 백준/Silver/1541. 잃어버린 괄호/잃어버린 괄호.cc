#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;

    int ans = 0, tmp = 0, t = 0;
    bool m = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '+' || str[i] == '-'){
            tmp += stoi(str.substr(t, i - t));
            if(t == 0) {
                ans += tmp;
                tmp = 0;
            }
            else if(!m){
                ans += tmp;
                tmp = 0;
            }
            else if(str[i] == '-'){
                ans -= tmp; 
                tmp = 0;
            } 
            if (str[i] == '-') m = 1;
            t = i + 1;
        }
        else if(i == str.size() - 1){
            tmp += stoi(str.substr(t));
            m ? ans -= tmp : ans += tmp;
        }
    }
    cout << ans;
}