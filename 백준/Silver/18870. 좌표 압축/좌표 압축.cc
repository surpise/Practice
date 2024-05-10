#include <stdio.h>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n, x = 0, idx = 0;
    scanf(" %d", &n);
    pair<int, int>* arr = new pair<int, int>[n];
    for(int i = 0; i < n; i++) 
    {
        scanf(" %d", &arr[i].first);
        arr[i].second = i;
    }  
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
    {
        int tmp = arr[i].first;
        arr[i].first = x;
        if((i < n - 1) && (tmp != arr[i + 1].first)) x++;
    }
    sort(arr, arr + n, comp);
    for(int i = 0; i < n; i++) printf("%d ", arr[i].first);
    delete[] arr;
}