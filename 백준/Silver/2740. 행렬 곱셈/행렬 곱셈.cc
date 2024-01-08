#include <iostream>
#include <vector>

using namespace std;

void makeMatrix(int rows, int cols, vector<vector<int>> &matrix){
  matrix.resize(rows, vector<int>(cols));

  for(int xIdx = 0; xIdx < rows; xIdx++){

    for(int yIdx = 0; yIdx < cols; yIdx++){
      cin >> matrix[xIdx][yIdx];
    }
  }
}

int main(){
  int aRows, aCols;
  cin >> aRows >> aCols;

  vector<vector<int>> A;
  makeMatrix(aRows, aCols, A);

  int bRows, bCols;
  cin >> bRows >> bCols;

  vector<vector<int>> B;
  makeMatrix(bRows, bCols, B);

  for(int aRowIdx = 0; aRowIdx < aRows; aRowIdx++){
    
    for(int bColIdx = 0 ; bColIdx < bCols; bColIdx++){
      int sum = 0;

      for(int idx = 0; idx < aCols; idx++){
        sum += A[aRowIdx][idx] * B[idx][bColIdx];
      }

      cout << sum << " ";
    }
    cout << '\n';
  }
}