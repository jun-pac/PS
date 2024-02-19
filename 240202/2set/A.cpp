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

pii datas[N];

void Solve(){
    int n;
    cin>>n;
    int cur,sum=0,alice;;
    rng(i,0,n-1){
        int x;
        cin>>x;
        if(i==0) alice=x;
        sum+=x;
        datas[i]={x,i};
    }
    sort(datas,datas+n);
    
    cur=alice;
    vc<int> ans;
    
    ans.pb(0);
    rng(i,0,n-1){
        if(datas[i].se==0) continue;
        if(datas[i].fi*2<=alice){
            cur+=datas[i].fi;
            ans.pb(datas[i].se);
        }
    }
    if(cur*2>sum){
        cout<<ans.size()<<'\n';
        rng(i,0,(int)ans.size()-1) cout<<ans[i]+1<<' ';
        cout<<'\n';        
    }
    else cout<<0<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

