
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
#define INF 30001000000007 
vc<ll> mxval[3003];
ll DP[3003], prev_DP[3003];
ll mx_happy[3003][3003];

void Solve(){
    ll n,w;
    cin>>n>>w;
    ll mnw=3000;
    rng(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        mnw=min(mnw,a);
        mxval[a].pb(b);
    }
    rng(i,0,w) sort(all(mxval[i]));
    rng(i,0,w) reverse(all(mxval[i]));


    // 각각의 weight k에 대해서 j개를 사용할 때의 maxhappy를 다른 DP문제로 풀면 된다.
    int cnt[3003];
    rng(k,1,w){
        if(mxval[k].size()==0) continue;
        fill(cnt,cnt+mxval[k].size(),0);
        mx_happy[k][0]=0;
        for(int j=1; k*j<=w; j++){
            ll mx=mxval[k][0]-2*cnt[0]-1;
            ll mxidx=0;
            rng(t,1,(int)mxval[k].size()-1){
                if(mxval[k][t]-2*cnt[t]-1 > mx){
                    mx=mxval[k][t]-2*cnt[t]-1;
                    mxidx=t;
                }
            }
            mx_happy[k][j]=mx_happy[k][j-1]+mx;
            cnt[mxidx]++;
        }
    }


    //cout<<mnw<<' '<<mxval[mnw][0]<<'\n';
    fill(DP,DP+w+1,-INF);
    DP[0]=0;
    for(int i=1; i*mnw<=w; i++){
        //cout<<"i "<<i<<' '<<i*mxval[mnw]-i*i<<endl;
        DP[i*mnw]=mx_happy[mnw][i];
    }

    rng(k,mnw+1,w){
        if(mxval[k].size()==0) continue;
        rng(i,0,w) prev_DP[i]=DP[i];
        rng(i,0,w){
            for(int j=1; i-k*j>=0; j++){
                DP[i]=max(DP[i],prev_DP[i-k*j]+mx_happy[k][j]);
            }
        }

    }
    ll mx=0;
    rng(i,0,w) mx=max(mx,DP[i]);
    cout<<mx<<'\n';

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

