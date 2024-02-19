// 
//./B<test

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

string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>s;
        int cnt=0;
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-1-i]) cnt++;
        }
        if(n%2==0){
            for(int i=0; i<=n; i++){
                if(i>=cnt && i<=n-cnt && (i-cnt)%2==0) cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
        else{
            for(int i=0; i<=n; i++){
                if(i>=cnt && i<=n-cnt) cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
    }
    return 0;
}