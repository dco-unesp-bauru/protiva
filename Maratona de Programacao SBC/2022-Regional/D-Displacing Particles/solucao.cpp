#include <bits/stdc++.h>
#include <map>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;
int x, y, n;

void solve(){
	int x, y, n;
	cin >> n >> x >> y;
	
	int a1 = __builtin_ctz(x);
	int a2 = __builtin_ctz(y);

	cout << n - 1 - max(a1, a2) << "\n";
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