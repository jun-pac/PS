
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N];
stack<int> st;
vc<int> getout;
vc<int> getin;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    getin.clear();
    getout.clear();
    // 남은 것들의 lexio-가 최소가 되도록 k개를 제거하는 방법을 찾는 문제임
    // k<n임. 마지막에는 가장 작은 원소가 남음.
    // 1개를 제거하는 방법은, 앞에서 부터 차례로, 이거 없애면 더 작아지나? 가 참이면 바로 뒤로 넘기면 됨. 
    // O(n)만에 이 작업을 끝낼 수 있음
    while(!st.empty()) st.pop();
    rng(i,0,n-1){
        while(!st.empty() && st.top() > datas[i]){
            getout.pb(st.top());
            st.pop();
        }
        st.push(datas[i]);
    }
    sort(all(getout));
    if(getout.empty()){
        // 애초부터 오름차순
        while(!st.empty()){
            getin.pb(st.top());
            st.pop();
        }
        sort(all(getin));
        rng(i,0,(int)getin.size()-1) cout<<getin[i]<<' ';
        rng(i,0,(int)getout.size()-1) cout<<getout[i]+1<<' ';
        cout<<'\n';
        return;
    }
    while(!st.empty() && st.top()>getout[0]+1){
        getout.pb(st.top());
        st.pop();   
    }
    while(!st.empty()){
        getin.pb(st.top());
        st.pop();
    }
    sort(all(getin));
    sort(all(getout));
    rng(i,0,(int)getin.size()-1) cout<<getin[i]<<' ';
    rng(i,0,(int)getout.size()-1) cout<<getout[i]+1<<' ';
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

