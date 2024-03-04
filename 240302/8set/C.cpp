
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

void Solve(){
    int n,m, res1, res2, res3, res4;
    cin>>n>>m;
    cout<<"? "<<1<<' '<<1<<endl;
    cin>>res1;

    cout<<"? "<<1<<' '<<m<<endl;
    cin>>res2;

    cout<<"? "<<n<<' '<<1<<endl;
    cin>>res3;

    pii tar1, tar2;

    int h=(res1+res2-(m-1))/2;
    tar1={1+h,1+res1-h};

    h=(res1+res3-(n-1))/2;
    tar2={1+res1-h,1+h};

    if(res1+res2-(m-1)<0 || (res1+res2-(m-1))%2!=0){
        cout<<"? "<<1<<' '<<1<<endl;
        cin>>res4;
        cout<<"! "<<tar2.fi<<' '<<tar2.se<<endl;
        return;
    }
    
    cout<<"? "<<tar1.fi<<' '<<tar1.se<<endl;
    cin>>res4;
    if(res4==0){
        cout<<"! "<<tar1.fi<<' '<<tar1.se<<endl;
    }
    else{
        cout<<"! "<<tar2.fi<<' '<<tar2.se<<endl;
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

