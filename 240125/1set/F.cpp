
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

#define BUC 450

ll datas[N];
ll sum[BUC+1][N];
ll ksum[BUC+1][N];

void Solve(){
    ll n,q,s,d,k;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,1,BUC){
        rng(j,0,n-1){
            sum[i][j]=(j<i?0:sum[i][j-i])+datas[j];
            ksum[i][j]=(j<i?0:ksum[i][j-i])+(j/i)*datas[j]; // 처음에 0을 곱하는 모델임
        }
    }

    rng(i,0,q-1){
        cin>>s>>d>>k;
        s--;
        if(d<=BUC){
            // DP를 이용
            // s%d를 알고있음
            ll temp=ksum[d][s+d*(k-1)]-(s<d?0:ksum[d][s-d]);
            //cout<<"de "<<temp<<' '<<(s/d-1)<<' '<<sum[d][s+d*(k-1)]<<' '<<d<<' '<<s+d*(k-1)<<'\n';
            temp=temp-(s/d-1)*(sum[d][s+d*(k-1)]-(s<d?0:sum[d][s-d]));
            cout<<temp<<' ';
        }
        else{
            ll res=0;
            rng(j,1,k) res+=j*datas[s+(j-1)*d];
            cout<<res<<' ';
        }
    } 
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

