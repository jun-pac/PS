
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[20];
vc<pii> ans;
ll DP[20], pred[20]; // DP는 기본적으로 i를 보존하는 전략임

void DFS(int l, int r){
    if(l==r){
        if(datas[l]!=0) ans.pb({l+1,l+1});
        datas[l]=1;
        return;
    }
    DFS(l,r-1);
    ans.pb({l+1,r});
    rng(j,l,r-1) datas[j]=r-l;
    DFS(l+1,r);
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    datas[n]=0;

    rng(i,0,n){
        DP[i]=datas[i]+i*i;
        pred[i]=-1;
        rng(p,0,i-1){
            if(DP[i]<datas[i]+(i-p-1)*(i-p-1)+DP[p]){
                DP[i]=datas[i]+(i-p-1)*(i-p-1)+DP[p];
                pred[i]=p;
            }
        }
        //cout<<"DP : "<<i<<' '<<DP[i]<<' '<<pred[i]<<'\n';
    }

    int cur=n;
    while(cur>0){
        int l=pred[cur];
        //cout<<"cur : "<<cur<<' '<<pred[cur]<<'\n';
        if(l+1<=cur-1){
            //cout<<"MEX : "<<l+2<<' '<<cur<<'\n';
            DFS(l+1,cur-1);
            ans.pb({l+2, cur});
        }
        cur=pred[cur];
    }
    assert((int)ans.size()<=500000);

    cout<<DP[n]<<' '<<ans.size()<<'\n';
    rng(i,0,(int)ans.size()-1){
        cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();
    }
    return 0;
}

