/**
Similar Problem - GNY07H
For explanation refer to this - http://journeywithdp.blogspot.com/2018/07/way-to-solve-tiling-problems.html
*/
#include <bits/stdc++.h>
using namespace std;
long long F[31];
long long G[31];
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
void solve() {
	F[0] = G[0] = 1;
	F[1] = G[1] = 0;
	for(int i=2; i<=30; i++) {
		F[i] = F[i-2] + 2*G[i-2];
		G[i] = F[i] + G[i-2];
	}
	while(true) {
		int input; cin >> input;
		if(input == -1)
			exit(0);
		cout << F[input] << endl;
	}
}
int main() {
  __fastio;
  solve();
  return 0;
} 
