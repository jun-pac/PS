
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

ll datas[N], ltemp[N], rtemp[N];

bool check(int l, int r){
    if(l>r){
        return datas[l-1]/2==datas[r+1] || datas[r+1]/2==datas[l-1];
    }
    if(datas[r+1]>=datas[l-1]){
        datas[r]=(datas[r+1]!=1?datas[r+1]/2:2);
        return check(l,r-1);
    }
    else{
        datas[l]=(datas[l-1]!=1?datas[l-1]/2:2);
        return check(l+1,r);
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    
    int fn=-1, ln=-1;
    rng(i,0,n-1){
        if(datas[i]!=-1){
            fn=i;
            break;
        }
    }
    gnr(i,n-1,0){
        if(datas[i]!=-1){
            ln=i;
            break;
        }
    }
    if(fn==-1){
        rng(i,0,n-1) cout<<(i%2==0?1:2)<<' ';
        cout<<'\n';
        return;
    }

    if(datas[0]==-1){
        assert(fn!=0);
        rng(i,1,fn){
            datas[fn-i]=(datas[fn-i+1]==1?2:datas[fn-i+1]/2);
        }   
    }
    if(datas[n-1]==-1){
        assert(ln!=n-1);
        rng(i,ln+1,n-1){
            datas[i]=(datas[i-1]==1?2:datas[i-1]/2);
        }
    }

    bool flag=0, ansflag=1;
    int l=0,r=0;
    rng(i,0,n-1){
        if(datas[i]==-1){
            if(!flag){
                l=i;
            }
            flag=1;
            r=i;
        }
        else{ // real num
            if(flag){
                flag=0;
                bool res=check(l,r);
                if(!res){
                    cout<<-1<<'\n';
                    return;
                }
            }
        }    
    }

    rng(i,0,n-2){
        if(!(datas[i+1]/2==datas[i] || datas[i+1]==datas[i]/2)) ansflag=0;
    }
    if(!ansflag) cout<<-1<<'\n';
    else{
        rng(i,0,n-1) cout<<datas[i]<<' ';
        cout<<'\n';
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

