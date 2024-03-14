#include <iostream>

using namespace std;

int arr[21][21][21];

int solution(int a, int b, int c){
  if(a <= 0 || b <= 0 || c <= 0) return 1;

  else if(a > 20 || b > 20 || c > 20) return solution(20, 20, 20);

  else if(arr[a][b][c]) return arr[a][b][c];

  else if(a < b && b < c) {
    arr[a][b][c] = solution(a, b, c - 1) + solution(a, b - 1, c - 1) - solution(a, b - 1, c);
    return arr[a][b][c];
  }

  else{
    arr[a][b][c] = solution(a - 1, b , c) + solution(a - 1, b - 1, c) + solution(a - 1, b, c - 1) - solution(a - 1, b - 1, c - 1);
    return arr[a][b][c];
  }
}

int main (){
  int a, b, c;

  while(1){
    cin >> a >> b >> c;

    if(a == -1 && b == -1 && c == -1) break;

    cout << "w(" << a << ", " << b << ", " << c << ") = " << solution(a, b, c) << '\n';
  }
}