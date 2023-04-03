#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, h;
    stack<int> st;
    for(int i = 0; i < moves.size(); i++){
        h = 0;
        while(h < board.size() && board[h][moves[i] - 1] == 0) h++;
        if(h < board.size()){
            if(!st.empty() && st.top() == board[h][moves[i] - 1]){
                st.pop();
                answer += 2;
            }
            else st.push(board[h][moves[i] - 1]);
            board[h][moves[i] - 1] = 0;
        }
    }
    return answer;
}