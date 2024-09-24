
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

int datas[2022];
bool is_pal[2002][2020];
int DP[2002][2020];
int sum[2002];
vc<pair<int,pii>> s_sum; // 구간들의 정렬본
pii same_ij[2002][2020]; // 가장 합이 작은 부분만 가지고 있으면 된다.

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    s_sum.clear();
    rng(i,0,n-1) rng(j,0,n-1) same_ij[i][j];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    rng(i,0,n-1){
        rng(j,i,n-1){
            s_sum.pb({sum[j]-(i==0?0:sum[i-1]),{i,j}});
        }
    }

    rng(i,0,n-1){
        is_pal[i][i]=1;
        rng(j,i+1,n-1){
            is_pal[i][j]=(datas[i]==datas[j]?(j==i+1?1:is_pal[i+1][j-1]):0);
        }
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

