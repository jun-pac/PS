
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

ll datas[2001];
ll gcd(ll x, ll y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}
int n;

int check(int val){
    int cnt=0;
    ll lcs=0;
    rng(i,0,n-1){
        if(val%datas[i]==0){
            cnt++;
            if(cnt==1) lcs=datas[i];
            else lcs=datas[i]*lcs/gcd(lcs,datas[i]);
        }
    }
    if(lcs!=val) return 0;
    else return cnt;
}

void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    bool flag=0;
    rng(i,0,n-1){
        if(datas[n-1]%datas[i]!=0) flag=1;
    }
    if(flag){
        cout<<n<<'\n';
    }
    else{
        // datas[n]의 약수들을 다 따져야 한다.
        int mx=0;
        rng(v,1,sqrt(datas[n-1])+1){
            if(datas[n-1]%v!=0) continue;
            if(datas[lower_bound(datas,datas+n,v)-datas]!=v){
                mx=max(mx,check(v));
            }
            if(datas[lower_bound(datas,datas+n,datas[n-1]/v)-datas]!=datas[n-1]/v){
                mx=max(mx,check(datas[n-1]/v));
            }
        }
        cout<<mx<<'\n';
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

