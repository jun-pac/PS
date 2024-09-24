
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

pair<double,double> pos[N];
double r[N];
priority_queue<pair<double,pii>> pq;
int parent[N];
int find(int idx){
	if(idx==parent[idx]) return idx;
	return parent[idx]=find(parent[idx]);
}
void c_union(int a, int b){
	a=find(a), b=find(b);
	parent[b]=a;
}

double get_dist(int i, int j){
    double d=sqrt((pos[i].fi-pos[j].fi)*(pos[i].fi-pos[j].fi)+(pos[i].se-pos[j].se)*(pos[i].se-pos[j].se));
    double r1=r[i];
    double r2=r[j];
    if(d<=r1+r2+0.0000000001) return 0;
    double sd=sqrt(d*d-(r1-r2)*(r1-r2));
    if(r1>r2) swap(r1,r2);
    double theta=acos((r2-r1)/d);
    return r2*(2*M_PI-2*theta)+2*sd+2*r1*theta;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>pos[i].fi>>pos[i].se>>r[i];
    }
    rng(i,0,n-1){
        rng(j,i+1,n-1){
            //cout<<i<<' '<<j<<' '<<get_dist(i,j)<<'\n';
            pq.push({-get_dist(i,j),{i,j}});
        }
    }
    rng(i,0,n-1) parent[i]=i;
    double res=0;
    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        if(find(temp.se.fi)!=find(temp.se.se)){
            res+=(-temp.fi);
            c_union(temp.se.fi,temp.se.se);
        }
    }
    cout<<fixed;
    cout.precision(12);
    cout<<res<<'\n';
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

