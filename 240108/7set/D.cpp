
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 

int ans[N], real_idx[N];
pii datas[N];

void Solve(){
    int n, res;
    cin>>n;
    cout<<"+ "<<n<<endl;
    cin>>res;
    if(res==-2) return;
    cout<<"+ "<<n+1<<endl;
    cin>>res;
    if(res==-2) return;
    rng(i,0,n-1){
        real_idx[i]=(i%2==0?n-(i/2):(i/2)+1);
    }
    int mxidx=0, mx=-1;
    rng(i,1,n-1){
        cout<<"? 1 "<<i+1<<endl;
        cin>>res;
        if(res==-2) return;
        if(res==-1){
            cout<<"fuck"<<endl;
            return;
        }
        if(res>mx) mx=res, mxidx=i;
    }
    rng(i,0,n-1){
        if(mxidx==i) continue;
        cout<<"? "<<mxidx+1<<' '<<i+1<<endl;
        cin>>res;
        if(res==-2) return;
        if(res==-1){
            cout<<"fuck"<<endl;
            return;
        }
        datas[i]={res,i};
    }
    datas[mxidx]={0,mxidx};
    sort(datas,datas+n);

    cout<<"! ";
    rng(i,0,n-1) ans[datas[i].se]=real_idx[datas[i].fi];
    rng(i,0,n-1) cout<<ans[i]<<' ';
    rng(i,0,n-1) ans[datas[i].se]=real_idx[n-1-datas[i].fi];
    rng(i,0,n-1) cout<<ans[i]<<' ';
    cout<<endl;
    cin>>res;
    if(res==-2){
        cout<<"why?"<<endl;
        return;
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

