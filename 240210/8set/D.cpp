
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

int capa[N], datas[N];
int ans[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>capa[i];
    rng(i,0,m-1) cin>>datas[i];
    bool flag=1;
    
    int pos=upper_bound(datas,datas+m,capa[0])-datas; // capa보다 큰 것
    if(pos==0) flag=0;
    if(!flag){
        cout<<-1<<'\n';
        return;
    }
    pos--;
    ans[0]=pos;
    rng(i,1,n-1){
        pos=upper_bound(datas,datas+m,capa[i])-datas;
        pos--;
        if(datas[pos]<=capa[i-1]) flag=0;
        ans[i]=pos;
    }
    if(!flag){
        cout<<-1<<'\n';
        return;
    }
    cout<<n<<'\n';
    rng(i,0,n-1) cout<<ans[i]+1<<' ';cout<<'\n';
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

