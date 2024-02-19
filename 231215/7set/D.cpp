
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

pair<pii,pii> qs[N];
map<pair<int,int>,int> pos; // pos->num mapping
vc<int> posidx[N]; // 위의 map을 통해 접근해서, 그것이 각각 어느 위치에 나왔는지
pii seq[N];

void Solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int x=0,y=0;
    int cntp=1, cntn=1;
    pos[{x,y}]=1;
    posidx[1].pb(0);
    seq[0]={0,0};

    rng(i,0,n-1){
        if(s[i]=='U') y++;
        if(s[i]=='D') y--;
        if(s[i]=='L') x--;
        if(s[i]=='R') x++;
        seq[i+1]={x,y};
        if(pos[{x,y}]==0){
            cntp++;
            pos[{x,y}]=cntp;
        }
        posidx[pos[{x,y}]].pb(i+1); // 정렬돼있음
    }

    rng(i,0,q-1){
        int l,r;
        cin>>x>>y>>l>>r;
        l--, r--;
        bool finded=0;
        pii T=seq[l], S=seq[r+1];
        if(pos[{x,y}]!=0){
            // [0,l], [r+1,n]에서는 (x,y)를 찾는다.
            int pp=pos[{x,y}];
            if(posidx[pp][0]<=l){
                cout<<"YES"<<'\n';
                finded=1;
            }
            else{
                int fidx=lower_bound(posidx[pp].begin(),posidx[pp].end(),r+1)-posidx[pp].begin();
                if(fidx!=posidx[pp].size() && posidx[pp][fidx]<=n){
                    cout<<"YES"<<'\n';
                    finded=1;
                }
            }
            
        }
        if(!finded && pos[{T.fi+S.fi-x,T.se+S.se-y}]!=0){
            // [l+1, r]까지는 반대의 원소가 있는지 찾는다.
            int pp=pos[{T.fi+S.fi-x,T.se+S.se-y}];
            int fidx=lower_bound(posidx[pp].begin(),posidx[pp].end(),l+1)-posidx[pp].begin();
            if(fidx!=posidx[pp].size() && posidx[pp][fidx]<=r){
                cout<<"YES"<<'\n';
                finded=1;
            }
        }
        if(!finded){
            cout<<"NO"<<'\n';
        }

    }

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

