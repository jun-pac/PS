
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


pii a[N], b[N]; // original idx dosen't matter for b[]
int aidx[N], ans[N];
bool used[N];

void Solve(){
    int n,x;
    cin>>n>>x;
    rng(i,0,n-1){
        cin>>a[i].fi;
        a[i].se=i;
    }
    rng(i,0,n-1){
        cin>>b[i].fi;
        b[i].se=i;
    }
    sort(a,a+n);
    sort(b,b+n);
    bool flag=1; 
    int bidx=x-1;   
    fill(used,used+n,0);
    gnr(i,n-1,0){
        if(bidx==-1) break;
        if(a[i].fi>b[bidx].fi){
            aidx[bidx]=i;
            used[i]=1;
            bidx--;
        }
    }
    if(bidx!=-1) {
        cout<<"NO"<<'\n';
        return;
    }
    bidx=x;
    rng(i,0,n-1){
        if(bidx==n) break;
        if(!used[i] && b[bidx].fi>=a[i].fi){
            aidx[bidx]=i;
            used[i]=1;
            bidx++;   
        }
    }
    if(bidx!=n){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    rng(i,0,n-1) ans[a[aidx[i]].se]=b[i].fi;
    rng(i,0,n-1) cout<<ans[i]<<' ';
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

