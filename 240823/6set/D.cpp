
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

string datas[N];
map<string,int> mp;
string rmp[6];
int r_close[6][N], l_close[6][N];

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    // rng(i,0,n-1) cout<<datas[i]<<'\n';
    rng(k,0,5){
        rng(i,0,n-1) l_close[k][i]=max((i==0?-1:l_close[k][i-1]),(datas[i][0]==rmp[k][0]&&datas[i][1]==rmp[k][1]?i:-1));
        gnr(i,n-1,0) r_close[k][i]=min((i==n-1?n:r_close[k][i+1]),(datas[i][0]==rmp[k][0]&&datas[i][1]==rmp[k][1]?i:n));
        // cout<<"cur : "<<rmp[k]<<' '<<mp[rmp[k]]<<'\n';
        // rng(i,0,n-1) cout<<l_close[k][i]<<' '; cout<<'\n';
        // rng(i,0,n-1) cout<<r_close[k][i]<<' '; cout<<'\n';
    }
    rng(i,0,q-1){
        int x,y;
        cin>>x>>y;
        x--, y--;
        if(x>y) swap(x,y);
        if(datas[x][0]==datas[y][0]||datas[x][0]==datas[y][1]||datas[x][1]==datas[y][0]||datas[x][1]==datas[y][1]){
            cout<<y-x<<'\n';
            continue;
        }
        else{
            int lc=-1, rc=n;
            rng(k,0,5){
                if(k==mp[datas[x]] || k==mp[datas[y]]) continue;
                //cout<<"visit "<<k<<' '<<rmp[k]<<' '<<datas[x]<<' '<<datas[y]<<'\n';
                lc=max(lc,l_close[k][y]);
                rc=min(rc,r_close[k][x]);
            }
            int res=INF;
            if(lc!=-1) res=min(res,abs(lc-x)+abs(lc-y));
            if(rc!=n) res=min(res,abs(rc-x)+abs(rc-y));
            if(res==INF) cout<<-1<<'\n';
            else cout<<res<<'\n';
        }
    } 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    mp["BG"]=0;
    mp["BR"]=1;
    mp["BY"]=2;
    mp["GR"]=3;
    mp["GY"]=4;
    mp["RY"]=5;
    
    rmp[0]="BG";
    rmp[1]="BR";
    rmp[2]="BY";
    rmp[3]="GR";
    rmp[4]="GY";
    rmp[5]="RY";
    

    while(t--){
        Solve();
    }
    return 0;
}

