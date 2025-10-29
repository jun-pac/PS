
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

string mps[N];
vc<bool> visited[N];
array<int,5> comps[N];

pair<pii,int> swp[N];

pii dir[4];
int n,m;
int isum[N], jsum[N];

array<int,5> DFS(int i, int j){
    int imx=i, imn=i;
    int jmx=j, jmn=j;
    int num=1;
    visited[i][j]=1;
    rng(k,0,3){
        int ni=i+dir[k].fi;
        int nj=j+dir[k].se;
        if(0<=ni && ni<n && 0<=nj && nj<m && mps[ni][nj]=='#' && !visited[ni][nj]){
            array<int,5> res=DFS(ni, nj);
            num+=res[0];
            imx=max(imx,res[1]);
            imn=min(imn,res[2]);
            jmx=max(jmx,res[3]);
            jmn=min(jmn,res[4]);
        }
    }
    return {num,imx,imn,jmx,jmn};
}

void Solve(){
    cin>>n>>m;
    rng(i,0,n-1){
        cin>>mps[i];
    }
    fill(isum,isum+n,0);
    fill(jsum,jsum+m,0);
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(mps[i][j]=='#'){
                isum[i]++;
                jsum[j]++;
            }
        }
    }

    rng(i,0,n-1){
        visited[i].clear();
        visited[i].resize(m,false);
    }
    int num=0;
    ll mx=0;
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(!visited[i][j] && mps[i][j]=='#'){
                comps[num++]=DFS(i,j);
                // rng(k,0,4) cout<<comps[num-1][k]<<' ';
                // cout<<'\n';
                mx=max(mx,(ll)comps[num-1][0]);
            }
        }
    }


    priority_queue<pii> pq; // {{i or j}mx, num}
    int idx=0;
    ll sum=0;

    // i-swipping
    rng(i,0,num-1){
        swp[i]={{comps[i][2],comps[i][1]},comps[i][0]}; // mn, mx, cnt
    }
    sort(swp,swp+num);
    while(!pq.empty()) pq.pop();
    idx=0;
    sum=0;

    rng(i,0,n-1){
        while(idx<num && swp[idx].fi.fi<=i+1){
            pq.push({-swp[idx].fi.se, swp[idx].se}); // -mx, cnt
            sum+=swp[idx].se; // num
            idx++;
        }
        while(!pq.empty()){
            pii temp=pq.top();
            if(-temp.fi<i-1){
                pq.pop();
                sum-=temp.se;
            }
            else break;
        }
        ll val=sum+m-isum[i];     
        // cout<<"i sw "<<i<<' '<<val<<'\n';   
        mx=max(val,mx);
    }

    // y-swipping
    rng(i,0,num-1){
        swp[i]={{comps[i][4],comps[i][3]},comps[i][0]}; // mn, mx, cnt
    }
    sort(swp,swp+num);
    while(!pq.empty()) pq.pop();
    idx=0;
    sum=0;

    rng(i,0,m-1){
        while(idx<num && swp[idx].fi.fi<=i+1){
            pq.push({-swp[idx].fi.se, swp[idx].se}); // -mx, cnt
            sum+=swp[idx].se; // num
            idx++;
        }
        while(!pq.empty()){
            pii temp=pq.top();
            if(-temp.fi<i-1){
                pq.pop();
                sum-=temp.se;
            }
            else break;
        }
        ll val=sum+n-jsum[i];       
        // cout<<"j sw "<<i<<' '<<val<<'\n'; 
        mx=max(val,mx);
    }

    cout<<mx<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    dir[0]={-1,0};
    dir[1]={1,0};
    dir[2]={0,-1};
    dir[3]={0,1};

    while(t--){
        Solve();
    }
    return 0;
}

