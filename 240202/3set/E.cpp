
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

int conn[2*N];
int nn;

bool check(int a, int b){
    //cout<<a<<' '<<b<<' '<<num<<'\n';
    int num=(b+nn-a)%nn+1;
    //cout<<a+1<<' '<<b+1<<' '<<num<<'\n';
    if(a==b) return 1;
    if(num==2) return (conn[a]==b);
    if(num%2==1) return 0;
    int tar=conn[a];
    if((tar-a+nn)%nn > (b-a+nn)%nn) return 0;
    return ((a+1)%nn==tar?1:check((a+1)%nn,(tar-1+nn)%nn)) && (tar==b?1:check((tar+1)%nn,b));
    //cout<<"what ? "<<a+1<<' '<<b+1<<'\n';
    //return 0;
}

void Solve(){
    int n;
    cin>>n;
    nn=2*n;
    rng(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        conn[a]=b;
        conn[b]=a;
    } 
    cout<<(check(0,conn[0]) && check(conn[0],0)?"No\n":"Yes\n");
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

