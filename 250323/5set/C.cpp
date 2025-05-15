
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
string s;
pll order[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    cin>>s;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) order[i]={datas[i],i};
    sort(order,order+n);
    reverse(order,order+n);
    set<pll> st;

    int curk=0;
    rng(i,0,n-1){
        int val=order[i].fi;
        int pos=order[i].se;
        int cval=(s[pos]=='B'?1:0);
        st.insert({pos,cval});
        auto ptr=st.lower_bound({pos,cval});
        if(s[pos]=='B'){
            if(st.size()==1){
                curk++;
            }
            else if((ptr==st.begin() && (next(ptr)->se==0)) || (next(ptr)==st.end() && (prev(ptr)->se==0))){
                curk++;
            }
            else if(prev(ptr)->se != cval && next(ptr)->se != cval){
                curk++;
            }
        }
        else{
            if(ptr!=st.begin() && next(ptr)!=st.end() && prev(ptr)->se != cval && next(ptr)->se != cval){
                curk++;
            }
        }
        // cout<<"de "<<i<<' '<<val<<' '<<pos<<' '<<curk<<'\n';
        if(curk>k){
            cout<<val<<'\n';
            return;
        }
    }
    cout<<0<<'\n';


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

