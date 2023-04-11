#include <iostream>

using namespace std;

int arr[500001], tmp[500001];
int n, k, cnt = 0;

void merge(int p, int q, int r){
    int i = p, j = q + 1, t = 1;
    while(i <= q && j <= r){
        if(arr[i] <= arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    while(i <= q) tmp[t++] = arr[i++];
    while(j <= r) tmp[t++] = arr[j++];
    i = p;
    t = 1;
    while(i <= r) {
        arr[i++] = tmp[t++];
        cnt++;
        if(cnt == k) cout << arr[i - 1];
    }
}

void merge_sort(int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q +1, r);
        merge(p, q, r);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    merge_sort(1, n);
    if(cnt < k) cout << -1;
}