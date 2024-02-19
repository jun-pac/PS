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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,q;
        cin>>n>>a>>q;
        string s;
        cin>>s;
        int up_num=a, mx=a, cur=a;
        for(int i=0; i<q; i++){
            if(s[i]=='+'){
                cur++;
                up_num++;
                mx=max(mx,cur);
            }
            else cur--;
        }   
        if(mx>=n){
            cout<<"YES"<<endl;
        }
        else if(up_num>=n){
            cout<<"MAYBE"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}