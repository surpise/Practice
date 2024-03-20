#include <iostream>
#include <vector>

using namespace std;

int n;
int board[10][10], l[20], r[20], ans[2];

void init(){
  cin >> n;

  for(int r = 0; r < n; r++){
    for(int c = 0; c < n; c++) cin >> board[r][c];
  }
}

void search(int color, int row, int col, int bishop){
  if(col >= n){
    row++;
    if(col % 2 == 0) col = 1;
    else col = 0;
  }

  if(row >= n){
    if(bishop > ans[color]) ans[color] = bishop;
    return;
  }

  if(board[row][col] && !l[col - row + n - 1] && !r[row + col]){
    l[col - row + n - 1] = 1;
    r[row + col] = 1;

    search(color, row, col + 2, bishop + 1);

    l[col - row + n - 1] = 0;
    r[row + col] = 0;
  }

  search(color, row, col + 2, bishop);
}

int main(){
  init();

  search(0, 0, 0, 0);
  search(1, 0, 1, 0);

  cout << ans[0] + ans[1];
}