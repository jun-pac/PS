
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

ll datas[N], od[N], e[N], sum[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
        e[i]=(i==0?0:e[i-1])+(datas[i]%2==0);
        od[i]=(i==0?0:od[i-1])+(datas[i]%2!=0);
        sum[i]=(i==0?0:sum[i-1])+datas[i];
    }

    rng(i,0,n-1){
        if(i==0) cout<<datas[0]<<' ';
        else{
            ll odd=od[i], even=e[i];
            if(odd%3==0){
                cout<<sum[i]-odd/3<<' ';
            }
            else if(odd%3==1){
                cout<<sum[i]-(odd/3+1)<<' ';
            }
            else{
                cout<<sum[i]-(odd/3)<<' ';
            }
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
