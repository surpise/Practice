#include <string>
#include <vector>

using namespace std;

bool visited[8];
int minP = 1001, answer = 0;

void search(int k, int depth, vector<vector<int>> vec){
    if(k < minP || depth >= vec.size()){
        answer = max(depth, answer);
        return;
    }
    
    for(int idx = 0; idx < vec.size(); idx++){
        if(visited[idx]) continue;
        
        if(k < vec[idx][0]) continue;
        
        visited[idx] = 1;
        search(k - vec[idx][1], depth + 1, vec);
        visited[idx] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    for(int idx = 0; idx < dungeons.size(); idx++){
        minP = min(dungeons[idx][0], minP);
    }

    search(k, 0, dungeons);
    
    return answer;
}