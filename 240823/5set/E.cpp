
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
    stack<pll> st; // {val, time} 시간간격으로 갑시다
    int n;
    cin>>n;
    ll last_ans=0;
    rng(i,0,n-1){
        ll a,val;
        cin>>a>>val;
        ll t=0;
        while(!st.empty()){
            pll temp=st.top();
            st.pop();
            if(temp.fi!=val){
                if(temp.se>a){
                    t+=a;
                    st.push({temp.fi,temp.se-a});
                    st.push({val,t}); // 처음 t간은 나임.
                    break;
                }
                else{
                    // left over(=a)가 더 커서 안끝난 상황
                    t+=temp.se;
                    a-=temp.se;
                }
            }
            else{
                // temp.fi==val인 경우
                t+=temp.se;
                // a는 고정임
            }
        }
        // 남은게 0인 경우도 갈아엎을거임
        if(st.empty()){
            last_ans=t+a;
            st.push({val,last_ans});
        }
        cout<<last_ans<<' ';
    }
    cout<<'\n';
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

