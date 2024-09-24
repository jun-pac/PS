
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
#define p1 97
#define p2 2
#define p3 101

string datas[N];
ll st[N]; // current state
ll h1, h2, h3;
array<ll,3> val[N];
map<array<ll,3>,ll> mp;

void Solve(){
    int n,m;
    mp.clear();
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    //rng(i,0,n-1) cout<<"hef "<<datas[i]<<'\n';
    rng(j,0,m-1){
        // 1,0,..,0 (n°³ÁÒ)
        st[0]=(datas[0][j]=='1');
        rng(i,1,n-1){
            st[i]=(datas[i][j]=='0');
        }
        // rng(i,0,n-1) cout<<st[i];
        // cout<<'\n';
        h1=h2=h3=0;
        ll m1=1, m2=1, m3=1;
        rng(i,0,n-1){
            h1=(h1+m1*st[i])%MOD;
            m1=(m1*p1)%MOD;
            h2=(h2+m2*st[i])%MOD;
            m2=(m2*p2)%MOD;
            h3=(h3+m3*st[i])%MOD;
            m3=(m3*p3)%MOD;
        }
        h1=(h1+MOD)%MOD;
        h2=(h2+MOD)%MOD;
        h3=(h3+MOD)%MOD;
        val[j]={h1,h2,h3};
        //cout<<"first "<<h1<<' '<<h2<<' '<<h3<<'\n';
        m1=1, m2=1, m3=1;
        rng(i,1,n-1){
            h1=h1+m1*(1-2*st[i-1]);
            h1=h1+(m1*p1)*(1-2*st[i]);
            h1=h1%MOD;
            m1=m1*p1%MOD;
            h1=(h1+MOD)%MOD;

            h2=h2+m2*(1-2*st[i-1]);
            h2=h2+(m2*p2)*(1-2*st[i]);
            h2=h2%MOD;
            m2=m2*p2%MOD;
            h2=(h2+MOD)%MOD;

            h3=h3+m3*(1-2*st[i-1]);
            h3=h3+(m3*p3)*(1-2*st[i]);
            h3=h3%MOD;
            m3=m3*p3%MOD;
            h3=(h3+MOD)%MOD;

            val[i*m+j]={h1,h2,h3};
            //cout<<"secod "<<h1<<' '<<h2<<' '<<h3<<'\n';
            st[i-1]=1-st[i-1];
            st[i]=1-st[i];            
        }
    }
    ll mx=0;
    
    rng(i,0,n-1){
        rng(j,0,m-1){
            mp[val[i*m+j]]++;
        }
    }
    rng(i,0,n-1){
        rng(j,0,m-1){
            mx=max(mx,mp[val[i*m+j]]);
        }
    }
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(mp[val[i*m+j]]==mx){
                cout<<mx<<'\n';
                rng(k,0,n-1){
                    //cout<<"?? "<<datas[k][j]<<' '<<(k==i?1:0)<<'\n';
                    cout<<!(datas[k][j]=='0'+(k==i?1:0));
                }
                cout<<'\n';
                return;
            }
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

