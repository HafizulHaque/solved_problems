// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define N 100001
ll val[N], addVal[N];

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int t, n, q, a, b, _case = 1;
    char ch;
    scanf("%d\n", &t);
    addVal[0] = 0;
    while(t--){
        scanf("%d%d\n", &n, &q);
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &val[i]);
            val[i] %= MOD;
            addVal[i] = val[i];
            addVal[i] += addVal[i-1];
            addVal[i] %= MOD;
        }
        scanf("\n");
        printf("Case %d\n", _case++);
        for(int i = 1; i <= q; ++i){
            scanf("%c%d%d\n", &ch, &a, &b);
            if(ch=='+') printf("%lld\n", (addVal[b]-addVal[a-1]+MOD)%MOD);
            else if(ch=='-') printf("%lld\n", (val[a]-val[b]+MOD)%MOD);
        }
    }
    return 0;
}
