
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

string rr[N];
string datas[N];
int num_dot[N], num_a[N]; 

int check(int n, int m, int k){
    int res=INF;
    rng(i,0,n-1){
        rng(j,0,m-1){
            num_a[j]=(j==0?0:num_a[j-1])+(datas[i][j]!='x');
            num_dot[j]=(j==0?0:num_dot[j-1])+(datas[i][j]=='.');
            if(j>=k-1 && num_a[j]-(j==k-1?0:num_a[j-k])==k){
                res=min(res,num_dot[j]-(j==k-1?0:num_dot[j-k]));
            }
        }
    }    
    return res;
}

void Solve(){
    int h,w,k;
    cin>>h>>w>>k;
    int mn=INF;
    int n,m;
    n=h, m=w;
    rng(i,0,n-1){
        cin>>rr[i];
    }
    rng(i,0,n-1){
        datas[i].clear();
        datas[i].resize(m);
        rng(j,0,m-1) datas[i][j]=rr[i][j];
    }
    mn=min(mn,check(n,m,k));
    rng(i,0,n-1) datas[i].clear();
    rng(i,0,m-1){
        datas[i].resize(n);
        rng(j,0,n-1) datas[i][j]=rr[j][i];
    }
    swap(n,m);
    mn=min(mn,check(n,m,k));
    cout<<(mn==INF?-1:mn)<<'\n';
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

