
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


int mx[N][11]; // [i][j] i idx기준 오른쪽에 넣을 개수
int visited[N];
int parent[N];

int find(int idx){
	if(idx==parent[idx]) return idx;
	return parent[idx]=find(parent[idx]);
}
void c_union(int a, int b){
	a=find(a), b=find(b);
	parent[b]=a;
}

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) fill(mx[i],mx[i]+11,0);
    rng(i,0,m-1){
        int a,k,d;
        cin>>a>>d>>k;
        a--;
        //assert(a+k*d<n);
        mx[a][d]=max(mx[a][d],k);
    }
    rng(i,0,n-1) parent[i]=i;
    rng(d,1,10){
        rng(i,0,n-1){
            if(mx[i][d]>0) c_union(i,i+d);
            if(i+d<n) mx[i+d][d]=max(mx[i+d][d],mx[i][d]-1);
        }
    }
    
    fill(visited,visited+n,0);
    int cnt=0;
    rng(i,0,n-1){
        int r=find(i);
        if(!visited[r]){
            visited[r]=1;
            cnt++;
        }
    }
    cout<<cnt<<'\n';

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

