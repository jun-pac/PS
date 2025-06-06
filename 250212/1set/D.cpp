
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

string datas[1000];
array<int,3> s[2], t[2];
int dist[2000002];
int n,m;
#define MIL 1000000

void Solve(){
    cin>>n>>m;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(datas[i][j]=='S'){
                s[0]={i,j,0};
                s[1]={i,j,1}; 
            }
            else if(datas[i][j]=='G'){
                t[0]={i,j,0};
                t[1]={i,j,1}; 
            }
        }
    }
    // i*m+j+MIL*dir
    queue<array<int,3>> q;
    fill(dist, dist+2*MIL, INF);
    q.push(s[0]);
    q.push(s[1]);
    dist[s[0][0]*m+s[0][1]+MIL*s[0][2]]=0;
    dist[s[1][0]*m+s[1][1]+MIL*s[1][2]]=0;
    // cout<<s[0][0]<<' '<<s[0][1]<<'\n';

    while(!q.empty()){
        array<int,3> temp=q.front();
        q.pop();
        int i=temp[0];
        int j=temp[1];
        int k=temp[2]; // 0 if horizontal
        int idx=i*m+j+MIL*k;
        // cout<<"cur "<<i<<' '<<j<<' '<<k<<' '<<idx<<' '<<dist[idx]<<'\n';
        if(datas[i][j]=='G'){
            cout<<dist[idx]<<'\n';
            return;
        }
        if(k==0){
            int ni=i-1;
            int nj=j;
            int nk=1-k;
            int nidx=ni*m+nj+nk*MIL;
            if(0<=ni && ni<n && dist[nidx]==INF && (datas[ni][nj]=='.'||datas[ni][nj]=='G')){
                dist[nidx]=dist[idx]+1;
                q.push({ni,nj,nk});
            }
            ni=i+1;
            nj=j;
            nk=1-k;
            nidx=ni*m+nj+nk*MIL;
            if(0<=ni && ni<n && dist[nidx]==INF && (datas[ni][nj]=='.'||datas[ni][nj]=='G')){
                dist[nidx]=dist[idx]+1;
                q.push({ni,nj,nk});
            }
        }
        else{
            int ni=i;
            int nj=j-1;
            int nk=1-k;
            int nidx=ni*m+nj+nk*MIL;
            if(0<=nj && nj<m && dist[nidx]==INF && (datas[ni][nj]=='.'||datas[ni][nj]=='G')){
                dist[nidx]=dist[idx]+1;
                q.push({ni,nj,nk});
            }
            ni=i;
            nj=j+1;
            nk=1-k;
            nidx=ni*m+nj+nk*MIL;
            if(0<=nj && nj<m && dist[nidx]==INF && (datas[ni][nj]=='.'||datas[ni][nj]=='G')){
                dist[nidx]=dist[idx]+1;
                q.push({ni,nj,nk});
            }
        }
    }
    cout<<-1<<'\n';
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

