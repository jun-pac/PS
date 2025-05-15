
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

#define N 1200030
#define MOD 998244353
#define INF 1000000007 
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N], sdatas[N];
vc<int> divs[N];
ll cnt[N]; // all divs

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sdatas[i]=datas[i];
    sort(sdatas,sdatas+n);

    int idx=0;
    rng(i,1,1000000){
        int prev_idx=idx;
        while(idx<n && i==sdatas[idx]) idx++;
        int num=idx-prev_idx;
        
        if(num==0) continue; 
        for (int j = 1; j*j <= i; j++) {  
            if (i % j == 0) {
                cnt[j]+=num;
                divs[i].pb(j);
                if (j != i / j) {  
                    cnt[i/j]+=num; 
                    divs[i].pb(i/j);
                }
            }
        }
    }
    rng(i,0,n-1){
        int ans=1;
        gnr(j,(int)divs[datas[i]].size()-1,0){
            if(cnt[divs[datas[i]][j]]>=k){
                ans=max(ans,divs[datas[i]][j]);
            }
        }
        cout<<ans<<'\n';
    }

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

