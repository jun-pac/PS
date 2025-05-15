
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int nest[N]; // pseudo idx
int nton[N]; // pseudo idx to real next
int invnton[N]; // real to pseudo


void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) nest[i]=i;
    rng(i,0,n-1) nton[i]=i;
    rng(i,0,n-1) invnton[i]=i;

    rng(i,0,q-1){
        int x,a,b;
        cin>>x;
        if(x==1){
            cin>>a>>b;
            a--, b--;
            int pseudob=invnton[b];
            nest[a]=pseudob;
        }
        else if(x==2){
            cin>>a>>b;
            a--, b--; // swap next a,b
            int pseudoa=invnton[a];
            int pseudob=invnton[b];
            invnton[a]=pseudob;
            invnton[b]=pseudoa;
            nton[pseudoa]=b;
            nton[pseudob]=a;
        }
        else{
            cin>>a;
            a--; // pigeon a's nest
            cout<<nton[nest[a]]+1<<'\n';
        }
    } 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

