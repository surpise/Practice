#include<iostream>

using namespace std;

typedef pair<int, int> PII;

int n, ans;
PII home;
PII node[12];
bool visited[11];

int calcDist(PII a, PII b){
  int distX = abs(a.first - b.first);
  int distY = abs(a.second - b.second);
  return distX + distY;
}

void dfs(int cur, int sum, int cnt){
  if(cnt == n){
    int res = sum + calcDist(node[cur], home);
    if(res < ans) ans = res;
    return;
  }

  for(int idx = 1; idx <= n; idx++){
    if(!visited[idx]){
      visited[idx] = 1;
      dfs(idx, sum + calcDist(node[cur], node[idx]), cnt + 1);
      visited[idx] = 0;
    }
  }
}

void solution(int t){
  ans = 1e9;
  cin >> n;

  cin >> node[0].first >> node[0].second;

  cin >> home.first >> home.second;

  int _x, _y;
  for(int idx = 1; idx <= n; idx++){
    cin >> _x >> _y;
    node[idx] = {_x, _y};
  }
  
  dfs(0, 0, 0);

  cout << '#' << t << ' ' << ans << '\n';
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    solution(test_case);
	}
	return 0;
}