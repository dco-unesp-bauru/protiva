#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

void solve(){
	int n, c;
	cin >> n >> c;
	map<string, int> values;

	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;

		for(int j = 0; j < c; ++j){
			if(s[j] == '*'){
				for(int k = 0; k < 26; ++k){
					s[j] = 'a' + k;
					values[s]++;
				}
				break;
			}	
		}
	}

	string ans;
	int r = 0;
	for(auto [p, m]: values){
		if(m > r){
			r = m;
			ans = p;
		}
	}
	cout << ans << " " << r << "\n";
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