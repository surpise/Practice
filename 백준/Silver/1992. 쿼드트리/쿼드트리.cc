#include <iostream>
#include <string>
using namespace std;

int arr[64][64];
string coding(int n, int r, int c){
    string tmp = "";
    if(n == 1) {
        if(arr[0][0]) return "1";
        else return "0";
    }
    if(n == 2){
        for(int i = -1; i < 1; i++){
            for(int j = -1; j < 1; j++){
                tmp += to_string(arr[r + i][c + j]);
            }
        }
        if(tmp == "1111") return "1";
        else if(tmp == "0000") return "0";
        else {
            tmp = "(" + tmp + ")";
            return tmp;
        }
    }
    else{
        for(int i = 1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                tmp += coding(n / 2, r - ((n / 2) * i), c - ((n / 2) * j));
            }
        }
        if(tmp == "1111") return "1";
        else if(tmp == "0000") return "0";
        else{
            tmp = "(" + tmp + ")";
            return tmp;
        }
    }
} 

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++) {
            arr[i][j] = str[j] - '0';
        }
    }
    cout << coding(n, n - 1, n -1);
}