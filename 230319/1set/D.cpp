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


int n;

void mv_left(string &a, int k){
    for(int i=0; i<n-k; i++){
        a[i]=a[i+k];
    }
    for(int i=n-k; i<n; i++) a[i]='0';
    return;
}

void mv_right(string &a, int k){
    for(int i=n-1; i>=k; i--){
        a[i]=a[i-k];
    }
    for(int i=0; i<k; i++) a[i]='0';
    return;
}

// b를 바꾼다.
void s_xor(string &a, string &b){
    for(int i=0; i<n; i++){
        b[i]=(a[i]==b[i]?0:1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        string a,b;
        cin>>a>>b;
        // right shift가 -임
        int lead_a=0, lead_b=0, cnt_a=0, cnt_b=0;
        while(lead_a<n && a[lead_a]=='0') lead_a++;
        while(lead_b<n && b[lead_b]=='0') lead_b++;
        bool same_flag=true;
        for(int i=0; i<n; i++) if(a[i]!=b[i]) same_flag=false;
        for(int i=0; i<n; i++) if(a[i]=='1') cnt_a++;
        for(int i=0; i<n; i++) if(b[i]=='1') cnt_b++;
        
        int cnt=0;
        vector<int> ans;
        if(same_flag){
            cout<<0<<endl;
        }   
        else if(lead_a==n){
            cout<<-1<<endl;
        }
        else if(lead_a==n-1 && lead_b==n){
            if(n<=3) cout<<-1<<endl;
            else{
                cout<<4<<endl;
                cout<<"1 -1 1 -1"<<endl;
            }
        }
        else if(lead_b>lead_a){
            // 불가능할수도
            s_xor(a,b);
            int last=lead_a;
            int cur=lead_a+1;
            while(cur!=n){
                while(cur<n && b[cur]=='0') cur++;
                if(cur==n) break;
                ans.push_back(-(cur-last));
                mv_right(a,cur-last);
                s_xor(a,b);
                last=cur;
                cur++;
            }
            for(int i=0; i<n; i++) if(a[i]=='1') cnt_a++;
            if(cnt_a==1){
                ans.push_back((last-lead_a));
            }
            else{
                ans.push_back(-(n-1-last));
                ans.push_back((n-1-lead_a));
                ans.push_back(-(n-1-lead_a));
            }

            if(ans.size()>n){
                cout<<-1<<endl;
            }
            else{
                cout<<ans.size()<<endl;
                for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
                cout<<endl;
            }
        }
        else{
            // 언제나 가능함.
            s_xor(a,b);
            int last=lead_b;
            int cur=lead_b;
            ans.push_back(lead_a-cur);
            mv_left(a,lead_a-cur);
            s_xor(a,b);
            cur++;
            while(cur!=n){
                while(cur<n && b[cur]=='0') cur++;
                if(cur==n) break;
                ans.push_back(-(cur-last));
                mv_right(a,cur-last);
                s_xor(a,b);
                last=cur;
                cur++;
            }
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}