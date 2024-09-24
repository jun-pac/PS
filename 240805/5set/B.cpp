
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))
string datas[2];
int cnt;
bool visited[2][N];
vc<pii> dir;
int nums[4];
int comnum[2][N];
int n;
int cutcnt[2][N];


void DFS(int a,int b){
    visited[a][b]=1;
    comnum[a][b]=cnt;
    if(cnt<=3) nums[cnt]++;
    rng(i,0,3){
        int na=a+dir[i].fi;
        int nb=b+dir[i].se;
        if(0<=na && na<=1 && 0<=nb && nb<n && !visited[na][nb] && datas[na][nb]=='.'){
            DFS(na,nb);
        }
    }
}

void Solve(){
    cin>>n;
    cin>>datas[0];
    cin>>datas[1];
    fill(visited[0],visited[0]+n,0);
    fill(visited[1],visited[1]+n,0);
    int cnt=0;
    fill(nums,nums+4,0);
    rng(i,0,1) rng(j,0,n-1) if(datas[i][j]=='.' && !visited[i][j]){
        cnt++;
        DFS(i,j);
    }
    //cout<<"CNT : "<<cnt<<'\n';
    if(cnt>4){
        cout<<0<<'\n';
    }
    else if(cnt==4){
        int res=0;
        rng(i,0,3) if(nums[i]==1) res++;
        cout<<res<<'\n';
    }
    else{
        rng(i,0,1){
            rng(j,0,n-1){
                if(datas[i][j]=='x') continue;
                if(nums[comnum[i][j]]==1) continue;
                cutcnt[i][j]=0;
                if(datas[1-i][j]=='x'){
                    int a1=i;
                    int b1=j+1;
                    int a2=i;
                    int b2=j-1;
                    if(0<=a1 && a1<=1 && 0<=b1 && b1<n && datas[a1][b1]=='.'){
                        if(0<=a2 && a2<=1 && 0<=b2 && b2<n && datas[a2][b2]=='.'){
                            cutcnt[i][j]=1;
                        }
                    }   
                }
                else{
                    bool flag=1;
                    cutcnt[i][j]=0;
                    rng(k,0,3){
                        int a1=i+dir[k].fi;
                        int b1=j+dir[k].se;
                        int a2=i+dir[(k+1)%4].fi;
                        int b2=j+dir[(k+1)%4].se;
                        ////cout<<" ? "<<a1<<' '<<b1<<' '<<a2<<' '<<b2<<'\n';
                        if(0<=a1 && a1<=1 && 0<=b1 && b1<n && datas[a1][b1]=='.'){
                            if(0<=a2 && a2<=1 && 0<=b2 && b2<n && datas[a2][b2]=='.'){
                                int na=a1+a2-i;
                                int nb=b1+b2-j;
                                ////cout<<"no?\n";
                                if(datas[na][nb]=='x') cutcnt[i][j]++;
                            }
                        }
                    }
                }
                //cout<<i<<' '<<j<<' '<<cutcnt[i][j]<<'\n';
            }
        }
        if(cnt==3){
            int res=0;
            rng(i,0,1){
                rng(j,0,n-1){
                    if(datas[i][j]=='x') continue;
                    if(nums[comnum[i][j]]==1) continue;
                    if(cutcnt[i][j]==0) res++;
                }
            }
            cout<<res<<'\n';
        }
        if(cnt==2){
            int res=0;
            rng(i,0,1){
                rng(j,0,n-1){
                    if(datas[i][j]=='x') continue;
                    if(nums[comnum[i][j]]==1) continue;
                    if(cutcnt[i][j]==1) res++;
                }
            }
            cout<<res<<'\n';
        }
        if(cnt==1){
            int res=0;
            rng(i,0,1){
                rng(j,0,n-1){
                    if(datas[i][j]=='x') continue;
                    if(nums[comnum[i][j]]==1) continue;
                    if(cutcnt[i][j]==2) res++;
                }
            }
            cout<<res<<'\n';
        }
        else{
            cout<<0<<'\n';
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    dir.pb({-1,0});
    dir.pb({0,1});
    dir.pb({1,0});
    dir.pb({0,-1});
    while(t--){
        Solve();
    }
    return 0;
}

