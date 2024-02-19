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

stack<pair<int,int>> st; // mx_idx, mn_idx
stack<int> min_st; // min_idx¸¸ °ü¸®
int datas[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    ll cnt=0;
    ll cur_cnt=0;
    ll same_num=1;
    st.push({0,0});
    ll tp;
    min_st.push(0);
    for(int i=1; i<n; i++){
        int mm=-1;
        while(!min_st.empty() && datas[min_st.top()]>datas[i]){
            min_st.pop();
        }
        if(!min_st.empty()) mm=min_st.top();
        min_st.push(i);
        while(!st.empty() && datas[st.top().fi]<datas[i]){
            tp=st.top().se;
            auto temp=st.top();
            st.pop();
            tp-=(st.empty()?-1:st.top().fi);
            if(temp.fi==temp.se) same_num-=tp;
            cur_cnt-=tp;
        }
        
        pair<int,int> temp={-1,-1};
        while(!st.empty() && st.top().se>mm){
            temp=st.top();
            tp=st.top().se;
            st.pop();
            tp-=(st.empty()?-1:st.top().fi);
            if(temp.fi==temp.se) same_num-=tp;
            cur_cnt-=tp;
        }
        if(mm!=-1 && temp.fi!=-1){
            cur_cnt+=mm-(st.empty()?-1:st.top().fi);
            st.push({temp.fi,mm});
        }
        
        tp=i-(st.empty()?-1:st.top().fi);
        cur_cnt+=tp;
        same_num+=tp;
        st.push({i,i});
        
        cnt+=cur_cnt;
        cnt-=same_num;
    }
    cout<<cnt<<endl;
    return 0;
}