
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

mt19937 engine((unsigned int)time(NULL));
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(0, 998253);

#define N 10010
#define MOD 998244353
#define INF 1000000007 

vc<pair<int,char>> raw_edges[N], edges[N]; // edges
ll datas[101][101];
bool visited[N];
vc<pii> dir;
// Naming convection : idx=i*n+j
int cnt=0;
int n;
int bidx;
string vwall[101];
string hwall[101];

inline bool check1(int a, int ad){
    int ax=a/n, ay=a%n;
    int anx=ax, any=ay; 
    
    if(ad=='U') anx=ax-1;
    if(ad=='L') any=ay-1;
    if(ad=='D') anx=ax+1;
    if(ad=='R') any=ay+1;

    if(anx<0 || anx>=n || any<0 || any>=n) return false;

    if(ad=='U') if(hwall[ax-1][ay]=='1') return false;
    if(ad=='L') if(vwall[ax][ay-1]=='1') return false;
    if(ad=='D') if(hwall[ax][ay]=='1') return false;
    if(ad=='R') if(vwall[ax][ay]=='1') return false;
    return true;
}

inline bool check(int a, int b, char ad, char bd){
    if(ad!='.') if(!check1(a,ad)) return false;
    if(bd!='.') if(!check1(b,bd)) return false;
    return true;
}

inline char rev(char dd){
    char rev;
    if(dd=='U') rev='D';
    if(dd=='D') rev='U';
    if(dd=='R') rev='L';
    if(dd=='L') rev='R';
    return rev;
}

ll swap_is_better(int aidx, int bidx){
    ll ori_res=0;
    int ax=aidx/n, ay=aidx%n;
    int bx=bidx/n, by=bidx%n;
    rng(i,0,3){
        int anx=ax+dir[i].fi;
        int any=ay+dir[i].se;
        if(anx==n || anx==-1 || any==n || any==-1) continue;
        ori_res+=(datas[ax][ay]-datas[anx][any])*(datas[ax][ay]-datas[anx][any]);
        int bnx=bx+dir[i].fi;
        int bny=by+dir[i].se;
        if(bnx==n || bnx==-1 || bny==n || bny==-1) continue;
        ori_res+=(datas[bx][by]-datas[bnx][bny])*(datas[bx][by]-datas[bnx][bny]);
    }

    ll new_res=0;
    swap(datas[ax][ay], datas[bx][by]);
    rng(i,0,3){
        int anx=ax+dir[i].fi;
        int any=ay+dir[i].se;
        if(anx==n || anx==-1 || any==n || any==-1) continue;
        new_res+=(datas[ax][ay]-datas[anx][any])*(datas[ax][ay]-datas[anx][any]);
        int bnx=bx+dir[i].fi;
        int bny=by+dir[i].se;
        if(bnx==n || bnx==-1 || bny==n || bny==-1) continue;
        new_res+=(datas[bx][by]-datas[bnx][bny])*(datas[bx][by]-datas[bnx][bny]);
    }
    swap(datas[ax][ay], datas[bx][by]);
    return new_res-ori_res;
}

void DFS(int aidx){
    char s='0',e='.';
    visited[aidx]=1;
    //cout<<"cur pos "<<aidx/n<<' '<<aidx%n<<' '<<bidx/n<<' '<<bidx%n<<'\n';
    for(auto anext : edges[aidx]){
        if(visited[anext.fi]) continue;
        s=(swap_is_better(aidx, bidx)<0?'1':'0');
        if(s=='1') swap(datas[aidx/n][aidx%n], datas[bidx/n][bidx%n]);
        ll mn=min(0LL,swap_is_better(anext.fi, bidx)); e='.';
        int nb=bidx;
        for(auto bnext : raw_edges[bidx]){
            if(swap_is_better(anext.fi,bnext.fi)<mn){
                mn=swap_is_better(anext.fi,bnext.fi);
                e=bnext.se;
                nb=bnext.fi;
            }
        }
        if(mn==0){
            ll mntemp=
            for(auto bnext : raw_edges[bidx]){
                if(swap_is_better(anext.fi,bnext.fi)<mn){
                    mn=swap_is_better(anext.fi,bnext.fi);
                    e=bnext.se;
                    nb=bnext.fi;
                }
            }
        }

        // Proceed
        cout<<s<<' '<<anext.se<<' '<<e<<'\n';
        // if(!check1(aidx, anext.se)){
        //     cout<<"why? "<<aidx/n<<' '<<aidx%n<<' '<<anext.se<<'\n';
        //     return;
        // }
        assert(check(aidx,bidx,anext.se,e));
        //check(aidx,bidx,anext.se,e);
        //if(!check(aidx,bidx,anext.se,e)) cout<<"False "<<aidx<<' '<<bidx<<' '<<anext.se<<' '<<e<<'\n';
        cnt++;
        assert(cnt<=4*n*n);
        bidx=nb;
        DFS(anext.fi);
        
        nb=bidx;
        s=(swap_is_better(anext.fi, bidx)<0?'1':'0');
        if(s=='1') swap(datas[aidx/n][aidx%n], datas[bidx/n][bidx%n]);
        mn=min(0LL,swap_is_better(aidx,bidx)); e='.'; 
        for(auto bnext : raw_edges[bidx]){
            if(swap_is_better(aidx,bnext.fi)<mn){
                mn=swap_is_better(aidx,bnext.fi);
                e=bnext.se;
                nb=bnext.fi;
            }
        }
        // if(mn==0){
        //     int sec=raw_edges[bidx].size();
        //     int j=(dist(gen))%(sec+1);
        //     if(j>=sec) e='.', nb=bidx;
        //     else e=raw_edges[bidx][j].se, nb=raw_edges[bidx][j].fi;
        // }
        

        // Backward
        cout<<s<<' '<<rev(anext.se)<<' '<<e<<'\n';
        assert(check(anext.fi,bidx,rev(anext.se),e));
        cnt++;
        assert(cnt<=4*n*n);
        bidx=nb;
        //cout<<"cur pos2 "<<aidx/n<<' '<<aidx%n<<' '<<bidx/n<<' '<<bidx%n<<'\n';
    }
}

void Solve(){
    int t;
    cin>>t>>n;
    dir.pb({1,0});
    dir.pb({0,1});
    dir.pb({-1,0});
    dir.pb({0,-1});


    rng(i,0,n-1){
        string s;
        cin>>vwall[i];
        rng(j,0,n-2){
            char v=vwall[i][j];
            if(v=='0'){
                raw_edges[i*n+j].pb({i*n+(j+1),'R'});
                raw_edges[i*n+j+1].pb({i*n+j,'L'});
            }
        }
    }
    rng(i,0,n-2){
        cin>>hwall[i];
        rng(j,0,n-1){
            char h=hwall[i][j];
            if(h=='0'){
                raw_edges[i*n+j].pb({(i+1)*n+j,'D'});
                raw_edges[(i+1)*n+j].pb({i*n+j,'U'});
            }
        }
    }
    rng(i,0,n-1) rng(j,0,n-1) cin>>datas[i][j];
    
    fill(visited,visited+n*n,0);
    int st=0*n+0; // Starting point of graph traversial
    queue<pair<pair<int,char>,int>> q; // {idx, p}

    q.push({{st,'L'},-1});
    while(!q.empty()){
        pair<int,char> idx=q.front().fi;
        int p=q.front().se;
        q.pop();
        if(visited[idx.fi]) continue;
        visited[idx.fi]=1;
        if(p!=-1){
            edges[p].pb(idx);
            edges[idx.fi].pb({p,rev(idx.se)});
        }
        for(auto next : raw_edges[idx.fi]){
            if(!visited[next.fi]) q.push({next, idx.fi});
        }
    }
    int sz=0;
    rng(i,0,n*n-1) sz+=(int)edges[i].size();
    assert(2*(n*n-1)==sz);

    bidx=(dist(gen))%(n*n);
    cout<<0<<' '<<0<<' '<<bidx/n<<' '<<bidx%n<<'\n';
    fill(visited,visited+n*n,0);
    DFS(0); assert(cnt<=2*n*n);
    fill(visited,visited+n*n,0);
    DFS(0); assert(cnt<=4*n*n);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Solve();
    return 0;
}

