// 
//./B<test

// 아니 정풀이 pq인데..?
// 이걸 어케 pq로 푼거

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

vector<pair<int,int>> edges[200020]; // time, next. time순으로 정렬됨
int times[200020];
bool visited[200020];

set<pair<int,int>> bst; // t, idx to be visit
// 이걸 정렬해서 방문을 하면 된다!!!

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n,t,m,a,b;
    cin>>n>>t;
    for(int tt=0; tt<t; tt++){
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back({tt,b});
            edges[b].push_back({tt,a});
        }
    }
    int k;
    cin>>k;
    for(int i=0; i<k; i++) cin>>times[i];
    for(int i=0; i<k; i++) times[i]--;

    stack<int> new_visit; // 한번에 한 step만 가는 것을 보장하기 위해서는 필요하다.
    visited[0]=1;
    //cout<<"visit! "<<0<<' '<<0<<endl;
    for(auto ee : edges[0]){
        if(!visited[ee.se]){
            bst.insert(ee);
        }
    }
    int tt;
    bool end_flag=false;
    for(tt=0; tt<k; tt++){
        //cout<<"time  "<<times[tt]<<endl;
        // bst에서 times[tt]시점을 가지는 원소들을 모두 update
        auto it=bst.lower_bound({times[tt],0});
        // if(it!=bst.end()){
        //     cout<<"Where is it? "<<it->fi<<' '<<it->se<< ' '<<visited[it->se]<<endl;
        // }
        while(it!=bst.end() && (it->fi) == times[tt]){
            // Actuall visit point
            //cout<<"visit! "<<tt<<' '<<(it->se)<<endl;
            if(!visited[it->se]){
                new_visit.push(it->se);
                visited[it->se]=true;
            }
            if(it->se==n-1){
                end_flag=true; break;
            }
            auto past=it;
            it++;
            bst.erase(past); // is it possible? // Maybe. document said other element's pointer is still valid.
        }
        if(end_flag) break;
        // 새롭게 visite된 node가 있으면 t와 상관없이 연결된 모든 edge를 bst에 담음 {t, next_pnt}
         
        while(!new_visit.empty()){
            int cur=new_visit.top();
            new_visit.pop();
            for(auto ee: edges[cur]){
                if(!visited[ee.se]){
                    bst.insert(ee);
                }
            }
        }

    }
    if(tt==k) cout<<-1<<endl;
    else cout<<tt+1<<endl;
    return 0;
}