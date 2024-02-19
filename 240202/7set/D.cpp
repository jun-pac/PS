
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

string aa, bb;

void Solve(){
    int zero,one,k;
    cin>>zero>>one>>k;
    int n=zero+one;
    if(k==0){
        cout<<"YES\n";   
        rng(i,0,one-1) cout<<1;
        rng(i,0,zero-1) cout<<0; cout<<'\n';
        rng(i,0,one-1) cout<<1;
        rng(i,0,zero-1) cout<<0; cout<<'\n';
        return;
    }
    if(one==1){
        cout<<"NO\n";
        return;
    }
    if(zero==0){
        cout<<"NO\n";
        return ;
    }
    if(k>=one+zero-1){
        cout<<"NO\n";
        return;
    }
    
    aa.resize(n);
    bb.resize(n);
    aa[0]=bb[0]='1';
    aa[n-1]='0';
    bb[n-1]='1';
    aa[n-1-k]='1';
    bb[n-1-k]='0';
    one-=2;
    rng(i,1,n-1-k-1){
        if(one>0){
            aa[i]=bb[i]='1';
            one--;
        }
        else aa[i]=bb[i]='0';
    }
    rng(i,n-1-k+1,n-1-1){
        if(one>0){
            aa[i]=bb[i]='1';
            one--;
        }
        else aa[i]=bb[i]='0';
    }


    cout<<"YES\n";
    cout<<aa<<'\n';
    cout<<bb<<'\n';
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

