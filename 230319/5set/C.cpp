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

// idx이하의 구간에서 0이 bonus개수 이상이었다면, 앞에 있던 bonus는 모조리 더해짐. (가장 0이 상대적으로 많은 시점?)
// idx이하의 어떤 구간에서는 0이 bonus개수보다 적을 수 있다. 이때는 버려야 함.

priority_queue<ll> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        while(!pq.empty()) pq.pop();
        ll sum=0;
        ll a;
        for(int i=0; i<n; i++){
            cin>>a;
            if(a==0){
                if(pq.size()!=0){
                    a=pq.top();
                    pq.pop();
                    sum+=a;
                }
            }
            else{
                pq.push(a);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}