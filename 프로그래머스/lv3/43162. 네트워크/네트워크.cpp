#include <string>
#include <vector>
#include <iostream>
using namespace std;

int com[200][200];
bool v[200];
int sz;

void dfs(int num){
    if(!v[num]){
        v[num] = 1;
        for(int i = 0; i < sz; i++){
            if(com[num][i])dfs(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    sz = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            com[i][j] = computers[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        if(!v[i]){
            dfs(i);
            answer++;
        }
    }
    return answer;
}