
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

int cnt[N];
// Is this deterministic? --> Yes
int datas[N];
int ans[N];
// Only count of numbers are important.

// typically, counts for number in [mx-20, mx] are matter. But in some critical cases, mx-200000 can also be matter.
// but this case is hard to replicate. 
// How to manage this special cases?
// 이게 Naive solution이 왜 TLE가 아니닌거지

set<pii> st; // 1의 {start, end} end는 next의 start와 최소 1 유격이 보장됨
void addd(int num){
    // num을 1추가한다.
    auto it=st.upper_bound(make_pair(num,1e9));
    int pos=num;
    //cout<<(it==st.begin()?-10:prev(it)->fi*10+prev(it)->se)<<endl;
    if(it!=st.begin() && ((prev(it)->fi)<=num) && ((prev(it)->se)>=num)){
        // num자리에 이미 1이 있다는 것 
        //cout<<"isnt it?"<<endl;
        pii temp=*prev(it);
        st.erase(temp);
        if(temp.fi<num) st.insert({temp.fi, num-1});
        pos=temp.se+1;
    }
    it=st.upper_bound(make_pair(pos,1e9));
    int last=pos;
    if(it!=st.end() && it->fi==pos+1){
        // union
        pii temp=*it;
        st.erase(temp);
        last=temp.se;
    }
    it=st.upper_bound(make_pair(pos,1e9));
    if(it!=st.begin() && prev(it)->se==pos-1){
        pii temp=*prev(it);
        st.erase(temp);
        st.insert({temp.fi,last});
    }
    else st.insert({pos,last});
}

void del(int num){
    // num을 지운다.
    auto it=st.upper_bound(make_pair(num,1e9));
    int last=num;
    if(it==st.begin() || prev(it)->se<num){
        // num is currently zero 000 (1) -> 111 ? 111 (0)
        pii temp = *it; 
        st.erase(it);
        if(temp.fi<temp.se) st.insert({temp.fi+1, temp.se}); // 0 000111..
        last=temp.fi-1;

        it=st.upper_bound(make_pair(num,1e9));
        if(it!=st.begin() && prev(it)->se==num-1){
            temp=*prev(it);
            st.erase(prev(it));
            st.insert({temp.fi,last}); // 111 1110 111...
        }
        else st.insert({num,last});
    }
    // else, just delete 1
    else{
        auto temp=(*prev(it));
        st.erase(temp);
        if(temp.fi!=num) st.insert({temp.fi, num-1});
        if(temp.se!=num) st.insert({num+1,temp.se});
    }   
}

int get_mx(){
    return (prev(st.end())->se);
}

void Solve(){
    int n,q,x,v,l,r,mx=0;
    cin>>n>>q;
    rng(i,0,n-1){
        cin>>datas[i];
        addd(datas[i]);
        //cout<<"add : "; for(auto ss : st) cout<<"["<<ss.fi<<' '<<ss.se<<"] ";cout<<endl;
    }
    //cout<<"init : "; for(auto ss : st) cout<<"["<<ss.fi<<' '<<ss.se<<"] ";cout<<endl;
    rng(i,0,q-1){
        cin>>x>>v;
        x--;
        del(datas[x]);
        //cout<<"del : "; for(auto ss : st) cout<<"["<<ss.fi<<' '<<ss.se<<"] ";cout<<endl;
        datas[x]=v;
        addd(datas[x]);
        //cout<<"add : "; for(auto ss : st) cout<<"["<<ss.fi<<' '<<ss.se<<"] ";cout<<endl;
        cout<<get_mx()<<endl;
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

