
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N];
int DP[N];
array<int,3> qs[N];
int ans[N];

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,q-1){
        int x,y;
        cin>>x>>y;
        x--;
        qs[i]={x,y,i};
    }
    fill(DP,DP+n,0);
    sort(qs,qs+q);
    
    int m=0;
    int qidx=0;
    rng(i,0,n-1){
        if(m==0 || DP[m-1]<datas[i]) DP[m++]=datas[i];
        else{
            int pos=lower_bound(DP,DP+m,datas[i])-DP;
            DP[pos]=datas[i];
        }
        while(qidx<q && qs[qidx][0]==i){
            // cout<<"Current DP: ";
            // rng(j,0,m-1) cout<<DP[j]<<' ';
            // cout<<'\n';
            // cout<<"Cur query: "<<qs[qidx][0]<<' '<<qs[qidx][1]<<' '<<qs[qidx][2]<<'\n';
            int idx=upper_bound(DP,DP+m,qs[qidx][1])-DP-1;
            
            ans[qs[qidx][2]]=idx+1;
            qidx++;
        }
    }

    rng(i,0,q-1) cout<<ans[i]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

