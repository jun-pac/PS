
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

pll datas[N];
vc<pll> comp;
ll n,m,a,b; // a,b<=20
int pcnt;

int DP[22];


void Solve(){
    cin>>n>>m>>a>>b; // n<=1000000000000, so can't use naive DP.
    rng(i,0,m-1) cin>>datas[i].fi>>datas[i].se;
    // datas is not overlap, but it can be touched with each others.
    ll last=datas[0].fi;
    rng(i,0,m-1){
        if(i==m-1 || datas[i].se!=datas[i+1].fi-1){
            pll temp={last,datas[i].se};
            comp.pb(temp);
            if(i!=m-1) last=datas[i+1].fi;
        }
    }
    bool flag=1;
    m=comp.size();
    rng(i,0,m-1){
        if(comp[i].se-comp[i].fi>=b){
            flag=0;
            break;
        }
    }
    // cout<<"debug\n";
    // rng(i,0,m-1) cout<<comp[i].fi<<' '<<comp[i].se<<'\n';

    if(!flag){
        cout<<"No\n";
        return;
    }

    if(a==b){
        // bk+1
        if(n%b!=1%b){
            cout<<"No\n";
            return;
        }
        rng(k,0,m-1){
            ll r=comp[k].se+1;
            while(r%b!=1%b) r++;

            ll l=comp[k].fi-1;
            while(l>0 && l%b!=1%b) l--;
            if(r!=l+b){
                cout<<"No\n";
                return;
            }
            if(k!=m-1 && r>=comp[k+1].fi){
                cout<<"No\n";
                return;
            }
            if(k!=0 && l<=comp[k-1].se){
                cout<<"No\n";
                return;
            }
            if(k==m-1 && r>n){
                cout<<"No\n";
                return;
            }
            if(k==0 && l<=0){
                cout<<"No\n";
                return;
            }
        }
        cout<<"Yes\n";
        return;
    }

    fill(DP,DP+b,0);
    ll cur=1;
    DP[1%b]=1;
    cur++;
    pcnt=1;
        
    rng(k,0,m-1){
        assert(comp[k].se-comp[k].fi<=b);
        // int temp=0;
        while(cur<comp[k].fi){
            if(DP[cur%b]){
                cur++;
                continue;
            }
            rng(j,1,b-a){
                if(DP[(cur+j)%b]){
                    DP[cur%b]=1;
                    break;
                }
            }
            pcnt+=DP[cur%b];
            // cout<<cur<<' '<<DP[cur%b]<<' '<<pcnt<<'\n';
            if(pcnt==b) break;
            if(pcnt==0){
                cout<<"No\n";
                return;
            }
            cur++;
            // temp++;
            // assert(temp<500);
        }
        cur=comp[k].fi;
        while(cur<=comp[k].se){
            pcnt-=DP[cur%b];
            DP[cur%b]=0;
            cur++;
        }
        if(pcnt==0){
            cout<<"No\n";
            return;
        }
    }
    while(cur<=n){
        // int temp=0;
        if(DP[cur%b]){
            cur++;
            continue;
        }
        rng(j,1,b-a){
            if(DP[(cur+j)%b]){
                DP[cur%b]=1;
                break;
            }
        }
        pcnt+=DP[cur%b];
        // cout<<cur<<' '<<DP[cur%b]<<' '<<pcnt<<'\n';
        if(pcnt==b) break;
        if(pcnt==0){
            cout<<"No\n";
            return;
        }
        cur++;
        // temp++;
        // assert(temp<500);
    }
    cout<<(DP[n%b]?"Yes\n":"No\n");

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

