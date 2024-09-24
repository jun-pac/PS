
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

vc<pair<int,char>> raw_edges[N]; // edges
ll datas[101][101], ori_datas[101][101];
bool visited[N];
vc<pii> dir;
// Naming convection : idx=i*n+j
int cnt=0;
int n;
string vwall[101];
string hwall[101];
vc<array<char,3>> tempans;
array<int,4> tempinit;


ll get_ans(){
    ll res=0;
    rng(i,0,n-1){
        rng(j,0,n-2){
            res+=(datas[i][j]-datas[i][j+1])*(datas[i][j]-datas[i][j+1]);
        }
    }
    rng(i,0,n-2){
        rng(j,0,n-1){
            res+=(datas[i][j]-datas[i+1][j])*(datas[i][j]-datas[i+1][j]);
        }
    }
    return res;
}

ll swap_is_better(int aidx, int bidx){
    ll ori_res=0;
    int ax=aidx/n, ay=aidx%n;
    int bx=bidx/n, by=bidx%n;
    rng(i,0,3){
        int anx=ax+dir[i].fi;
        int any=ay+dir[i].se;
        if(anx==n || anx==-1 || any==n || any==-1) continue;
        int bnx=bx+dir[i].fi;
        int bny=by+dir[i].se;
        if(bnx==n || bnx==-1 || bny==n || bny==-1) continue;
        ori_res+=(datas[ax][ay]-datas[anx][any])*(datas[ax][ay]-datas[anx][any]);
        ori_res+=(datas[bx][by]-datas[bnx][bny])*(datas[bx][by]-datas[bnx][bny]);
    }

    ll new_res=0;
    swap(datas[ax][ay], datas[bx][by]);
    rng(i,0,3){
        int anx=ax+dir[i].fi;
        int any=ay+dir[i].se;
        if(anx==n || anx==-1 || any==n || any==-1) continue;
        int bnx=bx+dir[i].fi;
        int bny=by+dir[i].se;
        if(bnx==n || bnx==-1 || bny==n || bny==-1) continue;
        new_res+=(datas[ax][ay]-datas[anx][any])*(datas[ax][ay]-datas[anx][any]);
        new_res+=(datas[bx][by]-datas[bnx][bny])*(datas[bx][by]-datas[bnx][bny]);
    }
    swap(datas[ax][ay], datas[bx][by]);
    return new_res-ori_res;
}


ll Solve(){    
    rng(i,0,n-1) rng(j,0,n-1) datas[i][j]=ori_datas[i][j];
    int aidx=(dist(gen))%(n*n);
    int bidx=(dist(gen))%(n*n);
    tempans.clear();
    tempinit={aidx/n,aidx%n,bidx/n,bidx%n};
    cnt=0;
    while(cnt<4*n*n-2){
        char s=(swap_is_better(aidx, bidx)<0?'1':'0');
        //assert(aidx<n*n && bidx<n*n);
        //if(aidx>=400 || bidx>=400 || aidx<0 || bidx<0) cout<<aidx<<' '<<bidx<<'\n';
        if(s=='1') swap(datas[aidx/n][aidx%n], datas[bidx/n][bidx%n]);
        int aa=dist(gen)%(raw_edges[aidx].size()+1);
        int anext, bnext; 
        char ad, bd;
        if(aa==raw_edges[aidx].size()) anext=aidx, ad='.';
        else anext=raw_edges[aidx][aa].fi, ad=raw_edges[aidx][aa].se;

        ll mn=min(0LL,swap_is_better(anext,bidx)); bd='.', bnext=bidx; 
        for(auto btemp : raw_edges[bidx]){
            ll val=swap_is_better(anext,btemp.fi);
            if(val<mn){
                mn=val;
                bd=btemp.se;
                bnext=btemp.fi;
            }
        }
        if(mn==0){
            int bb=dist(gen)%(raw_edges[bidx].size()+1);
            if(bb==raw_edges[bidx].size()) bd='.', bnext=bidx;
            else bd=raw_edges[bidx][bb].se, bnext=raw_edges[bidx][bb].fi;
        }
        aidx=anext;
        bidx=bnext;
        tempans.pb({s,ad,bd});
        cnt++;
    }
    assert(cnt<=4*n*n);
    return get_ans();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
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
    rng(i,0,n-1) rng(j,0,n-1) cin>>ori_datas[i][j];

    ll mn=2000000000000;
    array<int,4> ansinit;
    vc<array<char,3>> ans;
    //rng(i,0,n-1) rng(j,0,n-1) datas[i][j]=ori_datas[i][j];
    //cout<<"init ans "<<get_ans()<<'\n';
    rng(i,0,200){
        cnt=0;
        ll curval=Solve();
        if(curval<mn){
            mn=curval;
            ans=tempans;
            ansinit=tempinit;
        }
        //cout<<"debug : "<<curval<<'\n';
    }
    //cout<<"debug last "<<mn<<'\n';
    rng(i,0,3) cout<<ansinit[i]<<' ';
    cout<<'\n';
    rng(i,0,(int)ans.size()-1) cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<'\n';
    return 0;
}

