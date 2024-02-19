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

int cnt[26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        fill(cnt,cnt+26,0);
        for(int i=0; i<n; i++){
            cnt[s[i]-'a']++;
        }
        int f_e=0;
        while(f_e<26 && cnt[f_e]%2==0) f_e++;
        int remain=0;
        for(int i=f_e+1; i<26; i++){
            if(remain!=0 && cnt[i]!=0) remain=1000000;
            remain+=cnt[i];
        }
        //int efe=min(f_e,25);
        if(f_e==26){
            for(int c=0; c<26; c++){
                for(int i=0; i<cnt[c]/2; i++) cout<<(char)('a'+c);
            }
            for(int c=25; c>=0; c--){
                for(int i=0; i<cnt[c]/2; i++) cout<<(char)('a'+c);
            }
            cout<<endl;
        }
        else if(remain<1000000){
            for(int c=0; c<=f_e; c++){
                for(int i=0; i<cnt[c]/2; i++) cout<<(char)('a'+c);
            }
            for(int c=f_e+1; c<26; c++){
                for(int i=0; i<(cnt[c]+1)/2; i++) cout<<(char)('a'+c);
            }
            cout<<(char)('a'+f_e);
            for(int c=25; c>=f_e+1; c--){
                for(int i=0; i<cnt[c]/2; i++) cout<<(char)('a'+c);
            }
            for(int c=f_e; c>=0; c--){
                for(int i=0; i<cnt[c]/2; i++) cout<<(char)('a'+c);
            }
            cout<<endl;
        }
        else{
            for(int c=0; c<=f_e; c++){
                for(int i=0; i<cnt[c]/2; i++) cout<<(char)('a'+c);
            }
            for(int c=f_e+1; c<26; c++){
                for(int i=0; i<cnt[c]; i++) cout<<(char)('a'+c);
            }
            cout<<(char)('a'+f_e);
            for(int c=f_e; c>=0; c--){
                for(int i=0; i<cnt[c]/2; i++) cout<<(char)('a'+c);
            }
            cout<<endl;
        }
    }
    return 0;
}