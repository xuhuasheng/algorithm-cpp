# include <bits/stdc++.h>
using namespace std;

int n;
int func(int x, int y) {
    double mid = (n+1)/2.0;
    if (x==mid || y==mid || x == y || x+y==n+1)
        return 0;
    if (x<mid && y>mid && x+y < n+1)
        return 1;
    if (x<mid && y<mid && x<y)
        return 2;
    if (x < mid && y<mid && x>y)
        return 3;
    if (x>mid && y<mid && x+y <n+1)
        return 4;
    if (x>mid && y<mid && x+y>n+1)
        return 5;
    if (x>mid && y>mid && x>y)
        return 6;
    if (x>mid && y > mid && x<y)
        return 7;
    if (x<mid && y>mid && x+y>n+1)
        return 8;
}
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            printf("%d ", func(i, j));
        }
        printf("\n");
    }
}