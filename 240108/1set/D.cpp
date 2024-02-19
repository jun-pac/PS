
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

int cols[N], datas[N], ds[N];
int cnt[N];
priority_queue<pii> pq;
vc<int> ans[N];
unordered_map<int,int> temp_cnt;
vc<array<int,3>> picnt;
vc<int> real_ans[N];
vc<array<int,3>> req;

void Solve(){
    int n,m;
    cin>>n>>m; // element, shelves
    while(!pq.empty()) pq.pop(); 
    fill(cnt,cnt+n,0);
    rng(i,0,m-1) ans[i].clear();
    req.clear();

    rng(i,0,n-1) cin>>cols[i];
    rng(i,0,n-1) cnt[cols[i]-1]++;
    rng(i,0,n-1) if(cnt[i]!=0) pq.push({cnt[i],i+1});

    rng(i,0,m-1) cin>>datas[i]; // size of the shelves
    rng(i,0,m-1) cin>>ds[i]; // colorfulness
    rng(i,0,m-1) ans[i].resize(datas[i]);


    rng(i,0,m-1){
        rng(j,0,datas[i]/ds[i]-1) req.pb({ds[i],i,j*ds[i]});
        if(datas[i]%ds[i]!=0) req.pb({datas[i]%ds[i],i,datas[i]/ds[i]*ds[i]});
    }

    //rng(i,0,(int)req.size()-1) cout<<req[i].fi<<' '<<req[i].se<<' '; cout<<'\n';

    sort(all(req));
    reverse(all(req));
    bool flag=1;
    rng(i,0,(int)req.size()-1){
        stack<pii> st;
        if(req[i][0]>pq.size()){
            flag=0;
            break;
        }
        rng(j,0,req[i][0]-1){
            st.push(pq.top());
            pq.pop();
        }
        rng(j,0,req[i][0]-1){
            if(st.top().fi!=1) pq.push({st.top().fi-1,st.top().se});
            ans[req[i][1]][req[i][2]+j]=st.top().se;
            st.pop();
        }
    }
    if(!flag){
        cout<<-1<<'\n';
    }
    else{
        // rng(i,0,m-1){
        //     //cout<<"shelve info : "<<i<<' '<<datas[i]<<' '<<ds[i]<<'\n';
        //     rng(j,0,(int)ans[i].size()-1){
        //         cout<<ans[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        rng(i,0,m-1){
            real_ans[i].clear();
            real_ans[i].resize(datas[i],-1);
            temp_cnt.clear();
            if(datas[i]%ds[i]!=0){
                rng(j,0,datas[i]%ds[i]-1){
                    real_ans[i][datas[i]/ds[i]*ds[i]+j]=ans[i][datas[i]/ds[i]*ds[i]+j];
                    temp_cnt[ans[i][datas[i]/ds[i]*ds[i]+j]]=datas[i]/ds[i]*ds[i]+j;
                }
            }
            gnr(j,datas[i]/ds[i]-1,0){
                rng(k,0,ds[i]-1){
                    int val=ans[i][j*ds[i]+k];
                    int next_idx=temp_cnt[val];
                    if(next_idx!=0 && next_idx<(j+2)*ds[i]){
                        //cout<<"pre "<<k<<' '<<ans[i][j*ds[i]+k]<<' '<<next_idx-ds[i]<<endl;
                        real_ans[i][next_idx-ds[i]]=val;
                        temp_cnt[val]-=ds[i];
                        ans[i][j*ds[i]+k]=-1;
                    }
                }
                int cur=j*ds[i];
                rng(k,0,ds[i]-1){
                    int val=ans[i][j*ds[i]+k];
                    int next_idx=temp_cnt[val];
                    if(val!=-1){
                        while(cur<(j+1)*ds[i] && real_ans[i][cur]!=-1) cur++;
                        if(cur==(j+1)*ds[i]) cout<<"FUCK "<<k<<' '<<ans[i][j*ds[i]+k]<<' '<<cur<<'\n';
                        real_ans[i][cur]=val;
                        temp_cnt[val]=cur;
                    }
                }
            }
        }
        rng(i,0,m-1){
            rng(j,0,(int)ans[i].size()-1){
                cout<<real_ans[i][j]<<' ';
            }
            cout<<'\n';
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

