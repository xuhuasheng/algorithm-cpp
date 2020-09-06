# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}

ll a[19];
ll bit(ll n) {
    ll ans = 0;
    while (n)
    {
        if (n%2 == 1) ans++;
        n >>= 1;
    }
    return ans;
}

int main() {
    ll t, n, m;
    t = 1;
    ll b[105];
    ll cas = 1;
    while (t--) {
        cin>>n>>m;
        ll ans = 0;
        for (ll i=0; i<m; i++)
            cin>>a[i];

        for(ll i=1; i<=m; i++) {
            ll num =0, sum = 0;
            for (ll k=0; k<(1<<m); k++) {
                if (bit(k)==i) {
                    ll op = 1;
                    for (ll j=0; j<m; j++) {
                        if ((1<<j) & k)
                            op = lcm(op, a[j]);
                    }
                    sum += n/op;
                }
            }
            if (i%2==0)
                ans -= sum;
            else
                ans += sum;
        }
    printf("%d\n", ans);
    }
return 0;
}
