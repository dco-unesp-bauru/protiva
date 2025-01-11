#include bitsstdc++.h
using namespace std;

using ll = unsigned long long;

ll exp(ll a, ll b, ll m)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    ll ans = exp(a, b2, m);
    ll ret = ans  ans % m;
    if(b % 2 == 1)
        ret = a % m;
    return ret % m;
}

const ll MOD = 998244353;
void solve(){
    int n, x;
    cin  n;

    vectorint cartas(14, 0);
    int J = 0, M = 0;
    for(int i = 0; i  2; ++i){
        cin  x;
        J += min(x, 10);
        cartas[x]++;
    }
    for(int i = 0; i  2; ++i){
        cin  x;
        M += min(x, 10);
        cartas[x]++;
    }
    for(int i = 0; i  n; ++i){
        cin  x;
        cartas[x]++;
        M += min(x, 10);
        J += min(x, 10);
    }

    int a1 = 23 - M;
    if(a1  10){
        if(cartas[a1] = 4) a1 = -1;
    }else if(a1  10){
        a1 = -1;
    }

    int a2 = 23 - J + 1;
    if(a2  10) a2 = -1;
    else{
        while(cartas[a2] = 4){
            a2++;
        }

        if(M + a2  23) a2 = -1;
    }

    if(a1 == -1 && a2 == -1){
        cout  -1n;
    }else if(a1 != -1 && a2 == -1){
        cout  a1  n;
    }else if(a1 == -1 && a2 != -1){
        cout  a2  n;
    }else{
        cout  min(min(a1, a2), 10)  n;
    }
}

int main(){
    iossync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin  tt;
    while(tt--){
        solve();
    }
    return 0;
}