#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
            else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    cout << arr[str1.size()][str2.size()];
}