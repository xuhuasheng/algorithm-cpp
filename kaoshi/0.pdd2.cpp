# include <bits/stdc++.h>
using namespace std;

const int N = 410;
int f[N*N], sz[N*N], mp[N][N], num[N][N];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0, 1}};

int find(int x) {
    if (f[x] != x) 
        return f[x]=find(f[x]);
    return x;
}

set<int> st;
int main() {
    int n, m;
    cin>>n>>m;
    int cnt = 0;
    int tot = 0;
    for(int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            f[++cnt] = cnt;
            sz[cnt] = 1;
            num[i][j] = cnt;
            cin >> mp[i][j];
            tot+= mp[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int d=0; d<4; d++) {
                int x = i+dir[d][0], y = j+dir[d][1];
                if (x<=0 || x>n || y<=0||y>m) continue;
                if (mp[x][y] == mp[i][j]) {
                    int fx = find(num[x][y]), fy = find(num[i][j]);
                    if (fx == fy) continue;
                    sz[fx] += sz[fy];
                    f[fy] = fx;
                }
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if (mp[i][j] == 1) continue;
            int tmp = 0;
            st.clear();
            for (int d=0; d<4; d++) {
                int x=i+dir[d][0], y=j+dir[d][1];
                if (x<=0||x>n||y<=0||y>m) continue;
                if (mp[x][y] == 1){
                    st.insert(find(num[x][y]));
                }
            }
            for (auto it = st.begin(); it != st.end(); it++) tmp += sz[*it];
            ans = max(ans, min(tmp+1, tot));
        }
    }
    cout<<ans<<endl;
}