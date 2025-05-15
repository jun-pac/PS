
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

vc<int> edges[N];
int num[N];
bool conn[101][101];
void DFS(int idx, int p, int v){
    num[idx]=v%2;
    for(int next: edges[idx]){
        if(next!=p){
            DFS(next, idx, v+1);
        }
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
        conn[a][b]=1;
        conn[b][a]=1;
    }

    DFS(0,-1,0);
    int cnt0=0, cnt1=0;
    rng(i,0,n-1) if(num[i]==1) cnt1++;
    cnt0=n-cnt1;
    int left=cnt0*cnt1-(n-1);
    set<pii> mvs;
    rng(i,0,n-1){
        rng(j,i+1,n-1){
            if(num[i]!=num[j] && !conn[i][j]) mvs.insert({i,j});
        }
    } 

    if(left%2==1){
        cout<<"First"<<endl;
        pii temp = (*mvs.begin());
        cout<<temp.fi+1<<' '<<temp.se+1<<endl;
        mvs.erase(temp);
    }
    else{
        cout<<"Second"<<endl;
    }
    while(true){
        int a,b;
        cin>>a>>b;
        if(a==-1 || b==-1) break;
        a--, b--;
        pii temp={a,b};
        mvs.erase(temp);

        assert(mvs.size()!=0);
        temp = (*mvs.begin());
        cout<<temp.fi+1<<' '<<temp.se+1<<endl;
        mvs.erase(temp);
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

