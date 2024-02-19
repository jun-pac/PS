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
        int n,l,r;
        int cap=0, no=0, wls=0;
        cin>>n>>l>>r;
        string s;
        cin>>s;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1') cap++;
            else if(s[i]=='2') wls++;
            else no++;
        }
        if(cap*l<=n && n<=(cap+no)*r){
            bool flag=false;
            for(int k=cap; k<=cap+no; k++){
                if(l*k<=n && n<=r*k){
                    flag=true;
                    break;
                }
            }
            cout<<(flag?"YES":"NO")<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}