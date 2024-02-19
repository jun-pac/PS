// 
//./E<test

#include <bits/stdc++.h>
//#define endl '\n'
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

vector<int> edges[200000];
multiset<int> local[200000]; // 다음 depth의 길이들. 자기자신 (즉, +1한 것)은 포함하지 않음.
multiset<int> all; // min chain의 후보가 되는 것들. 단, root까지 올라온 chain은 불포함
int ans;


void DFS1(int idx, int p){
    for(auto next : edges[idx]){
        if(next==p) continue;
        DFS1(next,idx);
        local[idx].insert(*local[next].begin()+1);
        all.insert(*local[next].begin()+1);
    }
    if(local[idx].size()!=0) all.erase(all.find(*local[idx].begin()));
    if(local[idx].size()==0) local[idx].insert(0);    
}

void DFS(int idx, int p){
    // idx를 'root'화 시키는 세뇌 과정이다.
    
    if(local[idx].find(0)!=local[idx].end()) local[idx].erase(local[idx].find(0));
    all.erase(all.find(*local[idx].begin()));
    //cout<<"idx : "<<idx<<' '<<all.size()<<' '<<((*local[idx].begin())+1)<<' '<<(all.size()==0?*local[idx].begin()+1:min(*local[idx].begin()+1, *all.begin()))<<endl;
    //cout<<"all : "<<*all.begin()<<' '<<(*(++all.begin()))<<endl;
    if(all.size()==0) ans=max(ans,*local[idx].begin()+1);
    else ans=max(ans,min(*local[idx].begin()+1, *all.begin()));
    all.insert(*local[idx].begin());
    if(local[idx].find(0)!=local[idx].end()) local[idx].erase(local[idx].find(0));


    for(auto next : edges[idx]){
        if(next==p) continue;
        // set next to root
        all.erase(all.find(*local[next].begin()+1));
        local[idx].erase(local[idx].find(*local[next].begin()+1));
        if(local[idx].size()!=0) all.erase(all.find(*local[idx].begin()));
        if(local[idx].size()==0) local[idx].insert(0);

        if(*local[next].begin()!=0) all.insert(*local[next].begin());
        local[next].insert(*local[idx].begin()+1);
        //cout<<"idx2 : "<<idx<<" next : "<<next<<' '<<(*local[idx].begin()+1)<<endl;
        all.insert(*local[idx].begin()+1);

        // recursion
        DFS(next, idx);

        // reset root
        all.erase(all.find(*local[idx].begin()+1));
        local[next].erase(local[next].find(*local[idx].begin()+1));
        if(*local[next].begin()!=0) all.erase(all.find(*local[next].begin()));
        
        if(local[idx].size()==1 && *local[idx].begin()==0) local[idx].erase(local[idx].begin());
        if(local[idx].size()!=0) all.insert(*local[idx].begin());
        local[idx].insert(*local[next].begin()+1);
        all.insert(*local[next].begin()+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++) local[i].clear();
        all.clear();
        
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        DFS1(0,-1);
        
        //cout<<"semi ans : "<<(all.size()==0?*local[0].begin()+1:min(*local[0].begin()+1, *all.begin()))<<endl;
        all.insert(*local[0].begin());
        ans=0;
        DFS(0,-1);
        cout<<ans<<endl;
    }
    return 0;
}