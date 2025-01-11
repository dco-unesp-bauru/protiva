#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

ll exp(ll a, ll b, ll m)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    ll ans = exp(a, b/2, m);
    ll ret = ans * ans % m;
    if(b % 2 == 1)
        ret *= a % m;
    return ret % m;
}

const ll MOD = 998244353;
void solve(){
    int ok = true;
    for(int i = 0; i < 8; ++i){
        int x;
        cin >> x;
        if(x == 9) ok = false;
    }
    cout << (ok ? "S" : "F") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}