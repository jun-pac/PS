
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];
map<ll,ll> mp; // 나머지의 개수를 세는 것
multiset<pll> st;

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    // 중요한 건 k에 대한 기우성이 같은 애들을 배치하는 것.
    mp.clear();
    st.clear();
    rng(i,0,n-1) mp[datas[i]%k]++;
    rng(i,0,n-1) st.insert({datas[i]%k,datas[i]/k});
    if(n%2==0){
        bool flag=1;
        rng(i,0,n-1){
            if(mp[datas[i]%k]%2!=0){
                flag=0;
                break;
            } 
        }
        if(!flag) cout<<-1<<'\n';
        else{
            ll res=0, cnt=0;
            for(auto temp=st.begin(); temp!=st.end(); temp=next(temp)){
                cnt++;
                if(cnt%2==0){
                    res+=(temp->se)-(prev(temp)->se);
                }
            }
            cout<<res<<'\n';
        }
    }
    else{
        int oddmod=-1;
        bool flag=1;
        rng(i,0,n-1){
            if(mp[datas[i]%k]%2==1){
                if(oddmod==-1) oddmod=datas[i]%k;
                else if(oddmod!=datas[i]%k){
                    flag=0;
                    break;
                }
            }
        }
        if(!flag || oddmod==-1) cout<<-1<<'\n';
        else{
            ll res=0, cnt=0, bsum=0, fsum=0, last=-1;
            for(auto temp=st.begin(); temp!=st.end(); temp=next(temp)){
                if(temp->fi==oddmod) continue;
                if(oddmod!=last){
                    last=oddmod;
                    cnt=0;
                }
                cnt++;
                if(cnt%2==0){
                    res+=(temp->se)-(prev(temp)->se);
                }
            }
            ll mn=INF;
            cnt=0;
            for(auto temp=st.lower_bound({oddmod,-1}); temp!=st.upper_bound({oddmod,INF}); temp=next(temp)){
                cnt++;
                if(cnt%2==1 && cnt!=1){
                    bsum+=(temp->se)-(prev(temp)->se);
                    //cout<<"? "<<(temp->fi)<<' '<<(temp->se)<<' '<<(prev(temp)->fi)<<' '<<(prev(temp)->se)<<'\n';
                }
            }
            //cout<<"bsum? "<<bsum<<' '<<oddmod<<' '<<mp[oddmod]<<'\n';
            cnt=0;
            mn=bsum;
            for(auto temp=st.lower_bound({oddmod,-1}); temp!=st.upper_bound({oddmod,INF}); temp=next(temp)){
                cnt++;
                if(cnt%2==1 && cnt!=1){
                    bsum-=(temp->se)-(prev(temp)->se);
                    mn=min(mn,bsum+fsum);
                }
                else if(cnt%2==0){
                    fsum+=(temp->se)-(prev(temp)->se);
                    mn=min(mn,bsum+fsum);
                }
            }
            cout<<res+mn<<'\n';

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

