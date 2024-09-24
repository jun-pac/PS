
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

ll mp[505][505];
string tp[505];
ll colsum[505][505];
ll sqsum[505][505];
set<int> posval;

long long gcd(long long x, long long y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

void Solve(){
    int n,m,k;
    cin>>n>>m>>k; // k가 고정이군
    rng(i,0,n-1){
        rng(j,0,m-1){
            cin>>mp[i][j];
        }
    }
    rng(i,0,n-1) cin>>tp[i];
    ll ssum=0, nsum=0;
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(tp[i][j]=='1') ssum+=mp[i][j];
            else nsum+=mp[i][j];
        }
    }
    ll tar=abs(ssum-nsum);
    posval.clear();
    rng(i,k-1,n-1){
        if(i==k-1){
            rng(j,0,m-1){
                ll tmp=0;
                rng(ttt,0,i){
                    tmp+=(tp[ttt][j]=='1');
                } 
                colsum[i][j]=tmp;
            }
        }
        else{
            rng(j,0,m-1){
                colsum[i][j]=colsum[i-1][j]-(tp[i-k][j]=='1')+(tp[i][j]=='1');
            }
        }
        //rng(j,0,m-1) cout<<colsum[i][j]<<' ';
        //cout<<'\n';

    }
    // cout<<"pass \n";
    rng(i,k-1,n-1){
        rng(j,k-1,m-1){
            if(i==k-1 && j==k-1){
                ll tmp=0;
                rng(ttt,0,k-1) tmp+=colsum[k-1][ttt];
                sqsum[i][j]=tmp;
                //cout<<"w3 "<<tmp<<'\n';
                posval.insert(abs(k*k-2*tmp));
            }
            else if(j==k-1){
                ll tmp=sqsum[i-1][j];
                rng(ttt,0,k-1) tmp-=(tp[i-k][ttt]=='1');
                rng(ttt,0,k-1) tmp+=(tp[i][ttt]=='1');
                sqsum[i][j]=tmp;
                if(posval.find(abs(k*k-2*tmp))==posval.end()){
                    //cout<<"w2 "<<tmp<<'\n';
                    posval.insert(abs(k*k-2*tmp));
                }
            }
            else{
                ll tmp=sqsum[i][j-1];
                tmp=tmp-colsum[i][j-k];
                tmp=tmp+colsum[i][j];
                sqsum[i][j]=tmp;
                //cout<<"afasdf "<<tmp<<'\n';
                if(posval.find(abs(k*k-2*tmp))==posval.end()){
                    //cout<<"w "<<tmp<<'\n';
                    posval.insert(abs(k*k-2*tmp));
                }
            }
            //cout<<abs(k*k-2*sqsum[i][j])<<' ';
        }
        //cout<<"\n";
    }

    ll gd=0;
    for(auto val:posval){
        //cout<<"posval "<<val<<'\n';
        if(val==0) continue;
        if(gd==0) gd=val;
        else gd=gcd(gd,val);
    }
    if(tar==0 || (gd!=0 && tar%gd==0)) cout<<"Yes\n";
    else cout<<"No\n";
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

