#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
const int N = 110, M = 210;
struct Edge
{
    int a, b, w;
    bool operator< (const Edge &t)const
    {
        return w < t.w;
    }
}e[M];

int p[N];
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T; cin >> T;
    
    while(T--)
    {
        int n, m, k; cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) p[i] = i;
        int cnt = 0;
        for(int i = 1; i <= m; i++)
        {
            int a, b, w; cin >> a >> b >> w;
            if(w > k) continue;
            cnt++;
            e[cnt] = {a, b, w};
        }
        sort(e + 1, e + 1 + cnt);
        int res = 0;
        for(int i = 1; i <= cnt; i++)
        {
            int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
            if (a != b) p[a] = b;
            else res += w;
        }
        int fa = find(1);
        int flag = 1;
        for(int i = 1; i <= n; i++) 
        {
            if(find(i) != fa) 
            {
                flag = 0;
                break;
            }
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    
}

