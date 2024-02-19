// 
//./C<test.txt

#include <bits/stdc++.h>
//#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

unordered_map<int,int> mm;

class node{
public:
    int fi,se;
    bool ma,mb;
    bool operator<(node &b){
        if(fi==b.fi) return se<b.se;
        else return fi<b.fi; 
    }
};
node datas[200000];
bool ma[200000], mb[200000];
vector<int> dlist;

inline int f(int num){
    ll res=0, mul=1;
    while(num>=mul){
        mul=mul*10;
        res++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    dlist.reserve(200000);
    //cout<<f(100)<<' '<<f(110)<<' '<<f(1000)<<endl;
    while(t--){
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++) cin>>datas[i].fi;
        for(int i=0; i<n; i++) cin>>datas[i].se;
        for(int i=0; i<n; i++) datas[i].ma=datas[i].mb=false;
        
        mm.clear();
        dlist.clear();
        sort(datas,datas+n);
        for(int i=0; i<n; i++){
            mm[datas[i].fi]++;
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            //cout<<datas[i].se<<' '<<mm[datas[i].se]<<endl;
            if(mm[datas[i].se]!=0){
                //cout<<"same 1 "<<datas[i].se<<endl;
                mm[datas[i].se]--;
                datas[i].mb=true;
                dlist.push_back(datas[i].se);
            }
        }
        sort(dlist.begin(), dlist.end());
        int j=0;
        for(int i=0; i<dlist.size(); i++){
            while(j<n && datas[j].fi<dlist[i]){
                j++;
            }
            while(j<n && datas[j].ma) j++;
            datas[j].ma=true;
        }
        
        for(int i=0; i<n; i++){
            // if((!datas[i].ma && datas[i].fi>9) || (!datas[i].mb && datas[i].se>9)) cnt++;
            if(!datas[i].ma && datas[i].fi>=10){
                datas[i].fi=f(datas[i].fi);
                cnt++;
            }
            if(!datas[i].mb && datas[i].se>=10){
                datas[i].se=f(datas[i].se);
                cnt++;
            }
        }

        mm.clear();
        dlist.clear();
        sort(datas,datas+n);
        /*cout<<"prt "<<endl;
        for(int i=0; i<n; i++) cout<<datas[i].fi<<' ';
        cout<<endl;
        for(int i=0; i<n; i++) cout<<datas[i].se<<' ';
        cout<<endl;*/
        for(int i=0; i<n; i++){
            if(!datas[i].ma) mm[datas[i].fi]++;
        }
        for(int i=0; i<n; i++){
            if(!datas[i].mb && mm[datas[i].se]!=0){
                //cout<<"same 2 "<<datas[i].se<<endl;
                mm[datas[i].se]--;
                datas[i].mb=true;
                dlist.push_back(datas[i].se);
            }
        }
        sort(dlist.begin(), dlist.end());
        j=0;
        for(int i=0; i<dlist.size(); i++){
            while(j<n && datas[j].fi<dlist[i]){
                j++;
            }
            while(j<n && datas[j].ma) j++;
            datas[j].ma=true;
        }

        for(int i=0; i<n; i++){
            //if((!datas[i].ma && datas[i].fi>1) || (!datas[i].mb && datas[i].se>1)) cnt++;
            if((!datas[i].ma && datas[i].fi>1)){
                datas[i].fi=f(datas[i].fi);
                cnt++;
            }
            if(!datas[i].mb && datas[i].se>1){
                datas[i].se=f(datas[i].se);
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}