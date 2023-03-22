#include <iostream>

using namespace std;

int arr[2187][2187];
int m, z, o;
char paper(int n, int row, int col){
    if(n == 3){
        int tmp, a = 0, b = 0, c = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j ++){
                tmp = arr[row - i][col - j];
                if(tmp == -1) a++;
                else if(tmp == 0) b++;
                else if(tmp == 1) c++;
            }
        }
        if(a == 9) return 'a';
        else if(b == 9) return 'b';
        else if(c == 9) return 'c';
        else{
            m += a;
            z += b;
            o += c;
            return 'z';
        }
    }
    else{
        int at = 0, bt = 0, ct = 0;
        char res;
        for(int i = (n / 3) * -2; i < 1; i += n / 3){
            for(int j = (n / 3) * -2; j < 1; j += n / 3){
                res = paper(n / 3, row + i, col + j);
                if(res == 'a') at++;
                else if(res == 'b') bt++;
                else if(res == 'c') ct++;
            }
        }
        if(at == 9) return 'a';
        else if(bt == 9) return 'b';
        else if(ct == 9) return 'c';
        else{
            m += at;
            z += bt;
            o += ct;
            return 'z';
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }

    char ans = paper(n, n - 1, n - 1);
    if(ans == 'a') m = 1;
    else if(ans == 'b') z = 1;
    else if(ans == 'c') o = 1;
    cout << m << '\n' << z << '\n' << o;
}