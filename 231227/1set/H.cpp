
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 1030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N], r_edges[N];// a->b
int out_d[N]; // # of outdegree
int parent[N];
int find(int a){
    return parent[a]=(a==parent[a]?a:find(parent[a]));
}
void union_c(int a, int b){ 
    parent[find(a)]=find(b);
}

bool rels[N][N];
bool visited[N];
vc<int> group[N];
vc<pii> ans;

bool check(int gidx){
    bool flag=0;
    vc<pii> temp;
    stack<int> st;
    int n=group[gidx].size();
    
    //cout<<"group "<<gidx<<'\n';
    if(n==1) return true;
    
    rng(i,0,n-1){
        int cnt=0; //현재까지 만들어진 edge의 개수
        int idx=group[gidx][i]; // idx가 지우는 원소가 되는 것.
        int prev=idx;
        if(edges[idx].size()!=0) continue;

        temp.clear();
        while(!st.empty()) st.pop();
        
        rng(j,0,n-1) out_d[group[gidx][j]]=edges[group[gidx][j]].size(); 
        rng(j,0,(int)r_edges[idx].size()-1) out_d[r_edges[idx][j]]--;
        rng(j,0,n-1){
            int next=group[gidx][j];
            if(next!=idx && out_d[next]==0) st.push(next);
        }
        while(!st.empty()){
            int next=st.top();
            cnt++;
            temp.pb({next,prev});
            prev=next;
            st.pop();
            rng(j,0,(int)r_edges[next].size()-1){
                out_d[r_edges[next][j]]--;
                if(r_edges[next][j]!=idx && out_d[r_edges[next][j]]==0) st.push(r_edges[next][j]);
            }
        }
        if(cnt==n-1){
            flag=1;
            break;
        }
    }
    if(flag){
        rng(i,0,n-2) ans.pb(temp[n-2-i]);
        return true;
    }

    rng(i,0,n-1){
        int cnt=0; //현재까지 만들어진 edge의 개수
        int idx=group[gidx][i]; // idx가 지우는 원소가 되는 것.
        int prev=idx;
        temp.clear();
        while(!st.empty()) st.pop();
        
        rng(j,0,n-1) out_d[group[gidx][j]]=edges[group[gidx][j]].size(); 
        //rng(j,0,n-1) cout<<group[gidx][j]+1<<' '; cout<<'\n';

        rng(j,0,(int)r_edges[idx].size()-1){
            out_d[r_edges[idx][j]]--;
        }
        rng(j,0,n-1){
            int next=group[gidx][j];
            if(next!=idx && out_d[next]==0) st.push(next);
        }
        while(!st.empty()){
            int next=st.top();
            cnt++;
            temp.pb({next,prev});
            prev=next;
            st.pop();
            rng(j,0,(int)r_edges[next].size()-1){
                out_d[r_edges[next][j]]--;
                if(r_edges[next][j]!=idx && out_d[r_edges[next][j]]==0) st.push(r_edges[next][j]);
            }
        }
        if(cnt==n-1){
            flag=1;
            temp.pb({idx,prev});
            break;
        }
    }
    if(!flag) return false;
    else{
        rng(i,0,n-1) ans.pb(temp[n-1-i]);
        return true;
    }   
}

void Solve(){
    int n,m,a,b;
    cin>>n>>m;
    
    rng(i,0,n-1) parent[i]=i; 
    rng(i,0,m-1){
        cin>>a>>b;
        a--, b--;
        if(rels[a][b]) continue;
        rels[a][b]=1;
        edges[a].pb(b);
        r_edges[b].pb(a);
        union_c(a,b);
    }   
    int g=0;
    rng(i,0,n-1){
        if(visited[i]) continue;
        rng(j,i,n-1){
            if(find(i)==find(j)){
                visited[j]=true;
                group[g].pb(j);
            }
        }
        g++;
    }

    bool flag=1;
    rng(i,0,g-1){
        if(!check(i)){
            flag=0;
            break;
        }
    }
    if(!flag) cout<<-1<<'\n';
    else{
        cout<<ans.size()<<'\n';
        rng(i,0,(int)ans.size()-1){
            cout<<ans[i].fi+1<<' '<<ans[i].se+1<<'\n';
        }
    }

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

