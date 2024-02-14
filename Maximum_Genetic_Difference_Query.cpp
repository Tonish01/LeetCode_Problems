/*
There is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's number denotes its unique genetic value (i.e. the genetic value of node x is x). The genetic difference between two genetic values is defined as the bitwise-XOR of their values. You are given the integer array parents, where parents[i] is the parent for node i. If node x is the root of the tree, then parents[x] == -1.

You are also given the array queries where queries[i] = [nodei, vali]. For each query i, find the maximum genetic difference between vali and pi, where pi is the genetic value of any node that is on the path between nodei and the root (including nodei and the root). More formally, you want to maximize vali XOR pi.

Return an array ans where ans[i] is the answer to the ith query.

 

Example 1:


Input: parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
Output: [2,3,7]
Explanation: The queries are processed as follows:
- [0,2]: The node with the maximum genetic difference is 0, with a difference of 2 XOR 0 = 2.
- [3,2]: The node with the maximum genetic difference is 1, with a difference of 2 XOR 1 = 3.
- [2,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
Example 2:


Input: parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
Output: [6,14,7]
Explanation: The queries are processed as follows:
- [4,6]: The node with the maximum genetic difference is 0, with a difference of 6 XOR 0 = 6.
- [1,15]: The node with the maximum genetic difference is 1, with a difference of 15 XOR 1 = 14.
- [0,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
 

Constraints:

2 <= parents.length <= 105
0 <= parents[i] <= parents.length - 1 for every node i that is not the root.
parents[root] == -1
1 <= queries.length <= 3 * 104
0 <= nodei <= parents.length - 1
0 <= vali <= 2 * 105
*/

//--------------------------------------------------------------- SOLUTION----------------------------------------------------------------------

class Solution {
public:
    struct Node
    {
        int cnt[2];
        Node *child[2];
        Node()
        {
            for(int i=0;i<2;i++)
                cnt[i]=0,child[i]=NULL;
        }
    }*root;
    
    void add(int n)
    {
        Node *now=root;
        for(int i=30;i>=0;i--)
        {
            bool x=(n & (1<<i));
            if(!now->child[x]) now->child[x]=new Node();
            now->cnt[x]++;
            now=now->child[x];
        }
    }
    
    void remove(int n)
    {
        Node *now=root;
        for(int i=30;i>=0;i--)
        {
            bool x=(n & (1<<i));
            now->cnt[x]--;
            if(now->cnt[x]==0)
            {
                now->child[x]=NULL;
                delete(now->child[x]);
                return ;
            }
            now=now->child[x];
        }
    }
    
    int get(int val)
    {
        Node *now=root;
        int ans=0;
        for(int i=30;i>=0;i--)
        {
            bool x=(val & (1<<i));
            if(x)
            {
                if(now->cnt[0])
                    ans|=(1<<i),now=now->child[0];
                else
                    now=now->child[1];
            }
            else
            {
                if(now->cnt[1])
                    ans|=(1<<i),now=now->child[1];
                else
                    now=now->child[0];
            }
        }
        return ans;
    }
    
    
    vector<int> v[100005],ans;
    vector<pair<int,int>> q[100005];
    
    void dfs(int now)
    {
        add(now);
        for(auto to:v[now])
            dfs(to);
        for(auto i:q[now])
            ans[i.second]=get(i.first);
        remove(now);
    }
    
    vector<int> maxGeneticDifference(vector<int>& p, vector<vector<int>>& qu) 
    {
        int n=p.size(),rt;
        for(int i=0;i<n;i++)
            if(p[i]!=-1) v[p[i]].push_back(i);
            else  rt=i;
        for(int i=0;i<qu.size();i++)
            q[qu[i][0]].push_back({qu[i][1],i});
        
        root=new Node();
        ans.resize(qu.size());
        dfs(rt);
        return ans;
    }
};