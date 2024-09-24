#include <bits/stdc++.h>
using namespace std;
int cnt, N, t1, t2;
// const int NODES = 2147483647;
//각 컴포넌트들이 몇개의 별들을 이루고있는지 체크 component 
unordered_map<int, int> parent;
int findParent(int x)
{
    if(x==parent[x]){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}
void Merge(int x, int y)
{
    int rootX = findParent(x);
    int rootY = findParent(y);
    
    
    // cout << "Merging " << x << " and " << y << endl;
    // cout << "Root of " << x << ": " << rootX << endl;
    // cout << "Root of " << y << ": " << rootY << endl;
    
    if(rootX != rootY)
    {
        parent[rootY] = rootX; 
    }
}
int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    unordered_set<int> nodes;
    
    int result = 0;
    //하이퍼 웜홀의 총 갯숫
    
    cin >> cnt >> N;
    
    /*
    //미리 할당 받을 필요없어짐 
    for(int i= 0; i < NODES; ++i)
    {
        parent[i] = i;
    }
    */
    
    for(int i = 0 ; i < cnt; ++i)
    {
        t1 = t2 = 0;
        cin >> t1 >> t2;
        
        // 디버깅 출력 추가
        // cout << "Processing nodes: " << t1 << " " << t2 << endl;
        
        // 노드가 처음 등장할 때 초기화
        if (parent.find(t1) == parent.end()) {
            parent[t1] = t1;
        }
        if (parent.find(t2) == parent.end()) {
            parent[t2] = t2;
        }
        
        Merge(t1, t2);
        
        //나중에 카운팅위한 
        nodes.insert(t1);
        nodes.insert(t2);
       // nodes.push_back(t1);
       //  nodes.push_back(t2);
    }
    
    // pair 어떤 집합의 몇개가 존재한다 
    // 갯수를 찾자 
    // rootNode, count
    unordered_map<int, int> component;
    for(auto num : nodes)
    {
        int p = findParent(num);
        component[p]++;
    }
    
    for(auto &node : component)
    {
        if(node.second <= N)
        {
            result += node.second;
        }
    }
    
    cout << result << endl;
    
    return 0;
}



