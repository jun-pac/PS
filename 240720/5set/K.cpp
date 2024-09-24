
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

bool visited[2][505][505];
int mp[2][505][505];

void Solve(){
    int n,a,b,c,d;
    cin>>n;
    cin>>a>>b>>c>>d;

    //visited[0][0][0]=visited[1][0][0]=1;
    queue<pair<int,pii>> q;
    q.push({0,{0,0}});
    q.push({1,{0,0}});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        int v=temp.fi;
        int x=temp.se.fi;
        int y=temp.se.se;
        if(visited[v][x][y]) continue;
        visited[v][x][y]=1;
        
        int aa=(v==0?a:c);
        int bb=(v==0?b:d);
        
        int nx,ny;
        nx=x+aa, ny=y+bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
        nx=x-aa, ny=y+bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
        nx=x+aa, ny=y-bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
        nx=x-aa, ny=y-bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
        aa=(v==0?b:d);
        bb=(v==0?a:c);
        nx=x+aa, ny=y+bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
        nx=x-aa, ny=y+bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
        nx=x+aa, ny=y-bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
        nx=x-aa, ny=y-bb;
        if(0<=nx && nx<n && 0<=ny && ny<n && !visited[1-v][nx][ny]){
            q.push({1-v,{nx,ny}});
        }
    }
    int ans=0;
    rng(i,0,n-1){
        rng(j,0,n-1){
            if(visited[0][i][j] || visited[1][i][j]) ans++;
        }
    }
    cout<<ans<<'\n';
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

