
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

vc<int> datas;


void Solve(){
    int n;
    datas.clear();
    cin>>n;
    int l=0, r=INF;
    rng(i,0,n-1){
        int a,x;
        cin>>a>>x;
        if(a==1) l=max(l,x);
        else if(a==2) r=min(r,x);
        else{
            datas.pb(x);
        }
    }
    sort(all(datas));
    if(l>r) cout<<0<<'\n';
    else{
int num=upper_bound(datas.begin(), datas.end(), r)-lower_bound(datas.begin(), datas.end(), l);
    cout<<r-l+1-num<<'\n';
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
