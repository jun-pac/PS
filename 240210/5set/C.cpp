
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

int ans[N];

void rec(int n){
    //cout<<"VISIT "<<n<<'\n';
    int m=0;
    if(n==1){
        ans[0]=0;
        return;
    }
    else if(n==2){
        ans[0]=1;
        ans[1]=0;
        return;
    }
    // 0 ~ n-1
    int sq=int(sqrt(n-1));
    assert(sq*sq<=n-1 && (sq+1)*(sq+1)>n-1);
    // 0 ~ sq*sq (즉 sq*sq+1)은 문제없음
    if(sq*sq==n-1){
        rng(i,0,sq*sq) ans[i]=n-1-i;
        return;
    }
    // (sq+1)*(sq+1)로 처리가 되는 범위는
    // (sq+1)*(sq+1) - n-1
    assert((sq+1)*(sq+1)-(n-1)<=n-1);
    rng(i,(sq+1)*(sq+1)-(n-1), n-1){
        ans[i]=(sq+1)*(sq+1)-i;
        assert(ans[i]>=0 && ans[i]<n);
    } 
    rec((sq+1)*(sq+1)-(n-1)-1+1);

}


void Solve(){
    int n;
    cin>>n;
    rec(n);
    rng(i,0,n-1) cout<<ans[i]<<' ';
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

