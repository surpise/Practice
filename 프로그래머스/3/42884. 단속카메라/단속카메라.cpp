#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[1] == v2[1]) return v1[0] < v2[0];
    else return v1[1] <v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int pos = routes[0][1];
    answer++;
    for(int idx = 0; idx < routes.size(); idx++){
        if(routes[idx][0] > pos){
            answer++;
            pos = routes[idx][1];
        }
    }
    
    return answer;
}