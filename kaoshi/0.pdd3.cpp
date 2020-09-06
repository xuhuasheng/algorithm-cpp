# include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[25010];
struct cv {
    int c, v;
} a[210];

bool operator < (const cv a, const cv b) {
    return a.c < b.c;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf("%d%d", &a[i].c, &a[i].v);
    }
    sort(a+1, a+n+1);
    memset(dp, 128, sizeof(dp));
    dp[m] = 0;
    for (int i=1; i<n; i++) {
        int c=a[i].c, v=a[i].v;
        if (c<0)
            m -= c;
        if (c>0) {
            for (int j=0; j<=m-c; ++j)
                dp[j] = max(dp[j], dp[j+c]+v);
        }
        else {
            for (int j=m; j>=-c; j--) {
                dp[j] = max(dp[j], dp[j+c]+v);
            }
        }

    }
    int ans = 0;
    for (int i=0; i<=m; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans <<endl;
    return 0;
}