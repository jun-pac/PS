// 
//./SAM1<test

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

ll datas[200020];
priority_queue<ll> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        ll n,k;
        ll sum=0;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i];
        sort(datas,datas+n);
        for(int i=0; i<n; i++) sum+=datas[i];
        int res=0;
        int cur=0;
        bool flag=true;
        while(!pq.empty()) pq.pop();
        while(k<sum){
            while(cur<n && datas[cur]<=k){
                pq.push(datas[cur]);
                cur++;
            }
            if(pq.empty()){
                flag=false;
                break;
            }
            res++;
            sum-=pq.top();
            k+=pq.top();
            //cout<<"USE "<<pq.top()<<' '<<k<<endl;
            pq.pop();
        }
        cout<<"#"<<tt<<' '<<(flag?res:-1)<<endl;
    }
    return 0;
}