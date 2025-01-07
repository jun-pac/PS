
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


int a[N], b[N], last_pos[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    bool ff=1;
    rng(i,0,n-1) if(a[i]!=b[i]) ff=0;
    if(ff){
        cout<<"Yes\n";
    }
    else if(k==1){
        vc<int> anum;
        int last=-1;
        rng(i,0,n-1){
            if(a[i]!=last){
                last=a[i];
                anum.pb(a[i]);
            }
        }
        bool flag=1;
        last=-1;
        int cur=0;
        int asz=anum.size();
        rng(i,0,n-1){
            if(b[i]!=last){
                while(cur<asz && anum[cur]!=b[i]) cur++;
                if(cur==asz){
                    flag=0;
                    break;
                }
                else cur++;
                last=b[i];
            }
        }
        cout<<(flag?"Yes\n":"No\n");
    }
    else{
        set<int> aset,bset;
        rng(i,0,n-1) aset.insert(a[i]);
        bool flag=1;
        rng(i,0,n-1){
            if(aset.find(b[i])==aset.end()){
                flag=0;
                break;
            }
            bset.insert(b[i]);
        }
        if(!flag || (int)bset.size()==n) cout<<"No\n";
        else{
            // 거리 k이하인 같은 원소가 있어야 함.
            fill(last_pos,last_pos+n+1,-1);
            int mn=INF;
            rng(i,0,n-1){
                if(last_pos[b[i]]!=-1) mn=min(mn,i-last_pos[b[i]]);
                last_pos[b[i]]=i;
            }
            if(mn<=k) cout<<"Yes\n";
            else cout<<"No\n";
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

