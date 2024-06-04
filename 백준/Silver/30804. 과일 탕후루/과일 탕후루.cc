#include <iostream>

using namespace std;

int n;
int type[10], arr[200000];

int search(int left, int right, int cnt, int ans, int typeCnt){
    if(right >= n) return ans;

    if(type[arr[right]] == 0) typeCnt++;
    cnt++;
    type[arr[right]]++;

    while(typeCnt > 2){
        cnt--;
        type[arr[left]]--;
        if(type[arr[left]] == 0) typeCnt--;
        left++;
    }

    ans = max(ans, cnt);
    return search(left, right + 1, cnt, ans, typeCnt);
}

int main(){
    cin >> n;
    for(int idx = 0; idx < n; idx++) cin >> arr[idx];

    cout << search(0, 0, 0, 0, 0);
}