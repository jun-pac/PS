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

int cnt[4];
int datas[4];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        for(int i=0; i<4; i++) datas[i]=s[i]-'0';
        sort(datas,datas+4);
        fill(cnt,cnt+4,0);
        int l=0;
        for(int i=0; i<4; i++){
            //cout<<"d"<<datas[i]<<' '<<l<<endl;
            cnt[l]++;
            if(i!=3 && datas[i]!=datas[i+1]) l++;
        }
        //for(int i=0; i<4; i++) cout<<cnt[i]<<' ';
        //cout<<endl;
        sort(cnt,cnt+4);
        reverse(cnt,cnt+4);
        if(cnt[0]==4){
            cout<<-1<<endl;
        }
        else if(cnt[0]==3){
            cout<<6<<endl;
        }
        else{
            //22
            //211
            //1111
            cout<<4<<endl;
        }
    }
    return 0;
}