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
string a,b;

int ca[26], cb[26];
int pos[26][200020]; //각각이 등장하는 위치들
int sz[26]; // 각각이 등장하는 개수들
int cur[26]; // 각각이 지금 버려야하는 위치들 // i<j인 문자라면 pos[i][cur[i]-1] < pos[j][cur[j]]

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cin>>a;
        cin>>b;
        fill(ca,ca+26,0);
        fill(cb,cb+26,0);
        for(int i=0; i<n; i++) ca[a[i]-'a']++;
        for(int i=0; i<m; i++) cb[b[i]-'a']++;
        bool flag=true;
        for(int i=0; i<26; i++) if(cb[i]>ca[i]){
            flag=0;
            break;
        }
        if(!flag) cout<<"NO"<<'\n';
        else{
            fill(sz,sz+26,0);
            fill(cur,cur+26,0);
            for(int i=0; i<n; i++) pos[a[i]-'a'][sz[a[i]-'a']++]=i;
            // for(int i=0; i<26; i++){
            //     cout<<(char)(i+'a')<<' ';
            //     for(int j=0; j<sz[i]; j++) cout<<pos[i][j]<<' '; cout<<'\n';
            // }
            for(int j=0; j<m; j++){
                int tar=b[j]-'a';
                //cout<<(char)(tar+'a')<<'\n';
                if(cur[tar]>=sz[tar]){
                    flag=false;
                    break;
                }
                cur[tar]++;
                int last_idx=pos[tar][cur[tar]-1];
                for(int k=0; k<tar; k++){
                    while(cur[k]<sz[k] && pos[k][cur[k]]<=last_idx) cur[k]++; 
                }
            }
            cout<<(flag?"YES":"NO")<<'\n';
        }
    }
    return 0;
}