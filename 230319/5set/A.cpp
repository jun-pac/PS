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

bool visited[4];
char match[4];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    match[0]='m';
    match[1]='e';
    match[2]='o';
    match[3]='w';

    while(t--){
        int n;
        cin>>n;
        string s;
        fill(visited,visited+4,0);
        cin>>s;
        int cur=0;
        bool flag=true;
        int cur_cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]==match[cur] || s[i]==match[cur]+'A'-'a'){
                cur_cnt++;
            }
            else if(cur==3){
                flag=false;
                break;
            }
            else if(s[i]==match[cur+1] || s[i]==match[cur+1]+'A'-'a'){
                if(cur_cnt==0){
                    flag=false;
                    break;
                }
                cur++;
                cur_cnt=1;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag && cur==3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}