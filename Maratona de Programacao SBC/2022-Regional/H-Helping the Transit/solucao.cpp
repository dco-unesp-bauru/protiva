#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

const int MAXN = 10001;
int n, m;
vector<int> order;
vector<int> vis(MAXN), id(MAXN);
vector<vector<int>> adj(MAXN), adj_rev(MAXN);
void dfs1(int v){
	vis[v] = true;
	for(int u: adj[v]){
		if(!vis[u]){
			dfs1(u);
		}
	}
	order.push_back(v);
}

void dfs2(int x, int comp){
	vis[x] = true;
	for(int u: adj_rev[x]){
		if(!vis[u]){
			dfs2(u, comp);
		}
	}
	id[x] = comp;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		//a--; b--;
		adj[a].push_back(b);
		adj_rev[b].push_back(a);
	}

	vis.assign(MAXN, false);
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs1(i);
		}
	}

	vis.assign(MAXN, false);
	reverse(order.begin(), order.end());
	int comps = 0;
	for(int v: order){
		if(!vis[v]){
			comps++;
			dfs2(v, comps);
		}
	}

	//std::cout << comps << '\n';
//
	//for (int i = 1; i <= n; i++) { std::cout << id[i] << " \n"[i == n]; }

	vector<vector<int>> ssc(comps + 1), ssc_t(comps + 1);
	for(int i = 1; i <= n; ++i){
		for(auto u: adj[i]){
			if(id[u] != id[i]){
				ssc[id[i]].push_back(id[u]);
				ssc_t[id[u]].push_back(id[i]);
			}
		}
	}

	int in = 0, out = 0;
	for(int i = 1; i <= comps; ++i){
		if(ssc[i].size() == 0) out++;
		if(ssc_t[i].size() == 0) in++;
	}
	if(comps == 1) 
		cout << "0\n";
	else
		cout << max(in, out) << "\n";
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