
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

int datas[N];
int num[100];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    fill(num,num+100,0);
    rng(u,0,30){
        int cnt=0;
        rng(i,0,n-1) if(datas[i]&(1<<u)) cnt++;
        num[u]=n-cnt;
    }
    // rng(i,0,30){
    //     cout<<i<<' '<<num[i]<<'\n';
    // }
    gnr(u,30,0){
        if(k>=num[u]){
            rng(i,0,n-1) datas[i]=(datas[i]|(1<<u));
            k-=num[u];
        }
    }
    int res=datas[0];
    rng(i,0,n-1) res=(res&datas[i]);
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

