
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

pii opivot[4];
pii pivot[4]; 
int mp[1001][1001];
int res[1001][1001];
string s;
int n;

pii get_ori(int r, int c){
    rng(j,0,3){
        if((pivot[j].fi-r)%2==0 && (pivot[j].se-c)%2==0){
            //cout<<"okay "<<j<<'\n';
            int ni=((r-(pivot[j].fi-opivot[j].fi))%n+n)%n;
            int nj=((c-(pivot[j].se-opivot[j].se))%n+n)%n;
            return {ni,nj};
        }
    }
    assert(false);
    return {-1,-1};
}

void Solve(){
    pivot[0]={0,0};
    pivot[1]={0,1};
    pivot[2]={1,0};
    pivot[3]={1,1};
    rng(i,0,3) opivot[i]=pivot[i];
    int q;
    cin>>n>>q;
    rng(i,0,n-1){
        rng(j,0,n-1) mp[i][j]=i*n+j+1;
    }
    rng(i,0,q-1){
        cin>>s;
        if(s[0]=='S'){
            int r1, r2, c1, c2;
            cin>>r1>>c1>>r2>>c2;
            r1--, c1--, r2--, c2--;
            //cout<<r1<<' '<<c1<<' '<<r2<<' '<<c2<<'\n';

            // 지금의 r1, c1을 원래의 r1_o, c1_o로 환산. 거기서 교환을 한다.
            auto p1=get_ori(r1,c1);
            auto p2=get_ori(r2,c2);
            //cout<<"pre "<<p1.fi<<' '<<p1.se<<' '<<p2.fi<<' '<<p2.se<<'\n';
            swap(mp[p1.fi][p1.se],mp[p2.fi][p2.se]);
            continue;
        }
        if(s[0]=='R' && s[1]=='O'){
            rng(j,0,3) if(pivot[j].fi%2==0) pivot[j].se++;
        }
        if(s[0]=='R' && s[1]=='E'){
            rng(j,0,3) if(pivot[j].fi%2==1) pivot[j].se++;
        }
        if(s[0]=='C' && s[1]=='O'){
            rng(j,0,3) if(pivot[j].se%2==0) pivot[j].fi++;
        }
        if(s[0]=='C' && s[1]=='E'){
            rng(j,0,3) if(pivot[j].se%2==1) pivot[j].fi++;
        }    
    }
    rng(i,0,n-1){
        rng(j,0,n-1){
            if(i%2==0 && j%2==0){
                int ni=((i+pivot[0].fi-opivot[0].fi)%n+n)%n;
                int nj=((j+pivot[0].se-opivot[0].se)%n+n)%n;
                res[ni][nj]=mp[i][j];
            }
            else if(i%2==0 && j%2==1){
                int ni=((i+pivot[1].fi-opivot[1].fi)%n+n)%n;
                int nj=((j+pivot[1].se-opivot[1].se)%n+n)%n;
                res[ni][nj]=mp[i][j];
            }
            else if(i%2==1 && j%2==0){
                int ni=((i+pivot[2].fi-opivot[2].fi)%n+n)%n;
                int nj=((j+pivot[2].se-opivot[2].se)%n+n)%n;
                res[ni][nj]=mp[i][j];
            }
            else{
                int ni=((i+pivot[3].fi-opivot[3].fi)%n+n)%n;
                int nj=((j+pivot[3].se-opivot[3].se)%n+n)%n;
                res[ni][nj]=mp[i][j];
            }
        }
    }
    rng(i,0,n-1){
        rng(j,0,n-1) cout<<res[i][j]<<' ';
        cout<<'\n';
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

