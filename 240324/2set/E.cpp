
#include <bits/stdc++.h>
using namespace std;

int Solve(vector<pair<int,int>> trees, int w){
    int n=trees.size(), res=0;
    for(int i=0; i<n; i++) trees[i].second=-trees[i].second;
    sort(trees.begin(), trees.end());
    int mny=10101; // INF
    for(int i=0; i<n; i++){
        if(-trees[i].second<=mny){
            res++;
            mny=-trees[i].second;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> trees;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        trees.push_back({x,y});
    }
    cout<<Solve(trees,n);
    return 0;
}

