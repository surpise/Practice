#include <iostream>
using namespace std;

int main()
{
    int N, t, ans = 0;
    cin >> N;

    if(N > 20)
    {
        t = (N % 10) + 10;
        ans += (N - t) / 5;
        N = t;
    }
    
    if(((N % 19 != 4) && (N % 19 > 2)) || (N % 19 == 0))
    {
        ans += (N / 19) * 5;
        N = N % 19;
    }
    if(((N % 15 != 4) && (N % 15 > 2)) || (N % 15 == 0))
    {
        ans += (N / 15) * 3;
        N = N % 15;
    }
    if(((N % 12 != 4) && (N % 12 > 2)) || (N % 12 == 0))
    {
        ans += (N / 12) * 4;
        N = N % 12;
    }
    if(((N % 8 != 4) && (N % 8 > 2)) || (N % 8 == 0))
    {
        ans += (N / 8) * 2;
        N = N % 8;
    }
    if(((N % 5 != 4) && (N % 5 > 2)) || (N % 5 == 0))
    {
        ans += (N / 5);
        N = N % 5;
    }
    if(N % 3 == 0)
    {
        ans += (N / 3);
        N = N % 3;
    }
    
    if(N == 0) cout << ans;
    else cout << "-1";
}