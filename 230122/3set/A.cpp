// 
//./A<test

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

int datas[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    
    cin>>t;
    while(t--){
        int n;
        int sum=0;
        cin>>n;
        int mn_t=1000;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            sum+=datas[i];
            int tt=0;
            int temp=datas[i];
            while(temp!=0){
                tt++;
                if(temp%2 != (temp/2)%2) break;
                temp=temp/2;
            }
            mn_t=min(mn_t,tt);
        }
        if(sum%2==0) cout<<0<<endl;
        else cout<<mn_t<<endl;
    }
    return 0;
}