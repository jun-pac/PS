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

bool check[26][26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int an=a.size() ,bn=b.size();
        
        if(a[0]==b[0]){
            cout<<"YES"<<endl;
            cout<<a[0]<<"*"<<endl;
            continue;
        }
        if(a[an-1]==b[bn-1]){
            cout<<"YES"<<endl;
            cout<<"*"<<a[an-1]<<endl;
            continue;
        }
        for(int i=0; i<26; i++){
            fill(check[i],check[i]+26,false);
        }
        for(int i=1; i<an; i++){
            check[a[i-1]-'a'][a[i]-'a']=true;
        }
        bool flag=false;
        for(int i=1; i<bn; i++){
            if(check[b[i-1]-'a'][b[i]-'a']){
                cout<<"YES"<<endl;
                cout<<"*"<<b[i-1]<<b[i]<<"*"<<endl;
                flag=true;
                break;
            }
            if(flag) break;
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}