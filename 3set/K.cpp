
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

int col[N];
ll n,k,p;
ll m;
int last[N];
int icnt[N];
bool colflag[N];

bool init_check(){
    rng(i,0,m-1){
        icnt[col[i]]++;
        if(i-last[col[i]] < p) return false;
        last[col[i]]=i;
    }
    if(k<p && n>k) return false;
    return true;
}

void Solve(){
    cin>>n>>k>>p; // p for spacing, k for color
    cin>>m;
    rng(i,0,m-1){
        cin>>col[i];
        col[i]--;
    }   

    fill(last,last+k,-p);
    fill(icnt,icnt+k,0);

    if(!init_check()){
        cout<<"impossible\n";
        return;
    }

    priority_queue<pii> pq; //{-cnt, colidx}
    fill(colflag,colflag+k,1);
    rng(i,(int)max(0LL,m-p+1),m-1){
        // cout<<"i "<<i<<'\n';
        colflag[col[i]]=0;
        // cout<<"?\n";
    }
    rng(i,0,k-1){
        if(colflag[i]){
            pq.push({-icnt[i],i});
        }
    }
    // cout<<"sz "<<pq.size()<<"\n"; 
    rng(i,0,m-1) cout<<col[i]+1<<' ';
    rng(i,m,n-1){
        // assert(pq.size()>0);
        pii temp=pq.top();
        pq.pop();
        icnt[temp.se]++;
        col[i]=temp.se;
        cout<<temp.se+1<<' ';
        if(i<p-1) continue;
        pq.push({-icnt[col[i-p+1]],col[i-p+1]});
        // pq.push({temp.fi-1,temp.se});
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

