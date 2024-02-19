
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

ll datas[200], cnt2[200];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    //sort(datas,datas+n);
    int od=0,ev=0;
    rng(i,0,n-1){
        if(datas[i]%2==0) ev++;
        else od++;
    }
    if(ev!=0 && od!=0) cout<<2<<'\n';
    else{
        ll kabe=0;
        while(true){
            ev=0;
            rng(i,0,n-1) if(datas[i]%2==0) ev++;
            if(ev==0){
                rng(i,0,n-1) datas[i]--;
            }

            rng(i,0,n-1){
                ll temp=datas[i];
                if(temp==0) cnt2[i]=100;
                else{
                    int cnt=0;
                    while(temp!=0 && temp%2==0){
                        cnt++;
                        temp/=2;
                    }
                    cnt2[i]=cnt;
                }
            }
            ll mncnt=cnt2[0], mxcnt=cnt2[0];
            rng(i,0,n-1) mncnt=min(mncnt,cnt2[i]);
            rng(i,0,n-1) mxcnt=max(mxcnt,cnt2[i]);
            kabe+=mncnt;
            ll ttt=1;
            rng(i,0,mncnt-1) ttt*=2;
            if(mncnt==mxcnt){
                rng(i,0,n-1){
                    datas[i]=datas[i]/ttt;
                }
            }
            else break;
        }
        ll res=1;
        rng(i,0,kabe){
            res*=2;
        }
        cout<<res<<'\n';
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

