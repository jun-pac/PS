
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

void Solve(){
    ll n;
    cin>>n;
    ll l=2, r=n-1; 
    ll sz=n/4;
    int res[4];
    int sum=0;
    ll pos=0;
    rng(i,0,2){
        cout<<"? "<<i*sz+1<<' '<<(i+1)*sz<<endl;
        cin>>res[i];
        sum+=res[i];
    }
    if(res[0]+res[1]==2){
        // 좌측이 safe
        r=sz;
        while(l<r){
            ll mid=(l+r)/2;
            cout<<"? "<<1<<' '<<mid<<endl; // 원래 0이 나오는 구간임
            int res;
            cin>>res;
            if(res==0) l=mid+1;
            else r=mid;
        }
        cout<<"! "<<r<<endl;
    }
    else if(res[0]+res[1]==0){
        // 좌측이 safe
        pos=(res[2]==1?3*sz-1:4*sz-1);
        l=sz+1;
        // [n-l+1 n]을 하면 무조건 1이 있다!
        while(l<r){
            ll mid=(l+r)/2;
            cout<<"? "<<max(1LL,pos-mid+2)<<' '<<max(1LL,pos-mid+2)+mid-1<<endl;
            int res;
            cin>>res;
            if(res==1) l=mid+1;
            else r=mid;
        }
        cout<<"! "<<l<<endl;
    }
    else{
        if(sum==3){
            r=sz;
            while(l<r){
                ll mid=(l+r)/2;
                cout<<"? "<<n/2+1<<' '<<n/2+mid<<endl; // 원래 0이 반드시 나오는 구간임
                int res;
                cin>>res;
                if(res==0) l=mid+1;
                else r=mid;
            }
            cout<<"! "<<r<<endl;
        }
        else{
            l=sz+1;
            pos=(res[0]==1?0:sz);
            while(l<r){
                ll mid=(l+r)/2;
                cout<<"? "<<min(pos+mid,n)-mid+1<<' '<<min(pos+mid,n)<<endl;
                int res;
                cin>>res;
                if(res==1) l=mid+1;
                else r=mid;
            }
            cout<<"! "<<l<<endl;
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

