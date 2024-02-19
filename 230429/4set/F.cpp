// 
//./F<test

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

bool bob(int n){
    // OOO가 있거나 OOXO OXOO가 있으면 된다.
    for(int i=2; i<n; i++){
        int cnt=0;
        if(s[i]=='O') cnt++;
        if(s[i-1]=='O') cnt++;
        if(s[i-2]=='O') cnt++;
        if(i!=2 && s[i-3]=='O') cnt++;
        if(cnt>=3) return true;
    }
    return false;
}

bool alice(int n){
    for(int i=2; i<n; i++){
        int cnt=0;
        if(s[i]=='X') cnt++;
        if(s[i-1]=='X') cnt++;
        if(s[i-2]=='X') cnt++;
        if(i!=2 && s[i-3]=='X') cnt++;
        if(cnt>=3) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        int n=s.size();
        if(alice(n)) cout<<"Alice"<<endl;
        else{
            bool flag=true;
            for(int i=0; i<n-1; i++){
                swap(s[i],s[i+1]);
                if(!bob(n)){
                    flag=false;
                    break;
                }
                swap(s[i],s[i+1]);
            }
            if(flag) cout<<"Bob"<<endl;
            else cout<<"Tie"<<endl;
        } 
    }
    return 0;
}