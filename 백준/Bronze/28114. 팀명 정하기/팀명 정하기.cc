#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b){
    if(a.first > b.first) return true;
    else return false;
}

int main(){
    int p, y;
    string s;
    int arr1[3];
    pair<int, string> arr2[3];
    for(int i = 0; i < 3; i++){
        cin >> p >> y >> s;
        arr1[i] = y % 100;
        arr2[i] = {p, s};
    }

    sort(&arr1[0], &arr1[3]);
    for(int i = 0; i < 3; i++) cout << arr1[i];
    cout << '\n';

    sort(&arr2[0], &arr2[3], cmp);
    for(int i = 0; i < 3; i++) cout << arr2[i].second[0];
}