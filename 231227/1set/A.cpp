
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

vc<ll> sum[N];
priority_queue<pair<ll,pll>> pq;
ll cur_val[N];


void Solve(){
    ll x,k,n,val; 
    cin>>x>>k;
    rng(i,0,k-1){
        cin>>n;
        sum[i].resize(n);
        ll mx,mn;
        rng(j,0,n-1){
            cin>>val;
            sum[i][j]=(j==0?0LL:sum[i][j-1])+val;
            if(j==0) mx=val, mn=val;
            mn=min(mn,sum[i][j]);
            if(j==0 || sum[i][j]>mx){
                if(sum[i][j]>0){
                    pq.push({mn,{sum[i][j],i}});
                    //cout<<mn<<' '<<sum[i][j]<<'\n';
                }
            }
            mx=max(mx,sum[i][j]);
            
        }
    }
    while(!pq.empty()){
        if(pq.top().fi+x<0){
            break;
        }
        ll idx=pq.top().se.se;
        ll pl=pq.top().se.fi;
        if(pl>cur_val[idx]){
            x+=pl-cur_val[idx];
            cur_val[idx]=pl;
        }
        pq.pop();
    }
    cout<<x<<'\n';

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

