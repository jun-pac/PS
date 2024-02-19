// 
//./E<test

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

vector<int> gs;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        gs.clear();
        int last_pos=0;
        char lc=s[0];
        for(int i=1; i<n; i++){
            if(lc!=s[i]){
                gs.push_back(i-last_pos);
                last_pos=i;
                lc=s[i];
            }
        }
        gs.push_back(n-last_pos);
        ll res=0;
        int last_bad=-1;
        bool flag=true;
        for(int i=0; i<gs.size(); i++){
            if(gs[i]%2==1){
                if(last_bad==-1) last_bad=i;
                else{
                    if(flag) res+=i-last_bad;
                    flag=!flag;
                    last_bad=i;
                }
            }
        }
        cout<<res<<endl;
        
    }
    return 0;
}