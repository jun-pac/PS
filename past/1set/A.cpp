// 
//./A<test.txt

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
        cin>>n;
        cin>>s;
        bool all_s=true;
        int idx=n/2;
        int cnt=0;
        if(n%2==0 && (s[idx]!=s[idx-1])){
            cout<<0<<endl;
        }
        else{
            for(int idx=n/2+1; idx<n; idx++){
                if(s[n/2]==s[idx]) cnt++;
                else break;
            }
            cout<<2*cnt+(n%2==0?2:1)<<endl;
        }
        
    }
    return 0;
}