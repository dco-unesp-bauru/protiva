#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

void solve(){
	int n, l, k;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	cin >> k >> l;

	vector<ll> pre(n+1, 0), suf(n+1, 0);
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i-1] + a[i-1];
	}
	for(int i = n - 1; i >= 0; --i){
		suf[i] = suf[i+1] + a[i];
	}

	ll ans = 0;
	ll base = pre[0] + suf[n - k + 0]; 
	ll sum = 0;
	multiset<ll> best, all;
	for(int i = 0; i < k; ++i){
		all.insert(b[n - k + i]);
	}
	//cout << *(prev(all.end())) << "\n";
	for(int i = 0; i < l; ++i){
		ll mx = *prev(all.end());
		sum += mx;
		best.insert(mx);

		all.erase(prev(all.end()));
	}

	ans = max(ans, base + sum);
	for(int i = 1; i <= k; ++i){
		base = pre[i] + suf[n - k + i]; 

		// remover item ( b[ind] )
		int ind = n - k + i - 1;
		auto it_all = all.find(b[ind]);
		if(it_all != all.end()){
			all.erase(it_all);
		}else{
			best.erase(b[ind]);
			sum -= b[ind];

			ll mx = *prev(all.end());
			sum += mx;
			best.insert(mx);
			all.erase(prev(all.end()));
		}

		// adicionar novo elemento b[i - 1] e verificar se a troca deve se efetuada
		all.insert(b[i - 1]);
		ll mx_all  = *prev(all.end());
		ll mn_best = *best.begin();
		if(mx_all > mn_best){ // troca deve ser feita
			sum -= mn_best;
			sum += mx_all;

			all.erase(prev(all.end()));
			best.erase(best.begin());

			best.insert(mx_all);
			all.insert(mn_best);
		}

		ans = max(ans, base + sum);
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