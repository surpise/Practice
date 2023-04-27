#include <iostream>

using namespace std;

string arr[105][105];

string add(string str1, string str2){
    string res = "";
    int sum = 0, carry = 0, a, b;
    int sz = max(str1.size(), str2.size());
    int diff = sz - min(str1.size(), str2.size());
    int sz1 = str1.size() - 1, sz2 = str2.size() - 1;
    while(sz1 >= 0 || sz2 >= 0){
        a = (sz1 >= 0) ? str1[sz1] - '0' : 0;
        b = (sz2 >= 0) ? str2[sz2] - '0' : 0;
        sum = a + b;
        if(carry){
            sum += carry;
            carry = 0;
        }
        if(sum > 9){
            carry = sum / 10;
            sum %= 10;
        }
        res = (char)(sum + '0') + res;
        sz1--;
        sz2--;
    }

    if(carry) res = '1' + res;
    return res;
}

string combi(int n, int r){
    if(n == r || r == 0) return "1";
    if(arr[n][r] != "") return arr[n][r];
    return arr[n][r] = add(combi(n - 1, r - 1), combi(n - 1, r));
}

int main(){
    int N, M;
    cin >> N >> M;
    combi(N, M);
    cout << arr[N][M];
}