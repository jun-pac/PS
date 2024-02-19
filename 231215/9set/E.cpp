
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

map<pii,ll> DP;
ll cnt[30];
int digsum(int i){
    int res=0;
    while(i!=0){
        res+=i%10;
        i/=10;
    }
    return res;
}

ll DFS(int n, int dig){
    if(n==0 && dig==0) return 1;
    if(n==0 || dig==0) return 0;
    if(DP[{n,dig}]!=0) return DP[{n,dig}];    
    ll res=0;
    rng(i,0,min(dig,27)){
        if(i%10==n%10) res+=cnt[i]*DFS((n-i)/10,dig-i); 
    }   
    return DP[{n,dig}]=res;
}

void Solve(){
    int n;
    cin>>n;
    cout<<DFS(n,digsum(n))<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(i,0,9){
        rng(j,0,9){
            rng(k,0,9){
                cnt[i+j+k]++;
            }
        }
    }
    //rng(i,0,27) cout<<i<<' '<<cnt[i]<<'\n';
    while(t--){
        Solve();
    }
    return 0;
}
