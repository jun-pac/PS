
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

vc<int> datas[N];
vc<int> pos[N];
set<int> st;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) datas[i].clear();
    rng(i,0,n-1) pos[i].clear();
    st.clear();
    rng(i,0,n-1){
        datas[i].resize(m);
        rng(j,0,m-1) cin>>datas[i][j];
        rng(j,0,m-2) if(datas[i][j]>datas[i][j+1]){
            pos[i].pb(j);
            st.insert(j);
        }
    }
    if(st.size()>2){
        cout<<-1<<'\n';
    }
    else if(st.size()==2){
        int a=*(st.begin()), b=*(next(st.begin()));
        bool flag=1;
        rng(i,0,n-1) swap(datas[i][a],datas[i][b+1]);
        rng(i,0,n-1){
            rng(j,0,m-2) if(datas[i][j]>datas[i][j+1]) flag=0;
        }
        if(!flag) cout<<-1<<'\n';
        else cout<<a+1<<' '<<b+2<<'\n';
    }
    else if(st.size()==1){
        int midx=*(st.begin());
        bool flag=1;
        int l=-1, r=-1;
        rng(i,0,n-1){
            if(pos[i].size()!=1) continue;
            int templ=lower_bound(datas[i].begin(),datas[i].begin()+midx+1,datas[i][midx])-datas[i].begin();
            int tempr=upper_bound(datas[i].begin()+midx+1,datas[i].end(),datas[i][midx+1])-datas[i].begin();
            tempr--;
            if(l==-1) l=templ;
            else if(l!=templ) flag=0;
            if(r==-1) r=tempr;
            else if(r!=tempr) flag=0;
        }
        if(l!=midx && r!=midx+1) flag=0;
        if(!flag) cout<<-1<<'\n';
        else{
            int a=l, b=r;
            rng(i,0,n-1) swap(datas[i][a],datas[i][b]);
            rng(i,0,n-1){
                rng(j,0,m-2) if(datas[i][j]>datas[i][j+1]) flag=0;
            }
            if(!flag)cout<<-1<<'\n';
            else cout<<a+1<<' '<<b+1<<'\n';
        }
    }
    else{
        cout<<1<<' '<<1<<'\n';
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

