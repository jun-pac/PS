
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

ll ls[N], rs[N], cs[N];
pll pos[2*N];
ll sz[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>ls[i];
    rng(i,0,n-1) cin>>rs[i];
    rng(i,0,n-1) cin>>cs[i];
    rng(i,0,n-1) pos[i]={ls[i],1};
    rng(i,0,n-1) pos[i+n]={rs[i],-1};
    sort(pos,pos+2*n);
    sort(cs,cs+n);
    stack<ll> st;
    int cnt=0;
    rng(i,0,2*n-1){
        if(pos[i].se==1) st.push(pos[i].fi);
        else{
            sz[cnt++]=pos[i].fi-st.top();
            st.pop();
        }
    }
    sort(sz,sz+n);
    ll res=0;
    rng(i,0,n-1){
        res+=sz[i]*cs[n-1-i];
    }
    cout<<res<<'\n';
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

