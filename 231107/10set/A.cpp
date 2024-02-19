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

queue<int> st;
int red;
void DFS(string &s, int l, int r, int f1, int b0){
    if(r<=l+1){
        // 종료조건
        return;
    }
    char front=(f1!=0?'1':s[l]);
    char back=(b0!=0?'0':s[r]);
    if(front!=back){
        st.push(-1);
        red++;
        DFS(s, (f1==0?l+1:l), (b0==0?r-1:r), max(0,f1-1), max(0,b0-1));
    }
    else if(front=='0'){
        st.push(r+1-l+f1+b0);
        DFS(s, (f1==0?l+1:l), r, max(0,f1-1),b0+1);
    }
    else{
        st.push(0);
        DFS(s, l, (b0==0?r-1:r), f1+1, max(0,b0-1));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int num0=0, num1;
        for(int i=0; i<n; i++) if(s[i]=='0') num0++;
        num1=n-num0;
        if(num1!=num0){
            cout<<-1<<endl;
            continue;
        }
        red=0;
        DFS(s,0,n-1,0,0);
        int offset=0;
        cout<<(int)st.size()-red<<endl;
        while(!st.empty()){
            auto pos=st.front();
            st.pop();
            if(pos!=-1)cout<<offset+pos<<' ';
            offset++;
        }
        cout<<endl;
    }
    return 0;
}