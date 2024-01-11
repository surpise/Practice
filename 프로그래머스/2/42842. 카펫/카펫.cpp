#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int half = brown / 2;
    for(int row = half - 1; row >= 1; row--){
        int col = half - row + 2;
        
        if(brown + yellow == row * col){
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }
    
    return answer;
}