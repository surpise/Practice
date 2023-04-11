#include <iostream>
using namespace std;

int cnt;
int recursion(string s, int l, int r, int cnt){
    if(l >= r) {
        cout << 1 << " " << cnt << '\n';
        return 1;
    }
    else if(s[l] != s[r]) {
        cout << 0 << " " << cnt << '\n';
        return 0;
    }
    else return recursion(s, l+1, r-1, cnt + 1);
}

int isPalindrome(string s){
    return recursion(s, 0, s.size()-1, 1);
}

int main(){
    int t;
    cin >> t;

    string str;
    for(int i = 0; i < t; i++){
        cin >> str;
        isPalindrome(str);
    }
}