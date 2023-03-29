#include <iostream>
#include <string>
using namespace std;

int arr[101];
int main(){
    int n;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        cout << str[0] << str[str.size() - 1] << '\n';
    }
}