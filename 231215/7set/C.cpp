
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

ll datas[N], num[N];

ll gcd(ll x, ll y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    if(n==2){
        cout<<3<<'\n';
        return;
    }
    
    // n>=3
    sort(datas,datas+n);
    rng(i,0,n-2) num[i]=datas[i+1]-datas[0];
    
    //cout<<"FI "; rng(i,0,n-1) cout<<datas[i]<<' '; cout<<'\n';
    ll mn=gcd(num[0],num[1]); // non zero보장
    rng(i,0,n-2){
        mn=gcd(mn,num[i]);
    }
    // datas[n-1]이 가장 큼
    ll val=datas[n-1]-mn;
    for(int i=n-1; i>=0; i--){
        if(i==0) val=datas[i]-mn;
        if(datas[i]-mn!=datas[i-1]){
            val=datas[i]-mn;
            break;
        }
    }
    ll res=datas[n-1]-val;
    rng(i,0,n-2) res+=datas[n-1]-datas[i];
    cout<<res/mn<<'\n';
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

