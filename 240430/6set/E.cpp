
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int datas[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int last_ch=0;
    int cnt=0;
    while(cnt<5000000){
        //cout<<cnt<<' '<<datas[cnt%n]<<'\n';
        if(datas[(cnt+1)%n]==0 || datas[cnt%n]==0){
            if(cnt-last_ch>n) break;
        }
        else{
            datas[(cnt+1)%n]=max(0,datas[(cnt+1)%n]-datas[cnt%n]);
            last_ch=cnt;
        }
        cnt++;
    }
    int st=0;
    rng(i,0,n-1) if(datas[i]==0){
        st=i;
        break;
    }
    rng(i,st,st+n-1){
        if(datas[st%n]==0 && datas[(st+1)%n]!=0 && datas[(st+2)%n]!=0) datas[(st+2)%n]=0;
    }
    int res=0;
    rng(i,0,n-1) if(datas[i]!=0) res++;
    cout<<res<<'\n';
    rng(i,0,n-1) if(datas[i]!=0) cout<<i+1<<' ';
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

