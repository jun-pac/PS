
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

ll cnt(ll n, ll a, ll b){
    ll res=0;
    rng(i,0,b-1){
        if(a*i>n) break;
        if((n-a*i)%b==0){
            res+=(n-a*i)/(a*b)+1;
        }
    }
    return res;
}

void Solve(){
    ll n,x,a[3];
    cin>>n>>x; // n은 0일수가 있네
    rng(i,0,x-1) cin>>a[i];
    if(x==1){
        if(n%a[0]==0) cout<<1<<'\n';
        else cout<<0<<'\n';       
    }
    else if(x==2){
        cout<<cnt(n,a[0],a[1])<<'\n';
    }
    else{
        ll res=0;
        ll k=cnt(a[0]*a[1]*a[2],a[1],a[2])-1;
        rng(i,0,a[1]*a[2]-1){
            if(i*a[0]>n) break;
            // a[i]가 i, i+a[1]*a[2], .. 인 것들을 모두 고려해야 함.
            ll temp=cnt(n-i*a[0],a[1],a[2]);
            // temp + (temp-k) + (temp-2*k) + ... + (temp-n*k)
            ll nn=temp/k;
            res+=temp*(nn+1)-k*(nn*(nn+1))/2;
            //if(temp%k==0 && temp!=0) res++;
            //cout<<i<<' '<<temp<<' '<<k<<' '<<nn<<' '<<temp*(nn+1)-k*(nn*(nn+1))/2<<'\n';
        }
        cout<<res<<'\n';
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

