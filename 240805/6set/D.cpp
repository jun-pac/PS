
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

array<ll,3> pos[N];
ll datas[N];
ll sumj[N]; //min dist of jump
int idx_to_c[N];
int inv_idx[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>pos[i][0]>>pos[i][1];
    rng(i,0,n-1) pos[i][2]=i;
    rng(i,0,k-1) cin>>datas[i];
    rng(i,0,k-1) datas[i]--;

    sort(pos,pos+n);
    rng(i,0,n-1) inv_idx[pos[i][2]]=i;
    int cnt=0;
    idx_to_c[0]=0;
    sumj[0]=0;
    ll last=pos[0][1];
    rng(i,1,n-1){
        if(pos[i][0]>last){
            cnt++;
            sumj[cnt]=sumj[cnt-1]+pos[i][0]-last;
            last=pos[i][1];
        }
        else last=max(last,pos[i][1]);
        idx_to_c[i]=cnt;
    }
    ll ans=0;
    int cur=idx_to_c[inv_idx[0]];
    rng(i,0,k-1){
        int next=idx_to_c[inv_idx[datas[i]]];
        ans+=abs(sumj[next]-sumj[cur]);
        cur=next;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

