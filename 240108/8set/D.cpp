
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

ll datas[N], nnext[N], pprev[N];
int cnt[N];
bool visited[N];



priority_queue<pii> pq;
    
void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    while(!pq.empty()) pq.pop();
    bool flag=1;
    rng(i,0,n-1){
        nnext[i]=i+1;
        pprev[i]=i-1;
    }
    rng(i,0,n-1){
        pq.push({datas[i],-i}); // 기왕 가장 앞으로 합시다
    }   
    fill(visited,visited+n,0);
    while(!pq.empty()){
        pii cur=pq.top();
        pq.pop();
        int idx=-cur.se;
        if(datas[idx]==0){
            if(pq.size()==0){
                break;
            }
            else{
                flag=0;
                break;
            }
        }
        if(visited[idx]) continue;
        //cout<<"visit "<<idx<<'\n';
        int nextidx=idx;
        while(nnext[nextidx]!=n && datas[nextidx]==datas[idx]){
            visited[nextidx]=1;
            nextidx=nnext[nextidx];
        }
        bool rok=(nextidx!=n && datas[nextidx]==datas[idx]-1);
        bool lok=(pprev[idx]!=-1 && datas[pprev[idx]]==datas[idx]-1);

        if(!(rok||lok)){
            flag=0;
            break;
        }
        if(pprev[idx]!=-1) nnext[pprev[idx]]=nextidx;
        if(nextidx!=n) pprev[nextidx]=pprev[idx];
    }
    cout<<(flag?"YES\n":"NO\n");
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

