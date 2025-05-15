
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

string conn[101];
int dist[101][101];
int inq[101][101];
queue<pii> q;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>conn[i];
    }
    rng(i,0,n-1) fill(dist[i],dist[i]+n,-1);

    rng(i,0,n-1){
        inq[i][i]=i;
        dist[i][i]=0;
        q.push({i,i});
        rng(j,0,n-1){
            if(j!=i && conn[i][j]!='-'){
                inq[i][j]=1;
                dist[i][j]=1;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        int i=temp.fi;
        int j=temp.se;
        int d=dist[i][j];
        inq[i][j]=0;
        vc<pair<char,int>> nis, njs;
        rng(ni,0,n-1){
            if(conn[ni][i]!='-'){
                rng(nj,0,n-1){
                    if(conn[j][nj]==conn[ni][i]){
                        if(dist[ni][nj]>dist[i][j]+2 || dist[ni][nj]==-1){
                            dist[ni][nj]=dist[i][j]+2;
                            if(!inq[ni][nj]){
                                inq[ni][nj]=1;
                                q.push({ni,nj});    
                            }
                        }
                    }
                }
            }
        }
        // rng(ni,0,n-1){
        //     if(ni!=i && conn[ni][i]!='-') nis.pb({conn[ni][i],ni});
        // }
        // rng(nj,0,n-1){
        //     if(nj!=j && conn[j][nj]!='-') nis.pb({conn[j][nj],nj});
        // }
        // sort(all(nis));
        // sort(all(njs));
        // int ii=0, jj=0;
        // while(ii<nis.size() && jj<njs.size()){
        //     if(nis[ii]<njs[jj]){
        //         ii++;
        //     }
        //     else{

        //     }
        // }
    }
    rng(i,0,n-1){
        rng(j,0,n-1) cout<<dist[i][j]<<' ';
        cout<<'\n';
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

