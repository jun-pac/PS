
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
#define INF 1000000007000000007 

ll datas[N], esum[N], osum[N];
void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    if(n%2==0){
        ll res=1;
        rng(i,0,n-1){
            if(i%2!=0) res=max(res,datas[i]-datas[i-1]);
        }
        cout<<res<<'\n';
        return;
    }
    ll res=INF;
    rng(i,0,n-1){
        if(i%2==0 && (i==0 || i==n-1 || datas[i-1]<datas[i]-1 || datas[i+1]>datas[i]+1)){
            ll temp=1;
            rng(j,0,n-1){
                if(j<i){
                    if(j%2==1) temp=max(temp,datas[j]-datas[j-1]);
                }
                else if(j>i){
                    if(j%2==0) temp=max(temp,datas[j]-datas[j-1]);
                }
            }
            res=min(res,temp);
        }
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

