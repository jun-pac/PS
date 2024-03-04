
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

ll block[N];
int ans[1000];
int DP[N]; // sum을 만드는 최소의 개수
pii num[N];

void Solve(){
    ll n,start,mod,sum;
    cin>>n>>start>>mod>>sum;
    ll base=start%mod;
    if(sum<base*(n-1)+start || (sum%mod)!=(base*n)%mod){
        cout<<"NO\n";
        return;
    }
    
    // s, s+1, ... 0, 1, 2, 3, ... 이런 문제로 바뀜
    start=(start-base)/mod;
    sum-=n*base;
    sum/=mod;
    assert(sum>=0);

    fill(DP,DP+sum+1,INF);
    DP[start]=1;
    num[start]={start,start};
    int cur=start;
    rng(i,1,700){
        cur+=(start+i);
        if(cur>sum) break;
        DP[cur]=i+1;
        num[cur]={start,start+i};
    }
    rng(i,start+1,sum){
        rng(j,0,700){
            if(i<block[j]) break;
            if(DP[i-block[j]]+j+1<DP[i]){
                DP[i]=DP[i-block[j]]+j+1;
                num[i]={0,j};
            }
        }
    }
    if(DP[sum]>n){
        cout<<"NO\n";
        return;
    }
    vc<int> ans;
    cur=sum;
    while(true){
        int r=num[cur].se, l=num[cur].fi;
        gnr(i,r,l){
            ans.pb(i);
            cur-=i;
        }
        if(cur<=0) break;
    }
    reverse(all(ans));
    assert(ans[0]==start);
    assert(ans.size()==DP[sum]);
    assert(cur==0);
    cout<<"YES\n";
    rng(i,0,(int)ans.size()-1) cout<<ans[i]*mod+base<<' ';
    rng(i,(int)ans.size(),n-1) cout<<base<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng(i,0,1000) block[i]=(i*(i+1))/2;
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

