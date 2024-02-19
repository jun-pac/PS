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

vector<char> ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll pos;
        cin>>pos;
        pos--;
        ll k=0, n=s.size();
        for(k=0; k<n; k++){
            if(pos<n-k) break;
            pos-=n-k;
        }
        //cout<<"debug "<<pos<<' '<<k<<endl;
        stack<char> st;
        int cur=0;
        //cout<<s<<endl;
        for(int i=0; i<k; i++){
            while(st.empty()||(cur<n && st.top()<=s[cur])){
                st.push(s[cur]);
                cur++;
            }
            st.pop();
        }
        //cout<<"hello"<<endl;
        ans.clear();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        for(;cur<n; cur++){
            ans.push_back(s[cur]);
        }
        cout<<(char)ans[pos];
    }
    cout<<endl;
    return 0;
}