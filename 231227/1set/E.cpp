
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

void Solve(){
    ll p,q;
    cin>>p>>q;
    string ans;
    if(abs(p)%2!=abs(q)%2){
        cout<<"12";
        p-=12;
        q-=21;
    }
    else cout<<"0";
    cout<<"+0";
    ll aa, bb;
    aa=(p+q)/2;
    bb=(p-q)/2;
    //cout<<aa<<' '<<bb<<'\n';
    ll a=abs(aa), b=abs(bb);
    ll cur=1;
    if(a!=0){
        rng(i,0,17) cur*=10;
        if(aa<0) cout<<"+0";
        gnr(i,18,0){
            if(cur==1){
                if(a==10){
                    if(aa<0) cout<<"-";
                    else cout<<"+";
                    cout<<1;
                    a--;
                }
                if(a==0) break;
                if(aa<0) cout<<"-";
                else cout<<"+";
                cout<<a;
                break;
            }
            if(cur+1>a){
                cur=cur/10;
                continue;
            }
            ll val=a/(cur+1);
            if(aa<0) cout<<"-";
            else cout<<"+";
            cout<<val*(cur+1);
            a-=val*(cur+1);
            ans.pb(val);
            cur=cur/10;
        }
        if(aa<0) cout<<"-0";
        else cout<<"+0";
    }

    if(b!=0){
        cur=1;
        rng(i,0,17) cur*=10;
        gnr(i,18,0){
            if(cur==1){
                if(b==10){
                    if(bb<0) cout<<"-"<<1<<"+0";
                    else cout<<"+"<<1<<"-0";
                    b--;
                }
                if(b==0) break;
                if(bb<0) cout<<"-"<<b<<"+0";
                else cout<<"+"<<b<<"-0";
                break;
            }
            if(cur+1>b){
                cur=cur/10;
                continue;
            }
            ll val=(b)/(cur+1);
            if(bb<0){
                cout<<"-"<<val*(cur+1)<<"+0";
            }
            else{
                cout<<"+"<<val*(cur+1)<<"-0";
            }
            b-=val*(cur+1);
            cur=cur/10;
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

