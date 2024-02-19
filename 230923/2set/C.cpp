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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0; i<n; i++) sum+=(i+1)*(i+1);
        int mx=sum-(n+1)*(n+1);
        for(int i=1; i<n; i++){
            // i+1°³°¡ µÚÁýÈû
            int temp_sum=sum;
            for(int j=0; j<=i; j++) temp_sum-=(n-j)*(n-j);
            for(int j=0; j<=i; j++) temp_sum+=(n-j)*(n-i+j);
            temp_sum-=(n-i/2)*(n-(i+1)/2);
            mx=max(mx,temp_sum);
        }
        cout<<mx<<endl;
    }
    return 0;
}