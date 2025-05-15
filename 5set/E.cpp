
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
bool visited[N];
int parent[N];

int find_r(int x){
    if(parent[x]==x) return x;
    return parent[x]=find_r(parent[x]);
}
void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) parent[i]=i;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    // 가능/ 불가능은 그냥 자기보다 번호가 낮은 애랑 연결을 했는가? 로 확인 가능한거같다. 
    // 아 아니지 union-find해야겠다.
    // 근데 문제는 이제
    int cnt=0;
    int numcom=0;
    rng(i,0,n-1){
        numcom++;
        if(visited[i]) cnt--;

        for(auto next: edges[i]){
            if(next<i){
                if(find_r(i)!=find_r(next)){
                    numcom--;
                    parent[find_r(next)]=find_r(i);
                }
            }
            else{
                if(!visited[next]){
                    visited[next]=1;
                    cnt++;
                }
            }
        }
        if(numcom==1){
            cout<<cnt<<'\n';
        }
        else cout<<-1<<'\n';
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

