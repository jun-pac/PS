
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

pll pnt[N];
pll cur;
set<pii> st;


void Solve(){
    int n;
    cin>>n;
    st.clear();

    assert(n!=-1);
    cin>>cur.fi>>cur.se;
    rng(i,0,n-1) cin>>pnt[i].fi>>pnt[i].se;
    int cnt_o=0, cnt_e; // s와 홀수인 점의 개수
    rng(i,0,n-1){
        if((cur.fi+cur.se)%2!=(pnt[i].fi+pnt[i].se)%2){
            cnt_o++;
            st.insert({1,i+1});
        }
        else st.insert({0,i+1});
    }   
    
    cnt_e=n-cnt_o;
    if(cnt_e>(n-1)/2){
        // 내가 먼저 시작하면 내가 n/2개 지우고 상대도 n/2개 지움
        // 내가 먼저 시작하는 경우, 나는 최대한 odd한 애들을 지우면 됨.
        cout<<"First"<<endl;
        int next;
        
        rng(i,0,n/2-1){
            // 1인 애들 아무거나 지움
            auto iter=--st.end(); // st.end()--는 -1을 하기 전에 리턴을 합니다.
            cout<<(iter->se)<<endl;
            st.erase(iter);

            cin>>next;
            pii tar={((cur.fi+cur.se)%2!=(pnt[next-1].fi+pnt[next-1].se)%2?1:0),next};
            st.erase(st.find(tar));
        }
        if(!st.empty()){
            auto iter=--st.end();
            cout<<(iter->second)<<endl;
        }
    }
    else{
        // 내가 나중에 시작하면 상대는 언제나 n/2개를 지울 수 있음.
        // 나는 odd가 선택되기를 원함
        // cnt_o > n/2
        cout<<"Second"<<endl;
        int next;
        rng(i,0,n/2-1){
            // 0인 애들 아무거나 지움
            cin>>next;
            pii tar={((cur.fi+cur.se)%2!=(pnt[next-1].fi+pnt[next-1].se)%2?1:0),next};
            st.erase(st.find(tar));

            auto iter=st.begin();
            cout<<(iter->second)<<endl;
            st.erase(iter);
        }
        if(!st.empty()){
            cin>>next;
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

