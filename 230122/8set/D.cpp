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

int gcd(int x, int y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

int datas[300900];
int pred[300900];
stack<int> left_st;
stack<int> temp;
bool inq[300090], visited[300090];
int inv[300900];
int N=300010;

bool BFS(int s, int t){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cur=q.front();
        //cout<<"debug cur { "<<cur<<endl;
        q.pop();
        if(visited[cur]) continue;
        visited[cur]=true;
        while(!left_st.empty()){
            int next=left_st.top();
            left_st.pop();
            //cout<<"next "<<next;
            if(!visited[next] && !inq[next] && gcd(cur,next)!=1){
                pred[next]=cur;
                inq[next]=true;
                //cout<<" : added!! "<<t;
                if(next==t){
                    //cout<<endl;
                    return true;
                }
                q.push(next);
            }
            else if(!visited[next] && !inq[next]){
                //cout<<" Keep ";
                temp.push(next);
            }
            //cout<<endl;
        }
        while(!temp.empty()){
            int next=temp.top();
            temp.pop();
            left_st.push(next);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,s,t;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    fill(inv,inv+N,-1);
    for(int i=0; i<n; i++) inv[datas[i]]=i;

    cin>>s>>t;
    s--, t--;
    // edge numbers?
    
    fill(inq,inq+N,false);
    fill(visited,visited+N,false);
    while(!left_st.empty()) left_st.pop();
    while(!temp.empty()) temp.pop();
    for(int i=0; i<n; i++){
        if(inv[i]!=-1 && i!=s) left_st.push(i);
    }
    if(s==t){
        cout<<1<<endl;
        cout<<s+1<<endl;
        return 0;
    }
    if(!BFS(datas[s],datas[t])) cout<<-1<<endl;
    else{
        vector<int> ans;
        int idx=datas[t];
        while(inv[s]!=idx){
            ans.push_back(idx);
            idx=pred[idx];
        }
        ans.push_back(s);
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(int i=0; i<int(ans.size())-1; i++) cout<<inv[ans[i]+1]<<' ';
        cout<<t+1;
        cout<<endl;
    }
    return 0;
}