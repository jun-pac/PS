
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
#define INF 1000000000007 

int datas[N];

vc<pll> oooob[N], ccccb[N];

void Solve(){
    int n,m; // m : leng of tour
    cin>>n>>m;
    ll cur=0;
    rng(i,0,m-1){
        cin>>datas[i];
        datas[i]--;
        if(i!=0){
            if((datas[i]+n-datas[i-1])%n<=n/2){
                oooob[datas[i-1]].pb({datas[i],(datas[i]+n-datas[i-1])%n});
                ccccb[datas[i]].pb({datas[i-1],(datas[i]+n-datas[i-1])%n});
                cur+=(datas[i]+n-datas[i-1])%n;
                //cout<<"input1 "<<datas[i-1]<<' '<<datas[i]<<' '<<(datas[i]+n-datas[i-1])%n<<'\n';
            }
            else{
                oooob[datas[i]].pb({datas[i-1],(datas[i-1]+n-datas[i])%n});
                ccccb[datas[i-1]].pb({datas[i],(datas[i-1]+n-datas[i])%n});
                cur+=(datas[i-1]+n-datas[i])%n;
                //cout<<"input2 "<<datas[i]<<' '<<datas[i-1]<<' '<<(datas[i-1]+n-datas[i])%n<<'\n';
            }
        }
    }
    //cout<<"original cost "<<cur<<'\n';

    // 0-1을 자를 때의 cost
    rng(i,1,n-1){
        for(auto next : oooob[i]){
            if(next.fi<i && next.fi>0){
                assert((next.fi+n-i)%n<=n/2);
                cur+=n-2*next.se;
            }
        }
    }
    //cout<<"init cur : "<<cur<<'\n';
    ll mn=INF;
    rng(i,0,n-1){
        if(i!=0){
            for(auto next : ccccb[i]){
                assert(next.se<=n/2 && (i+n-next.fi)%n==next.se);
                cur-=n-2*next.se;
            }
        }
        for(auto next : oooob[i]){
            //cout<<"oooob "<<i<<' '<<next.fi<<' '<<next.se<<'\n';
            assert(next.se<=n/2 && (next.fi+n-i)%n==next.se);
            cur+=n-2*next.se;
        }
        mn=min(mn,cur);
        //if(i<20) cout<<"CUT "<<i<<' '<<(i+1)%n<<' '<<cur<<'\n';
    }
    cout<<mn<<'\n';
    
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

