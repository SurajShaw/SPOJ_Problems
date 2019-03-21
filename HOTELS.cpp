#include <bits/stdc++.h>
using namespace std;
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
void solve() {
	int n, m;
	cin >> n >> m;
	int a[n];
	int l = 0, max = 0, sum = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<n; i++) {
		sum += a[i];
		while(sum > m) {
			sum -= a[l++];
		}
		if(max <= sum && sum <= m)
			max = sum;
	}
	cout << max;
}
int main() {
  __fastio;
  solve();
  return 0;
} 
