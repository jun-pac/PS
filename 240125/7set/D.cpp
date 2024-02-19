
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

int a[N], b[N];
map<int,int> mp;
int n;

bool check_back(int aval){
    // b[i]>a인 애들만 관심이 있음.
    rng(i,0,n-1){
        if(b[i]<=aval) continue;
        int l=abs(aval-b[i]), r=aval+b[i];
        auto it = mp.upper_bound(l);
        if(it==mp.end()) return 0;
        else if(it->fi == aval){
            if(it->se==1){
                it=next(it);
                if(it==mp.end() || it->fi >= r) return 0;
            }
        }
        else if(it->fi >= r) return 0;
    }
    return 1;
}

void Solve(){
    cin>>n;
    mp.clear();
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    rng(i,0,n-1) mp[a[i]]++; 
    
    if(!check_back(a[n-1])){
        cout<<"Bob\n";
        return;
    }

    int l=0, r=n-1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check_back(mid)) r=mid;
        else l=mid+1;
    }

    rng(i,l,n-1){
        if(b[0]>a[i]){
            cout<<"Alice\n";
            return;
        }
        else{
            int l=abs(a[i]-b[0]), r=a[i]+b[0];
            auto it = mp.upper_bound(l);
            if(it==mp.end()) continue;
            else if(it->fi == a[i]){
                if(it->se==1){
                    it=next(it);
                    if(it==mp.end() || it->fi >= r) continue;
                }
            }
            else if(it->fi >= r) continue;
            cout<<"Alice\n";
            return;
        }
    }
    cout<<"Bob\n";
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

