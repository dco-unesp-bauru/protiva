#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

const int MAXN = 2025;
bool mat[MAXN][MAXN];

void solve(){
	memset(mat, 0, sizeof(mat));
	int n, fx, fy;
	cin >> n;
	cin >> fx >> fy;

	for(int i = 1; i <= n; ++i){
		int x, y;
		cin >> x >> y;

		if(x == fx){
			int mn = min(y, fy);
			int mx = max(y, fy);
			for(int j = 2 * mn - 1; j <= 2 * mx - 1; ++j){
				mat[j][2 * x - 1] = 1;	
			}
		}else if(y == fy){
			int mn = min(x, fx);
			int mx = max(x, fx);
			for(int j = 2 * mn - 1; j <= 2 * mx - 1; ++j){
				mat[2 * y - 1][j] = 1;	
			}
		}

		fx = x;
		fy = y;
	}
	
	auto dfs = [&](auto &&self, int i, int j, int& val) {
    	static int dx[] = {0, 0, 1, -1};
		static int dy[] = {1, -1, 0, 0};
		if(mat[j][i] == 1) return 0;

		mat[j][i] = 1;
		if(j % 2 == 0 && i % 2 == 0) val++;
		for(int k = 0; k < 4; ++k){
			if(i + dx[k] >= 0 && i + dx[k] < MAXN && j + dy[k] >= 0 && j + dy[k] < MAXN){
				self(self, i + dx[k], j + dy[k], val);
			}
		}
		return val;
    };

	int ans = 0;
	dfs(dfs, 0, 0, ans); ans = 0;
	for(int i = 0; i < MAXN; ++i){
		for(int j = 0; j < MAXN; ++j){
			if(mat[j][i] != 1){
				int val = 0;
				dfs(dfs, i, j, val);
				ans = max(ans, val);
			}
		}
	}
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tt = 1;
	//freopen("time.in", "r", stdin);
	//freopen("time.out", "w", stdout);
	//cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}