#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = board.size() * board.size();
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] == 1){
                for(int n = -1; n < 2; n++){
                    for(int m = -1; m < 2; m++){
                        if(i + n >= 0 && i + n < board.size()){
                            if(j + m >= 0 && j + m < board.size()){
                                if(board[i + n][j + m] != 1) {
                                    board[i + n][j + m] = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] == 1 || board[i][j] == -1) answer--;
        }
    }
    return answer;
}