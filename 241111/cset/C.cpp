
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 

vc<int> edgesa[N];
vc<int> edgesb[N];
int anum[N], bnum[N]; // %k num
int at[N], bt[N]; // type. 0 for in
bool visited[N];
int k;
int acnt[N], bcnt[N];

void DFSa(int idx, int d){
    if(visited[idx]) return;
    visited[idx]=1;
    anum[idx]=d;
    for(int next : edgesa[idx]){
        if(!visited[next]) DFSa(next, (d+1)%k);
    }
}

void DFSb(int idx, int d){
    if(visited[idx]) return;
    visited[idx]=1;
    bnum[idx]=d;
    for(int next : edgesb[idx]){
        if(!visited[next]) DFSb(next, (d+1)%k);
    }
}

int phi[N];
vector<int> match_res;

void get_phi(){
    int m=k;
    phi[0]=0;
    for(int i=1, j=0; i<m; i++){
        while(j>0 && bcnt[i]!=bcnt[j]) j=phi[j-1];
        if(bcnt[i]==bcnt[j]) j++;
        phi[i]=j;
    }
}

void KMP(){
    int n=2*k, m=k;
    match_res.clear();
    for(int i=0, j=0; i<n; i++){
        while(j!=0 && acnt[i]!=bcnt[j]) j=phi[j-1];
        if(acnt[i]==bcnt[j]) j++;
        if(j==m) match_res.push_back(i+1-m), j=phi[j-1];
    }
}

void Solve(){
    int n,m;
    cin>>n>>k;
    rng(i,0,n-1) edgesa[i].clear();
    rng(i,0,n-1) edgesb[i].clear();

    rng(i,0,n-1) cin>>at[i];
    cin>>m;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edgesa[a].pb(b);
    }
    fill(visited,visited+n,0);
    DFSa(0,0);

    rng(i,0,n-1) cin>>bt[i];
    cin>>m;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edgesb[a].pb(b);
    }
    fill(visited,visited+n,0);
    DFSb(0,0);

    int aout=0, bout=0;
    rng(i,0,n-1) aout+=at[i];
    rng(i,0,n-1) bout+=bt[i];
    if(n-aout!=bout){
        cout<<"No\n";
        return;
    }
    if(aout==n || aout==0){
        cout<<"Yes\n";
        return;
    }

    // // ain 들의 cnt histogram을 k만큼 shift해서 bout과 동일
    // // aout 들의 cnt histogram을 k만큼 shift해서 bin과 동일하게 할 수 있어야 함
    fill(acnt,acnt+k,0);
    rng(i,0,n-1) if(at[i]) acnt[anum[i]]++;
    rng(i,0,k-1) acnt[i+k]=acnt[i];
    fill(bcnt,bcnt+k,0);
    rng(i,0,n-1) if(!bt[i]) bcnt[bnum[i]]++;
    get_phi();
    KMP();
    vc<int> res1(match_res);


    fill(acnt,acnt+k,0);
    rng(i,0,n-1) if(!at[i]) acnt[anum[i]]++;
    rng(i,0,k-1) acnt[i+k]=acnt[i];
    fill(bcnt,bcnt+k,0);
    rng(i,0,n-1) if(bt[i]) bcnt[bnum[i]]++;
    get_phi();
    KMP();
    
    vc<int> res2;
    rng(i,0,(int)(match_res.size())-1) res2.push_back((match_res[i]-2+k)%k);


    int i=0, j=0;
    sort(all(res1));
    sort(all(res2));
    while(i<res1.size() && j<res2.size()){
        if(res1[i]==res2[j]){
            cout<<"Yes\n";
            return;
        }
        else if(res1[i]<res2[j]) i++;
        else j++;
    }   
    cout<<"No\n"; 
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

