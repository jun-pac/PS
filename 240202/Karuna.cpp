#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int MAXN = 101010;
 
struct node {
	ll s, l, r, x;
};
node operator+(node a, node b) {
	return {a.s + b.s, max(a.l, a.s + b.l), max(b.r, b.s + a.r), max(a.r + b.l, max(a.x, b.x))};
}
 
struct seg {
	node tree[4 * MAXN];
 
	void update(int a, ll v, int l, int r, int x) {
		if (l == r) {
			tree[x] = {v, v, v, v};
			return;
		}
		int m = (l + r) / 2;
		if (a <= m)
			update(a, v, l, m, 2 * x);
		else	
			update(a, v, m + 1, r, 2 * x + 1);
 
		tree[x] = tree[2 * x] + tree[2 * x + 1];
	}
	node query(int a, int b, int l, int r, int x) {
		if (a <= l && r <= b) return tree[x];
		int m = (l + r) / 2;
		if (b <= m)
			return query(a, b, l, m, 2 * x);
		else if (a > m)
			return query(a, b, m + 1, r, 2 * x + 1);
		else
			return query(a, b, l, m, 2 * x) + query(a, b, m + 1, r, 2 * x + 1);
	}
} t1;
 
int n, m, q;
vector<pair<int, int>> upd[MAXN];
vector<array<int, 3>> qry[MAXN];
 
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
 
		upd[l].push_back({i, x});
		upd[r + 1].push_back({i, 0});
	}
 
	cin >> q;
	for (int i = 0; i < q; i++) {
		int k, s, t;
		cin >> k >> s >> t;
 
		qry[k].push_back({s, t, i});
	}
 
	vector<ll> ans(q);
	for (int i = 1; i <= n; i++) {
		for (auto [x, v] : upd[i]) t1.update(x, v, 1, m, 1);
		for (auto [l, r, i] : qry[i]) ans[i] = t1.query(l, r, 1, m, 1).x;
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
}