#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  int value;
  vector<int> path;
};

void printAnswer(vector<int> vec){
  int calcCnt = vec.size();

  cout << calcCnt - 1 << '\n';

  for(int idx = 0; idx < calcCnt; idx++){
    cout << vec[idx] << " ";
  }
}

void bfs(int x){
  queue<Node> q;
  q.push({x, {x}});
  bool visited[1000001] = {0, };

  while(!q.empty()){
    int value = q.front().value;
    vector<int> prevValues = q.front().path;
    q.pop();

    if(value == 1){
      printAnswer(prevValues);
      return;
    }

    if(visited[value]) continue;
    
    visited[value] = 1;

    if(value % 3 == 0){
        vector<int> tmpPath = prevValues;
        tmpPath.push_back(value / 3);
        q.push({value / 3, tmpPath});
    }

    if(value % 2 == 0){
      vector<int> tmpPath = prevValues;
      tmpPath.push_back(value / 2);
      q.push({value / 2, tmpPath});
    }

    vector<int> tmpPath = prevValues;
    tmpPath.push_back(value - 1);
    q.push({value - 1, tmpPath});
  }
}

int main(){
  int x;
  cin >> x;

  bfs(x);
}