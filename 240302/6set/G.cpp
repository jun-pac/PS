
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int ans[N];
vc<array<int,3>> pos;

int check(int n, int m){
    int res=0;
    int f1=1, f2=1, f3=1, f4=1;
    rng(i,0,(int)pos.size()-1){
        if((pos[i][0]+pos[i][1]/2)%2!=pos[i][2]) f1=0;
        if((pos[i][0]+1+pos[i][1]/2)%2!=pos[i][2]) f2=0;
        if((pos[i][0]+(pos[i][1]+1)/2)%2!=pos[i][2]) f3=0;
        if((pos[i][0]+1+(pos[i][1]+1)/2)%2!=pos[i][2]) f4=0;
    }   
    res=f1+f2+f3+f4;
    f1=1, f2=1, f3=1, f4=1;
    rng(i,0,(int)pos.size()-1){
        if((pos[i][1]+pos[i][0]/2)%2!=pos[i][2]) f1=0;
        if((pos[i][1]+1+pos[i][0]/2)%2!=pos[i][2]) f2=0;
        if((pos[i][1]+(pos[i][0]+1)/2)%2!=pos[i][2]) f3=0;
        if((pos[i][1]+1+(pos[i][0]+1)/2)%2!=pos[i][2]) f4=0;
    }  
    res+=f1+f2+f3+f4;
    return res;
}

void Solve(){
    int n,m,k;
    cin>>n>>m>>k;
    pos.clear();
    rng(i,0,k-1){
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        a--, b--;
        int val=(s[0]=='c'?1:0);
        bool flag=1;
        rng(j,0,(int)pos.size()-1) if(a%4==pos[j][0]%4 && b%4==pos[j][1]%4 && val==pos[j][2]) flag=0;
        if(flag) pos.pb({a,b,val});
        ans[i]=check(n,m);
    }
    cout<<8<<'\n';
    rng(i,0,k-1) cout<<ans[i]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

