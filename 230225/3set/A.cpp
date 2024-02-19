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

int datas[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, sum=0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            sum+=datas[i];
        }
        int mx_temp=-100;
        for(int i=0; i<n-1; i++){
            int temp=0;
            temp=(datas[i]==-1?2:-2)+(datas[i+1]==-1?2:-2);
            umax(mx_temp,temp);
        }
        cout<<sum+mx_temp<<endl;    
    }
    return 0;
}