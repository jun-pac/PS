
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
#define MAX_DIGIT 60

random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll a[N], b[N];
set<pll> aset, bset;
pll datas[N];

long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1){
        cin>>a[i];
    }
    rng(i,0,n-1){
        cin>>b[i];
    }
    aset.clear();
    bset.clear();
    ll res=1;
    rng(i,0,n-1) aset.insert({a[i],i});
    rng(i,0,n-1) bset.insert({b[i],i});
    auto acur=aset.begin();
    auto bcur=bset.begin();

    rng(i,0,n-1){
        res=(res*min((acur->fi),(bcur->fi)))%MOD;
        datas[i]={(acur->fi),(bcur->fi)};
        acur=next(acur);
        bcur=next(bcur);
    }
    res=(res+MOD)%MOD;
    cout<<res<<' ';

    rng(i,0,q-1){
        int o,x;
        cin>>o>>x;
        x--;
        if(o==1){
            //a[x] 인 것 중 가장 뒤에있는 것
            int l=0, r=n-1;
            while(l<r){
                int m=(l+r+1)>>1;
                if(datas[m].fi<=a[x]) l=m;
                else r=m-1;
            }
            if(datas[l].fi<=datas[l].se){
                res=(res*ari_inv(datas[l].fi))%MOD;
            }
            else{
                res=(res*ari_inv(datas[l].se))%MOD;
            }
            datas[l].fi++;
            res=(res*min(datas[l].fi,datas[l].se))%MOD;
            a[x]++;
        }
        else{
            int l=0, r=n-1;
            while(l<r){
                int m=(l+r+1)>>1;
                if(datas[m].se<=b[x]) l=m;
                else r=m-1;
            }
            if(datas[l].fi<=datas[l].se){
                res=(res*ari_inv(datas[l].fi))%MOD;
            }
            else{
                res=(res*ari_inv(datas[l].se))%MOD;
            }
            datas[l].se++;
            res=(res*min(datas[l].fi,datas[l].se))%MOD;
            b[x]++;
        }
        cout<<(res+MOD)%MOD<<' ';
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

