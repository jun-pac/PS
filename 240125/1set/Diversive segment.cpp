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
 
#define N 200030
#define MOD 998244353
#define INF 1000000007 

int datas[N];
pii cons[N], comp[2*N];
map<int,int> nums;
vc<int> vals[N];
int nextc[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    int numidx=1;
    fill(nextc,nextc+n,n);
    nums.clear();
    rng(i,0,n-1) vals[i].clear();
    rng(i,0,n-1){
        cin>>datas[i];
        int idx=nums[datas[i]];
        if(idx==0) nums[datas[i]]=numidx++;
        else nextc[vals[idx-1].back()]=i;
        vals[nums[datas[i]]-1].pb(i);
    }
    
    rng(i,0,m-1) cin>>cons[i].fi>>cons[i].se;
    rng(i,0,m-1) cons[i].fi--, cons[i].se--;
    sort(cons,cons+m);
    int mx=0, cnt=0, j=0; // cnt는 meaningful한 개수임
    rng(i,0,n-1){
        while(j<m && cons[j].fi<=i){
            mx=max(mx,cons[j].se);
            j++;
        }
        if(mx<i) continue;
        if(nextc[i]!=n && nextc[i]<=mx){
            comp[cnt++]={i,nextc[i]};
            int idx=nums[datas[i]]-1;
            int pos=upper_bound(vals[idx].begin(),vals[idx].end(),mx)-vals[idx].begin();
            pos=pos-1;
            assert(pos>=0 && vals[idx][pos]<=mx);
            if(vals[idx][pos]>nextc[i]) comp[cnt++]={i,vals[idx][pos]};
        }
    } 

    if(cnt==0) cout<<0<<'\n';
    else{
        sort(comp,comp+cnt);     
        int res=INF, mx=comp[cnt-1].fi, mn=comp[cnt-1].fi;
        if(datas[0]==636623560){
            // cout<<cnt<<'\n';
            // rng(i,0,cnt-1) assert(comp[i].fi<=comp[i].se);
        } 
        rng(i,0,cnt-1){
            res=min(res,mx-min(comp[i].fi,mn)+1);
            // if(datas[0]==636623560 && r-comp[i].fi+1<100){
            //     cout<<"("<<i<<' '<<r-comp[i].fi+1<<' '<<comp[i].fi<<' '<<r<<") "; 
            // }
            mx=max(mx,comp[i].se);
            mn=min(mn,comp[i].se);
        }
        // if(datas[0]==636623560) cout<<'\n';
        mx=comp[0].se, mn=comp[0].se;
        rng(i,0,cnt-1) mx=max(mx,comp[i].se);
        rng(i,0,cnt-1) mn=min(mn,comp[i].se);
        // if(datas[0]==636623560) cout<<mn<<' '<<mx<<'\n';
        cout<<min(res,mx-mn+1)<<'\n';
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

