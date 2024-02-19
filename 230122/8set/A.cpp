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
    string s;
    while(t--){
        cin>>s;
        int n=s.size();
        if(s[0]=='a' && s[n-1]=='a'){
            int fa=0;
            while(fa<n && s[fa]=='a') fa++;
            if(fa==n){
                cout<<s[0]<<' ';
                for(int i=1; i<n-1; i++) cout<<s[i];
                cout<<' '<<s[n-1];
                cout<<endl;
            }
            else{
                for(int i=0; i<fa; i++) cout<<s[i];
                cout<<' ';
                for(int i=fa; i<n-1; i++) cout<<s[i];
                cout<<' '<<s[n-1]<<endl;
            }
        }


        else if(s[0]=='b' && s[n-1]=='b'){
            int fa=0;
            while(fa<n && s[fa]=='b') fa++;
            if(fa==n){
                cout<<s[0]<<' ';
                for(int i=1; i<n-1; i++) cout<<s[i];
                cout<<' '<<s[n-1];
                cout<<endl;
            }
            else{
                for(int i=0; i<fa; i++) cout<<s[i];
                cout<<' ';
                for(int i=fa; i<n-1; i++) cout<<s[i];
                cout<<' '<<s[n-1]<<endl;
            }
        }

        
        else if(s[0]=='a' && s[n-1]=='b'){
            int fa=0;
            while(fa<n && s[fa]==s[0]) fa++;
            int fb=fa;
            while(fb<n && s[fb]==s[fa]) fb++;
            if(fb==n){
                if(fa>=n-fa){
                    for(int i=0; i<fa-1; i++) cout<<s[i];
                    cout<<' '<<s[fa-1]<<' ';
                    for(int i=fa; i<n; i++) cout<<s[i];
                    cout<<endl;
                }
                else{
                    for(int i=0; i<fa; i++) cout<<s[i];
                    cout<<' ';
                    for(int i=fa; i<n-1; i++) cout<<s[i];
                    cout<<' '<<s[n-1];
                    cout<<endl;
                }
            }
            else{
                for(int i=0; i<fa; i++) cout<<s[i];
                cout<<' ';
                for(int i=fa; i<fb; i++) cout<<s[i];
                cout<<' ';
                for(int i=fb; i<n; i++) cout<<s[i];
                cout<<endl;
            }
        }


        else{
            int fa=0;
            while(fa<n && s[fa]==s[0]) fa++;
            int fb=fa;
            while(fb<n && s[fb]==s[fa]) fb++;
            if(fb==n){
                if(fa>=n-fa){
                    cout<<s[0]<<' ';
                    for(int i=1; i<fa; i++) cout<<s[i];
                    cout<<' ';
                    for(int i=fa; i<n; i++) cout<<s[i];
                    cout<<endl;
                }
                else{
                    for(int i=0; i<fa; i++) cout<<s[i];
                    cout<<' '<<s[fa]<<' ';
                    for(int i=fa+1; i<n; i++) cout<<s[i];
                    cout<<endl;
                }
            }
            else{
                for(int i=0; i<fa; i++) cout<<s[i];
                cout<<' ';
                for(int i=fa; i<fb; i++) cout<<s[i];
                cout<<' ';
                for(int i=fb; i<n; i++) cout<<s[i];
                cout<<endl;
            }
        }
    }
    return 0;
}