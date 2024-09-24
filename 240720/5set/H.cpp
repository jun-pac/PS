
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
priority_queue<pii> pq;
int add1[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    if(n==1){
        cout<<datas[0]<<'\n';
        return;
    }
    sort(datas,datas+n);
    int cnt1=0;
    rng(i,0,n-1) if(datas[i]==1) cnt1++;
    rng(i,0,n-1) if(datas[i]!=1) pq.push({-datas[i],i});
    while(cnt1>0){
        cnt1--;
        if(!pq.empty() && pq.top().fi==-2){
            pii temp=pq.top();
            if(temp.se!=-1) add1[temp.se]++;
            pq.pop();
            pq.push({-(-temp.fi+1),temp.se});
        }
        else if(cnt1>0){
            cnt1--;
            pq.push({-2,-1});
        }
        else{
            pii temp=pq.top();
            if(temp.se!=-1) add1[temp.se]++;
            pq.pop();
            pq.push({-(-temp.fi+1),temp.se});
        }
    }
    while(!pq.empty()){
        pii temp=pq.top();
        pq.pop();
        if(temp.se==-1){
            // 1들로만 이뤄진 애들
            cout<<"(";
            rng(i,0,-temp.fi-1){
                cout<<"1";
                if(i!=-temp.fi-1) cout<<"+";
            }
            cout<<")";
            if(!pq.empty()) cout<<"*";
        }
        else{
            if(add1[temp.se]==0){
                cout<<datas[temp.se];
                if(!pq.empty()) cout<<"*";
            }
            else{
                cout<<"(";
                rng(i,0,add1[temp.se]-1){
                    cout<<"1+";
                }
                cout<<datas[temp.se];
                cout<<")";
                if(!pq.empty()) cout<<"*";
            }
        }
    }
    cout<<"\n";
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

