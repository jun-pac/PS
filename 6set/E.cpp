
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)


vc<int> divs[N];
int datas[N];
bool is_data[N];
vc<ll> temp[N];
vc<pll> all_temp;


void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);

    fill(is_data,is_data+n,0);
    rng(i,0,n-1) is_data[datas[i]]=1;
    
    rng(i,0,m) temp[i].clear();
    all_temp.clear();


    rng(i,0,n-1){
        for(auto val: divs[datas[i]]) if(val<=m) temp[val].pb(datas[i]);
    }
    // rng(i,1,m){
    //     for(auto val: temp[i]) cout<<val<<' ';
    //     cout<<'\n';
    // }

    ll r=0;
    rng(i,1,m){
        if((int)temp[i].size()==0){
            cout<<-1<<'\n';
            return;
        }
        r=max(r,temp[i][0]);
        rng(j,0,(int)temp[i].size()-1){
            int next;
            if(j==(int)temp[i].size()-1) next=INF; 
            else next=temp[i][j+1];
            all_temp.pb({temp[i][j],next});
        }
    }

    sort(all(all_temp));
    int idx=0;
    ll mn=r-datas[0]; // r is value, not idx
    rng(l,1,n-1){
        while(idx<all_temp.size() && all_temp[idx].fi<datas[l]){
            r=max(r,all_temp[idx].se);
            idx++;
        }
        mn=min(mn,r-datas[l]);
    }
    cout<<mn<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;

    rng(i,1,100000){
        int j=1;
        while(i*j<=100000){
            divs[i*j].pb(i);
            j++;
        }
    }
    while(t--){
        Solve();
    }
    return 0;
}

