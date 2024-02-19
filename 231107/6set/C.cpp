// 
//./C<test

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
priority_queue<ll> pq; // max q

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        while(!pq.empty()) pq.pop();
        ll left=0;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            left+=datas[i];
        }
        for(int i=0; i<n; i++) pq.push(datas[i]);
        ll x=0;
        ll del_num=0;
        ll ans=0;
        while(!pq.empty()){
            if(left>2*pq.top()){
                ans+=pq.top()+1;
                left-=pq.top()*2;
                pq.pop();
            }
            else if(left==2*pq.top()){
                ans+=pq.top()+1;
                break;
            }
            else{
                if(left==0) break;
                else if(left==1){
                    ans++;
                    break;
                }
                ans+=left/2+1+left%2;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}