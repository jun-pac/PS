
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

int datas[300];

void Solve(){
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    datas[0]=0;
    rng(i,0,n-1) cin>>datas[i+1];
    int cur=k;
    if(l<=cur && cur<=r){
        cout<<0<<"\n";
        return;
    }
    rng(i,1,n){
        if(cur<l) cur=cur+(datas[i]-datas[i-1]);
        else cur=cur-(datas[i]-datas[i-1]);
        if(l<=cur && cur<=r){
            cout<<datas[i]<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
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

