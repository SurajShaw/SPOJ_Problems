/**
Input
1
6 5
3 1 7 4 2
2 1 3 1 1
1 2 2 1 8
2 2 1 5 3
2 1 4 4 4
5 2 7 5 1
Output
32

The problem is similar to Min Cost Path
Blog - https://www.geeksforgeeks.org/min-cost-path-dp-6/
*/
#include <bits/stdc++.h>
using namespace std;
int dp[110][110];
int ar[110][110];
const long long INF = 1e8;
int row, column;
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
int MAX(int a, int b, int c) {
	return max(a, max(b, c));
	//return(a>b?(a>c?a:c):(b>c?b:c));
}
int f(int a, int b) {
	if(a >= row || b >= column || a < 0 || b < 0) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	else 
		return dp[a][b] = ar[a][b] + MAX(f(a+1, b), f(a+1, b+1), f(a+1, b-1));
}
void solve() {
	int testcase;
	cin >> testcase;
	while(testcase--) {
		cin >> row >> column;
		
		for(int i=0; i<row; i++) {
			for(int j=0; j<column; j++) {
				cin >> ar[i][j];
			}
		}
		int m = 0;
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<column; i++) {
			m = max(m, f(0, i));
		}
		cout << m << endl;
	}
}
int main() {
  __fastio;
  solve();
  return 0;
}
