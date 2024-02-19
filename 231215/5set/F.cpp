
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

// 일단 sort를 하던말던 상관이 없는 것은 확실하다.
int datas[N];
vc<int> muls[N]; // i의 배수들의 mul들을 담는다.
ll cnt[N];
ll DP[N]; // 나를 gcd로 가지는 pair의 개수

int gcd(int x, int y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

void Solve(){
    int n=100000;
    //cin>>n;
    rng(i,0,n-1) datas[i]=100000;
    sort(datas,datas+n);
    rng(i,1,100000) muls[i].clear();
    rng(i,0,n-1){
        for(int j=1; j*j<=datas[i]; j++){
            if(datas[i]%j==0){
                muls[j].pb(i);
                if(j*j!=datas[i]) muls[datas[i]/j].pb(i);
            }
        }
    }
    // rng(i,1,10){
    //     //cout<<"das : "<<i<<' ';
    //     rng(j,0,(int)muls[i].size()-1){
    //         cout<<muls[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    fill(cnt,cnt+100001,0);
    rng(i,1,100000){
        rng(j,0,(int)muls[i].size()-1){
            cnt[i]+=((ll)j)*((ll)n-1-muls[i][j]);
        }
    }
    gnr(i,100000,1){
        for(int j=2; i*j<=100000; j++){
            cnt[i]-=cnt[i*j];
        }
    }
    long long res=0;
    rng(i,1,100000){
        res+=cnt[i]*i;
    }
    cout<<res<<'\n';
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

