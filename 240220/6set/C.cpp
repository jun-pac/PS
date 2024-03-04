
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

string mp[505];
pii dir[200];

void Solve(){
    int h,w,n;
    cin>>h>>w>>n;
    dir['U']={-1,0};
    dir['D']={1,0};
    dir['R']={0,1};
    dir['L']={0,-1};
    string p;
    cin>>p;
    int mxx=0, mnx=0, mxy=0, mny=0;
    int x=0, y=0;
    rng(i,0,n-1){
        x+=dir[p[i]].fi;
        y+=dir[p[i]].se;
        mxx=max(mxx,x);
        mnx=min(mnx,x);
        mxy=max(mxy,y);
        mny=min(mny,y);
    }
    assert(p.size()==n);
    rng(i,0,h-1) cin>>mp[i];
    int res=0;
    rng(i,1,h-2){
        rng(j,1,w-2){
            if(mp[i][j]=='.' && i+mxx<h-1 && i+mnx>0 && j+mxy<w-1 && j+mny>0){
                bool flag=1;
                int x=i, y=j;
                rng(k,0,n-1){
                    x+=dir[p[k]].fi;
                    y+=dir[p[k]].se;
                    if(mp[x][y]=='#'){
                        flag=0;
                        break;
                    }
                }
                if(flag) res++;
            }
        }
    }
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

