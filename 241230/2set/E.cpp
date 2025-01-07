
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int cnt[N];
set<pii> st; // {l,col}

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cnt[i]=1;
    rng(i,0,n-1) st.insert({i,i}); // idx, col

    rng(i,0,q-1){
        int a,prev_idx,c;
        cin>>a;
        if(a==1){
            cin>>prev_idx>>c;
            prev_idx--, c--;
            auto temp=(prev(st.upper_bound({prev_idx,INF})));
            int prev_col = temp->se; // 필요없나?
            int l=temp->fi;
            int r=(next(temp)==st.end()?n-1:(next(temp)->fi)-1);
            cnt[prev_col]-=(r-l+1);
            cnt[c]+=(r-l+1);
            int lcol=(temp==st.begin()?-1:prev(temp)->se);
            int rcol=(next(temp)==st.end()?-1:(next(temp)->se));
            if(c!=lcol && c!=rcol){
                st.erase(*temp);
                st.insert({l,c});
            }
            else if(c==lcol && c==rcol){
                auto p=prev(temp);
                auto np=next(temp);
                int lend=p->fi;
                st.erase(*p);
                st.erase(*temp);
                st.erase(*np);
                st.insert({lend,c});
            }
            else if(c==lcol){
                auto p=prev(temp);
                int lend=p->fi;
                st.erase(*p);
                st.erase(*temp);
                st.insert({lend,c});
            }
            else{
                auto np=next(temp);
                st.erase(*temp);
                st.erase(*np);
                st.insert({l,c});
            }
        }
        else{
            cin>>c;
            c--;
            cout<<cnt[c]<<'\n';
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

