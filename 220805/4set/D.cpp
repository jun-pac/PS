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

string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>s;
        int cnt=0;
        for(int i=0; i<n; i++) if(s[i]=='(') cnt++;
        if(2*cnt!=n){
            cout<<-1<<endl;
            continue;
        }
        ll num=0;
        ll mx=0, mn=0;
        for(int i=0; i<n; i++){
            num=num+(s[i]=='('?1:-1);
            mx=max(mx,num);
            mn=min(mn,num);
        }
        if(mx*mn<0) cout<<2<<endl;
        else cout<<1<<endl;
        num=0;
        bool flag=false;
        if(s[0]=='(') flag=true;
        for(int i=0; i<n; i++){
            num=num+(s[i]=='('?1:-1);
            if(num>0) cout<<(flag?1:2)<<' ';
            else if(num<0) cout<<(flag?2:1)<<' ';
            else{
                if(s[i]=='(') cout<<(flag?2:1)<<' ';
                else cout<<(flag?1:2)<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}