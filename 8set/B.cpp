
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

#define MOD 1000000007
#define INF 1000000007 

bool mp[1001][1010];
bool isgood[500050];
pii datas[500050];
vc<pii> dir;
int parent[1000050];
ll sz[1000050];
ll onecnt[1000050];
ll rels[1000050];

int find_r(int idx){
    if(parent[idx]==idx) return idx;
    return parent[idx]=find_r(parent[idx]);
}

void Solve(){

    int n,m,k;
    cin>>n>>m>>k;
    rng(i,0,n-1) fill(mp[i],mp[i]+m,0);
    fill(isgood,isgood+k+1,0);
    rng(i,0,n*m-1) parent[i]=i; 
    fill(sz,sz+n*m,1);
    fill(onecnt,onecnt+n*m,0);
    fill(rels,rels+n*m,0);

    bool flag=1;
    // rng(i,0,k) datas[i]={-1,-1}; // default
    rng(i,0,k){
        int a,b;
        cin>>a>>b;
        a--, b--;
        datas[i]={a,b};
        if(mp[a][b]){
            flag=0;
        }
        mp[a][b]=1;
        if(i==0) continue;
        if((a+b)%2!=(datas[0].fi+datas[0].se)%2){
            flag=0;
        }
        rng(j,0,3){
            if(datas[i-1].fi==datas[i].fi-dir[j].fi*2 && datas[i-1].se==datas[i].se-dir[j].se*2){
                // straight
                a=datas[i].fi-dir[j].fi;
                b=datas[i].se-dir[j].se;
                if(mp[a][b]){
                    flag=0;
                }
                mp[a][b]=1;
                isgood[i]=1;
                break;
            }
        }        
    }
    if(!flag){
        cout<<0<<'\n';
        return;
    }

    // 
    rng(i,1,k){
        if(!isgood[i]){
            rng(j,0,3){
                if(datas[i].fi+dir[j].fi+dir[(j+1)%4].fi == datas[i-1].fi && datas[i].se+dir[j].se+dir[(j+1)%4].se == datas[i-1].se){
                    int a1=datas[i].fi+dir[j].fi;
                    int b1=datas[i].se+dir[j].se;
                    int a2=datas[i].fi+dir[(j+1)%4].fi;
                    int b2=datas[i].se+dir[(j+1)%4].se;
                    int r1=find_r(a1*m+b1);
                    int r2=find_r(a2*m+b2);
                    rels[r2]++;
                    // cout<<"DE "<<a1<<' '<<b1<<' '<<a2<<' '<<b2<<' '<<r1<<' '<<r2<<'\n';

                    if(r1!=r2){
                        parent[r1]=r2;
                        sz[r2]+=sz[r1];
                        rels[r2]+=rels[r1];
                        // cout<<rels[r2]<<' '<<sz[r2]<<' '<<r2<<' '<<r1<<'\n';
                    }
                    isgood[i]=1;
                    break;
                }
            }
            if(!isgood[i]){
                cout<<0<<'\n'; // Not reachable from its initial layout
                return;
            }    
        }
    }


    ll res=1;
    rng(i,0,n-1){
        rng(j,0,m-1) if(mp[i][j]) onecnt[find_r(i*m+j)]++;
    }

    rng(i,0,n-1){
        rng(j,0,m-1) if(find_r(i*m+j)==i*m+j && sz[i*m+j]>=2){
            if(rels[i*m+j]==sz[i*m+j]){
                if(onecnt[i*m+j]==0) res=(res*2)%MOD;
                else res=0;
            }
            else if(rels[i*m+j]>sz[i*m+j]){
                res=0;
            }
            else{
                if(onecnt[i*m+j]==0) res=(res*sz[i*m+j])%MOD;
                else if(onecnt[i*m+j]>=2) res=0;
            }
        }
    }
    
    cout<<(res%MOD+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    dir.pb({-1,0});
    dir.pb({0,1});
    dir.pb({1,0});
    dir.pb({0,-1});
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

