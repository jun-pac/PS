
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

array<int,3> datas[N]; // {row, color, col} // w가 -1.
void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,m-1){
        int x,y;
        char c;
        cin>>x>>y>>c;
        x--, y--;
        if(c=='W') datas[i]={x,-1,y};
        else datas[i]={x,1,y};
    }
    // 같은 row에서 bbbwww policy
    // 같은 column에서 bbbwww policy
    // 위에서부터 내려가면서 w의 최소 등장점 이후에 b가 등장하면 안 됨.
    int mn=n;
    sort(datas,datas+m);
    rng(i,0,m-1){
        if(datas[i][1]==-1) mn=min(mn,datas[i][2]);
        else{
            if(datas[i][2]>=mn){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
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

