
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)

#define N 300030

string s;
int sum[N];
int lknot[N], rknot[N]; // 좌측, 우측방향으로 가장 가까운 knot의 위치

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n;
    cin>>s;
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+(s[i]=='*'?0:s[i]-'0');
    int last=-1;
    rng(i,0,n-1){
        if(s[i]=='*') last=i;
        lknot[i]=last;
    }
    last=n;
    gnr(i,n-1,0){
        if(s[i]=='*') last=i;
        rknot[i]=last;
    }

    cin>>q;
    rng(i,0,q-1){
        int s,e;
        cin>>s>>e;
        int l=rknot[s];
        int r=lknot[e];
        if(l>=r) cout<<0<<'\n';
        else cout<<sum[r]-(l==0?0:sum[l-1])<<'\n';
    }

    return 0;
}

