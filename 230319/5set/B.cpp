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

int upnum[26], lonum[26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        string s;
        cin>>n>>k;
        cin>>s;
        fill(upnum,upnum+26,0);
        fill(lonum,lonum+26,0);
        for(int i=0; i<n; i++){
            if(s[i]>='a') lonum[s[i]-'a']++;
            else upnum[s[i]-'A']++;
        }
        int cnt=0, capa=0;
        for(int i=0; i<26; i++){
            cnt+=min(upnum[i],lonum[i]);
            capa+=abs(upnum[i]-lonum[i])/2;
        }
        cout<<cnt+min(capa,k)<<endl;
    }
    return 0;
}