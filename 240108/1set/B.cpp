
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

#define N 330
#define MOD 998244353
#define INF 1000000007 

ll as[N], bs[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    ll asum=0, bsum=0;
    rng(i,0,n-1) cin>>as[i];
    rng(i,0,m-1) cin>>bs[i];
    rng(i,0,n-1) asum+=as[i];
    rng(i,0,m-1) bsum+=bs[i];
    sort(as,as+n);
    sort(bs,bs+m);
    reverse(as,as+n);
    reverse(bs,bs+m);
    if(n==1 && m==1){
        if(k%2==0) cout<<min(as[0],bs[0])<<'\n';
        else cout<<max(as[0],bs[0])<<'\n';
    }
    else if(n==1){
        if(k%2==0) cout<<min(as[0],bs[m-1])<<'\n';
        else cout<<max(as[0],bs[0])<<'\n';
    }
    else if(m==1){
        if(k%2==0) cout<<asum+bsum-max(as[0],bs[0])<<'\n';
        else cout<<asum+bsum-min(as[n-1],bs[m-1])<<'\n';
    }
    else{
        if(as[0]<bs[m-1]){
            if(k%2==0) cout<<asum<<'\n';
            else cout<<asum-as[n-1]+bs[0]<<'\n';
        }
        else if(bs[0]<as[n-1]){
            if(k%2==0) cout<<asum-as[0]+bs[m-1]<<'\n';
            else cout<<asum<<'\n';
        }
        else{
            if(k%2==0) cout<<asum-as[0]-as[n-1]+min(as[0],bs[0])+min(as[n-1],bs[m-1])<<'\n';
            else cout<<asum-as[n-1]+bs[0]<<'\n';
        }
        
    }
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

