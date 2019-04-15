/**
 * Tutorial on Segment Tree
 * https://cp-algorithms.com/data_structures/segment_tree.html
 * https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/
 *
 * Solution using segment tree, for SPOJ KGSS - Maximum Sum
 * Implementation of Segment Tree
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef pair<int, int> ii; 
typedef vector<ii> vii;
//vii tree[4*MAXN];
int ar[MAXN];
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
struct dual {
	int first; 
	int second;
};
dual tree[4*MAXN];//Array for Segment Tree
void build(int node, int start, int end) {
	if(start == end) {
		//When there is a single integer then it is only largest in the array
		//Second largest is 0 (phantom value)
		tree[node].first  = ar[start]; //Largest Number
		tree[node].second = 0;//Second Largest
	} else {
		//Find mid
		int mid = (start + end)/2;
		// Recurse on the left child
		build(2*node, start, mid);
		// Recurse on the right child
		build(2*node+1, mid+1, end);
		
		//Largest value in ar[x].first
		tree[node].first  = max(tree[2*node].first, tree[2*node+1].first);
		//Second Largest in ar[x].second
		tree[node].second = max(min(tree[2*node].first, tree[2*node+1].first), max(tree[2*node].second, tree[2*node+1].second));
	}
}
dual query(int node, int start, int end, int l, int r) {
	dual result;
	result.first = result.second = -1;
	if(start > r || end < l) 
		return result;
	
	if(l <= start && end <= r) 
		return tree[node];
	
	//Find mid
	int mid = (start+end)/2;
	//if the range is partially in and out, then recurse left and right child
	dual p1 = query(2*node, start, mid, l, r);
	dual p2 = query(2*node+1, mid+1, end, l, r);
	//If found then find largest and second largest
	//Largest
	result.first = max(p1.first, p2.first);
	//Second Largest
	result.second = max(min(p1.first, p2.first), max(p1.second, p2.second));
	
	return result;
}
void update(int node, int start, int end, int idx, int value) {
	if(start == end) {
		tree[node].first = value;
		tree[node].second = 0;
	} else {
		//Mid Value
		int mid = (start + end)/2;
		//if the index is on the left half then recurse on the left half
		//else the index is on the right half then recurse on the right half
		if(start <= idx && idx <= mid)
			update(2*node, start, mid, idx, value);
		else
			update(2*node+1, mid+1, end, idx, value);
		
		//Largest value in ar[x].first
		tree[node].first  = max(tree[2*node].first, tree[2*node+1].first);
		//Second Largest in ar[x].second
		tree[node].second = max(min(tree[2*node].first, tree[2*node+1].first), max(tree[2*node].second, tree[2*node+1].second));
	}
}
void solve() {
	int input; cin >> input;
	for(int i=0; i<input; i++) 
		cin >> ar[i];
	
	//building segment tree
	build(1, 0, input-1);
	int que; cin >> que;
	while(que--) {
		char type;
		int l, r;
		cin >> type >> l >> r;
		if(type == 'Q') {
			dual answer = query(1, 0, input-1, l-1, r-1);//1 based Indexing
			cout << answer.first + answer.second << endl;
		} else {
			update(1, 0, input-1, l-1, r);
		}
	}
}
int main() {
  __fastio;
  solve();
  return 0;
}
