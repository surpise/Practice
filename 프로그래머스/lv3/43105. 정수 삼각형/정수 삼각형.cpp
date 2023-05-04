#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[501][501];
int solution(vector<vector<int>> triangle) {
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            arr[i + 1][j + 1] = triangle[i][j];
            arr[i + 1][j + 1] += max(arr[i][j + 1], arr[i][j]);
        }
    }

    int answer = 0;
    for(int i = 1; i <= triangle[triangle.size() - 1].size(); i++){
        if(arr[triangle.size()][i] > answer) answer = arr[triangle.size()][i];
    }
    return answer;
}