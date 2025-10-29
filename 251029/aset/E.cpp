
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int parent[N];
int find_r(int x){
    return parent[x]=(x==parent[x]?x:find_r(parent[x]));
}


vc<int> comb[16], rcomb[16];
vc<int> conn[4];
pii datas[N];

int ctonum(char x){
    if(x=='R')return 0;
    if(x=='G')return 1;
    if(x=='B')return 2;
    return 3;
}



void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,3) conn[i].clear();
    // rng(i,0,n) edges[i].clear();
    rng(i,0,n-1) parent[i]=i;
    rng(i,0,15) comb[i].clear();
    rng(i,0,15) rcomb[i].clear();


    rng(i,0,n-1){
        string x;
        cin>>x;
        conn[ctonum(x[0])].pb(i);
        conn[ctonum(x[1])].pb(i);
        datas[i]={ctonum(x[0]),ctonum(x[1])};
        if(datas[i].fi>datas[i].se) swap(datas[i].fi, datas[i].se);
        int val=datas[i].fi*4+datas[i].se;
        comb[val].pb(i);
        rcomb[val].pb(-i);
    }
    rng(k,0,15) sort(all(rcomb[k]));
    

    rng(k,0,3){
        int m=conn[k].size();
        rng(i,0,m-2){
            // edges[conn[k][i]].pb({conn[k][i+1], conn[k][i+1]-conn[k][i]});
            // edges[conn[k][i+1]].pb({conn[k][i], conn[k][i+1]-conn[k][i]});
            int a=find_r(conn[k][i]);
            int b=find_r(conn[k][i+1]);
            if(a!=b) parent[a]=b;
        }
    }

    rng(i,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        if(find_r(a)!=find_r(b)){
            cout<<-1<<'\n';
        }
        else{
            if(datas[a].fi!=datas[b].fi && datas[a].fi!=datas[b].se && datas[a].se!=datas[b].fi && datas[a].se!=datas[b].se){
                int mn=INF;
                int val1=datas[a].fi*4+datas[a].se;
                int val2=datas[b].fi*4+datas[b].se;
                int pos, temp;
                rng(k,0,15){
                    if(k!=val1 && k!=val2){
                        temp=lower_bound(comb[k].begin(),comb[k].end(),min(a,b))-comb[k].begin();
                        if(temp<comb[k].size()){
                            pos=comb[k][temp];
                            // cout<<"right "<<k<<' '<<pos+1<<'\n';
                            mn=min(mn,abs(pos-a)+abs(pos-b));
                        }
                        temp=lower_bound(rcomb[k].begin(),rcomb[k].end(),-max(a,b))-rcomb[k].begin();
                        if(temp<rcomb[k].size()){
                            pos=-rcomb[k][temp];
                                                        // cout<<"left "<<k<<' '<<pos+1<<'\n';

                            mn=min(mn,abs(pos-a)+abs(pos-b));
                        }
                    }
                }
                cout<<mn<<'\n';
            }
            else{
                cout<<abs(a-b)<<'\n';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

