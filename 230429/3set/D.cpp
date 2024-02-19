// 
//./D<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}
#define INF 1000000007

ll datas[300000];
ll ans[300000];
ll mn, mx;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        mn=INF, mx=0;
        int n;
        cin>>n;
        ll cur=0;
        priority_queue<int> pl, mi;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            mn=min(mn,datas[i]);
            mx=max(mx,datas[i]);
            if(datas[i]<0) mi.push(-datas[i]);
            else if(datas[i]>0) pl.push(datas[i]);
            else ans[cur++]=0;
        }
        
        ll tar=mx-mn;
        if(tar==0) cout<<"No"<<endl;
        else{
            ll cur_sum=0;
            bool flag=true;
            while(!(pl.empty() && mi.empty())){
                if(!pl.empty() && cur_sum+pl.top()<tar){
                    ans[cur++]=pl.top();
                    cur_sum+=pl.top();
                    pl.pop();
                }
                else if(!mi.empty() && cur_sum-mi.top()>=0){
                    ans[cur++]=-mi.top();
                    cur_sum-=mi.top();
                    mi.pop();
                }
                else{
                    flag=false;
                    break;
                }
            }
            assert(flag);
            cout<<"Yes"<<endl;
            for(int i=0; i<n; i++) cout<<ans[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}

