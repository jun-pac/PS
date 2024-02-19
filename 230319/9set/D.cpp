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
bool visited[500000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int k=m/4;
    int mx=0;
    int mn=0;
    for(int i=0; i<n; i++){
        cin>>s;
        int temp=0;
        
        fill(visited,visited+m,0);
        int two_left=k;
        int cnt0=0;
        for(int j=0; j<m; j++){
            if(s[j]=='1') temp++;
            if(j!=0 && s[j]=='1' && s[j-1]=='1' && !visited[j-1] && two_left>0){
                visited[j]=visited[j-1]=true;
                two_left--;
                cnt0++;
            }
        }

        // processing mx
        fill(visited,visited+m,0);
        two_left=k;
        for(int j=1; j<m; j++){
            if((s[j]!=s[j-1] || (s[j]=='0' && s[j-1]=='0'))&& !visited[j-1] && two_left>0){
                visited[j]=visited[j-1]=true;
                two_left--;
            }
        }
        mn+=temp-cnt0;
        mx+=temp-two_left;
    }
    cout<<mn<<' '<<mx<<endl;
    return 0;
}