
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

string s;

void Solve(){
    int n;
    int cnt=0;
    int dir=1;
    cin>>n;
    cin>>s;
    int mn=0, mx=0;
    int last=0;
    rng(i,1,n-1){
        if(s[i]!=s[i-1]){
            int l=i-last;
            if(l%2==0){
                cnt=cnt+dir;
                mn=min(mn,cnt);
                mx=max(mx,cnt);
                cnt=cnt-dir;
                dir*=-1;
            }
            else{
                cnt=cnt+dir;
                mn=min(mn,cnt);
                mx=max(mx,cnt);
            }
            last=i;
        }
    }    
    int l=n-last;
    if(l%2==0){
        cnt=cnt+dir;
        mn=min(mn,cnt);
        mx=max(mx,cnt);
        cnt=cnt-dir;
        dir*=-1;
    }
    else{
        cnt=cnt+dir;
        mn=min(mn,cnt);
        mx=max(mx,cnt);
    }
    cout<<mx-mn<<'\n';
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

