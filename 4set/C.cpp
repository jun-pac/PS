
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


pii datas[N];
int ab[N], ba[N], aidx[N]; 

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi;
    rng(i,0,n-1) cin>>datas[i].se;
    rng(i,0,n-1){
        datas[i].fi--;
        datas[i].se--;
    }
    rng(i,0,n-1) ab[datas[i].fi]=datas[i].se;
    rng(i,0,n-1) ba[datas[i].se]=datas[i].fi;
    rng(i,0,n-1) aidx[datas[i].fi]=i;

    int cnt=0;
    rng(i,0,n-1){
        // cout<<i<<' '<<ab[i]<<' '<<ba[ab[i]]<<'\n';
        if(ab[ab[i]]!=i){
            cout<<-1<<'\n';
            return;
        }
        if(ab[i]==i) cnt++;
    }

    vc<pii> ans;
    if(n%2==0){
        if(cnt!=0){
            cout<<-1<<'\n';
            return;
        }
        rng(i,0,n/2-1){
            int aval=datas[i].fi;
            assert(datas[i].fi!=datas[i].se);

            int bidx=aidx[ab[aval]];
            assert(datas[bidx].fi!=datas[bidx].se);
            if(bidx!=n-1-i){
                ans.pb({bidx,n-1-i});
                swap(aidx[datas[bidx].fi], aidx[datas[n-1-i].fi]);
                swap(datas[bidx],datas[n-1-i]);
            }
        }
    }
    else{
        if(cnt!=1){
            cout<<-1<<'\n';
            return;
        }
        rng(i,0,n-1){
            if(datas[i].fi==datas[i].se){
                if(i!=n/2){
                    ans.pb({i,n/2});
                    swap(aidx[datas[i].fi], aidx[datas[n/2].fi]);
                    swap(datas[i],datas[n/2]);
                }
                break;
            }
        }
        rng(i,0,n/2-1){
            int aval=datas[i].fi;
            assert(datas[i].fi!=datas[i].se);

            int bidx=aidx[ab[aval]];
            assert(datas[bidx].fi!=datas[bidx].se);
            if(bidx!=n-1-i){
                ans.pb({bidx,n-1-i});
                swap(aidx[datas[bidx].fi], aidx[datas[n-1-i].fi]);
                swap(datas[bidx],datas[n-1-i]);
            }
        }
    }

    cout<<ans.size()<<'\n';
    rng(i,0,(int)ans.size()-1){
        cout<<ans[i].fi+1<<' '<<ans[i].se+1<<'\n';
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

