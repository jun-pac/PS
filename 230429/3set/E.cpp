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

int datas[300030];
int visited[300030];
int left_step[300030]; // 불가능하면 -1
int ans[300030];
int n;

int DFS(int idx){
    if(visited[idx]) return left_step[idx];
    visited[idx]=true;
    int next=idx+datas[idx]+1;
    if(next==n){
        return left_step[idx]=1;
    }
    else if(next<n){
        int temp=DFS(next);
        if(temp==-1) left_step[idx]=-1;
        else left_step[idx]=temp+1;
        return left_step[idx];
    }
    else{
        return left_step[idx]=-1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++){
            DFS(i);
        }
        set<int> past;
        for(int i=n-2; i>=0; i--){
            //cout<<"d "<<left_step[i+1]<<endl;
            if(left_step[i+1]!=-1 && datas[i]==left_step[i+1]){
                ans[i]=0;;
            }
            else if(left_step[i+1]!=-1){
                ans[i]=1;
            }
            else{
                // datas[i]개를 만족하는... 조합이 있는가?
                // 니 뒤에 datas[i]-1이 있는가?
                if((datas[i]!=0 && past.find(datas[i])!=past.end()) || (i==n-2 && datas[i]==1)) ans[i]=1;
                else ans[i]=2;
            }
            past.insert(left_step[i+1]+1);
        }
        for(int i=0; i<n-1; i++) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}