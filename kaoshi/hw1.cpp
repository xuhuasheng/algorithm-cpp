#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> idx;
unordered_map<int, string> udx;
const int N = 1e5 + 233;
int w[N];
bool cmp(const int a, const int b){
    string x = udx[a], y = udx[b];
    if(w[a] == w[b]) return x < y;
    return w[a] > w[b]; 
} 
vector<int> son[N];
set<int> st[N];
void dfs(int x)
{
    for(int i = 0; i < son[x].size(); i++)
    {
        int y = son[x][i];
        dfs(y);
        w[x] += w[y];
    }
    sort(son[x].begin(), son[x].end(), cmp);
}
void out(int x, int p)
{
    if(x != 0)
    {
        for(int i = 0; i < p; i++) printf("-");
        string name = udx[x]; int num = w[x];
        printf("%s<%d>\n", name.c_str(), num);
    }
    for(int i = 0; i < son[x].size(); i++)
    {
        int y = son[x][i];
        out(y, p + 1);
    }
    
}
int main() {
    // 把标准输入流重定向到文件(默认是键盘输入缓冲区)
    freopen("0.inputfile.txt", "r", stdin);

    string ts;
    int cnt = 0;
    while(cin >> ts)
    {
        if(ts == "performance") continue;
        if(ts == "organization") break;
        // 替换成空格
        for (char &x: ts) {
            if(x == ',') {
                x = ' ';
            }
        }
        string name = ""; int num = 0;
        stringstream ss(ts);
        ss >> name; ss >> num;

        if(!idx.count(name)) {
            idx[name] = ++cnt; 
            udx[cnt] = name;
        }
        w[idx[name]] = num;
    }
    string s1, s2, s3;
    while(cin >> ts)
    {
        if(ts == "eof") break;
        for (char &x: ts) if(x == ',') x = ' ';
        stringstream ss(ts);
        ss >> s1 >> s2 >> s3;
        int tmp = 0;
        if(!idx.count(s1)) {
            idx[s1] = ++cnt;
            udx[cnt] = s1;
        }
        tmp = idx[s1];
        if(st[0].find(tmp) == st[0].end()) {
            son[0].push_back(tmp);
            st[0].insert(tmp);
        }
        
        if(!idx.count(s2)) {
            idx[s2] = ++cnt;
            udx[cnt] = s2;
        } 
        tmp = idx[s2];
        if(st[idx[s1]].find(tmp) == st[idx[s1]].end()) {
            son[idx[s1]].push_back(tmp);
            st[idx[s1]].insert(tmp);
        }
        
        if(!idx.count(s3)) {
            idx[s3] = ++cnt;
            udx[cnt] = s3;
        }
        tmp = idx[s3];
        if(st[idx[s2]].find(tmp) == st[idx[s2]].end()) {
            son[idx[s2]].push_back(tmp);
            st[idx[s2]].insert(tmp);
        }
    }


    dfs(0);
    out(0, -1);

}


// performance
// Adam,125
// Andy,110
// Bill,92
// Evan,154

// organization
// Aaron,Abel,Adam
// Aaron,Abel,Andy
// Aaron,Jone,Bill
// Aaron,Jone,Evan
// eof