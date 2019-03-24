/**
For explanation refer to this - http://journeywithdp.blogspot.com/2018/07/way-to-solve-tiling-problems.html
*/
#include <bits/stdc++.h>
using namespace std;
long long F[1001];
long long G[1001];
long long H[1001];
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
void solve() {
	F[0] = G[0] = H[0] = F[1] = H[1] = 1;
	G[1] = 2;
	for(int i=2; i<=1000; i++) {
		F[i] = 2*G[i-2] + H[i-2] + F[i-2] + F[i-1];
		G[i] = F[i] + G[i-1];
		H[i] = F[i] + H[i-2];
	}
	int i = 1;
	int test; cin >> test;
	while(test--) {
		int input; cin >> input;
		cout << i++ << " " << F[input] << endl;
	}
}
int main() {
  __fastio;
  solve();
  return 0;
}//Subscribe! to PewDiePie.
