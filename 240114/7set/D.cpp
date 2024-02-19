
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
ll INF=1000000000000000001LL;
ll cursz[N];
int cnt;
map<ll,ll> val;

ll get_val(ll idx){
    if(val[idx]!=0) return val[idx];
    int pos=upper_bound(cursz,cursz+cnt,idx)-cursz;
    //assert(pos!=0);
    //assert(val[cursz[pos]-1]==0);
    //cout<<"find : "<<idx<<' '<<cursz[pos-1]<<' '<<idx%cursz[pos-1]<<'\n';
    return get_val(idx%cursz[pos-1]);
}

void Solve(){
    int n,q;
    cin>>n>>q;
    ll cur=0;
    val.clear();
    cnt=0;
    bool flag=1;
    rng(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        if(a==1){
            if(flag && cur<=INF){
                val[cur]=b;
                cur++;
                cursz[cnt++]=cur;
            }
        }
        else{
            if(flag && cur<=INF/(b+1) && cur!=0){
                cur=cur*(b+1);
                cursz[cnt++]=cur;
            } 
            else flag=0;
        }
    }
    cursz[cnt++]=INF;

    //cout<<"lengs : "; rng(i,0,cnt-1) cout<<cursz[i]<<' ';cout<<endl;
    //for(auto ii : val) cout<<"("<<ii.fi<<' '<<ii.se<<")"<<' '; cout<<endl;

    rng(i,0,q-1){
        ll x;
        cin>>x;
        cout<<get_val(x-1)<<' ';
    }
    cout<<'\n';
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

