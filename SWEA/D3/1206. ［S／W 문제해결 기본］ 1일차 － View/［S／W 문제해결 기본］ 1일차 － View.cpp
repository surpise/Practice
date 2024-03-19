#include<iostream>
#include <algorithm>

using namespace std;

void solution(int t){
  int n;
  cin >> n;
  
  int arr[1000] = {0, };
  for(int idx = 0; idx < n; idx++) cin >> arr[idx];

  int sum = 0;
  for(int idx = 2; idx < n - 2; idx++){
    int nearHighest = max({arr[idx - 2], arr[idx - 1], arr[idx + 1], arr[idx + 2]});

    if(arr[idx] - nearHighest > 0) sum += arr[idx] - nearHighest;
  }

  cout << '#' << t << ' ' << sum << '\n';
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case) solution(test_case);
	
	return 0;
}