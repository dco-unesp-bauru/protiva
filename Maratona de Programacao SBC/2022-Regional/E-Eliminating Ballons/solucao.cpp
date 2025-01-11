#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

void solve(){
	int n;
	cin >> n;
	vector<int> b(n), h(1001001, 0);
	
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(h[b[i]] > 0){
			h[b[i]]--;
			h[b[i] - 1]++;
		}else{
			ans++;
			h[b[i] - 1]++;
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