// 
//./E<test.txt

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

#define N 200020

int rdatas[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>x;
            rdatas[x]=i;
        }
        int l=rdatas[0], r=rdatas[0];
        ll res=0;
        for(int k=1; k<=n; k++){
            umin(l,rdatas[k-1]);
            umax(r,rdatas[k-1]);
            int temp=0;
            if(2*k<=n){
                temp+=max(min(l+2*k-1,n-1)-max(r,2*k-1)+1,0);
            }
            if(2*k-1<=n){
                temp+=max(min(l+2*k-2,n-1)-max(r,2*k-2)+1,0);
            }
            res+=temp;
            if(2*k-1>n) break;
        }
        cout<<res<<endl;
    }
    return 0;
}