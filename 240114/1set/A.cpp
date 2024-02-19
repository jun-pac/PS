
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

ll datas[100], res[100];
pii ans[1909];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int nump=0, numn=0; // nump에는 0을 포함하는걸로 할까요?
    ll mx=-100, mn=100, mxidx, mnidx;
    rng(i,0,n-1){
        if(mx<datas[i]) mxidx=i;
        if(mn>datas[i]) mnidx=i;
        mx=max(mx,datas[i]);
        mn=min(mn,datas[i]);
        nump+=(datas[i]>0);
        numn+=(datas[i]<0);        
    }
    if(mx<=0){
        cout<<n-1<<'\n';
        rng(i,0,n-2){
            cout<<n-i-1<<' '<<n-i<<'\n';
        }
        return;
    }
    if(mn>=0){
        cout<<n-1<<'\n';
        rng(i,0,n-2){
            cout<<i+2<<' '<<i+1<<'\n';
        }
        return;
    }
    int cnt=0;
    int maj=(nump==numn?(abs(mx)>abs(mn)):nump>numn); // +면 1
    if(maj==0){
        rng(i,0,n-1) datas[i]=-datas[i];
        reverse(datas,datas+n);
        swap(mx,mn);
        mx=-mx, mn=-mn;
        swap(mxidx,mnidx);
        mxidx=n-1-mxidx, mnidx=n-1-mnidx;
    }
    if(nump==numn){
        rng(i,0,n-1){
            if(datas[i]<0) ans[cnt++]={mxidx+1,i+1}; // 이제 다 양수
        }
        rng(i,0,n-2){
            ans[cnt++]={i+1,i+2};
        }
    }
    else if(mx*8>=abs(mn)){
        rng(i,0,2) ans[cnt++]={mxidx+1, mxidx+1};
        rng(i,0,n-1){
            if(datas[i]<0) ans[cnt++]={mxidx+1,i+1}; // 이제 다 양수
        }
        rng(i,0,n-2){
            ans[cnt++]={i+1,i+2};
        }
    }
    else{
        // basically 음수로 다루게 될 예정
        int lidx; // 음수인 가장 우측원소
        rng(i,0,n-1) if(datas[i]<0) lidx=i;
        ans[cnt++]={mnidx+1,lidx+1};
        ans[cnt++]={lidx+1,lidx+1};
        ans[cnt++]={lidx+1,lidx+1};
        rng(i,lidx+1,n-1){
            ans[cnt++]={i,i+1};
        }
        int last=lidx;
        gnr(i,lidx-1,0){
            if(datas[i]<0 || i==0){
                ans[cnt++]={last+1,i+1};
                ans[cnt++]={i+1,i+1};
                rng(j,i+1,last-1){
                    ans[cnt++]={j,j+1};
                }
                last=i;
            }
        }
        if(mx==1){
            rng(i,0,cnt-1){
                datas[ans[i].se-1]+=datas[ans[i].fi-1];
            }
            bool flag=1;
            rng(i,0,n-2){
                if(datas[i]>datas[i+1]) flag=0;
            }
            assert(flag);
        }
        
    }
    assert(cnt<=31);
    if(maj==1){
        cout<<cnt<<'\n';
        rng(i,0,cnt-1) cout<<ans[i].se<<' '<<ans[i].fi<<'\n';
    }
    if(maj==0){
        cout<<cnt<<'\n';
        rng(i,0,cnt-1) cout<<n+1-ans[i].se<<' '<<n+1-ans[i].fi<<'\n';
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

