// Below is application of BFS and DFS
// You have to first implement DFS and BFS in graph and print it levelwise
#include <bits/stdc++.h>
using namespace std;
class sol
{
public:
    bool measuredfs(int jug1, int jug2, int target)
    {
        unordered_set<int> seen;
        return dfs(0, jug1, jug2, target, seen);
    }

    bool dfs(int total, int jug1, int jug2, int target, unordered_set<int> &seen)
    {
        if (total == target)
        {
            return true;
        }
        if (seen.count(total) != 0 || total < 0 || total > jug1 + jug2)
        {
            return false;
        }
        cout << "Current total :" << total << endl;
        seen.insert(total);

        return dfs(total + jug1, jug1, jug2, target, seen) || 
        dfs(total - jug1, jug1, jug2, target, seen) || 
        dfs(total + jug2, jug1, jug2, target, seen) || 
        dfs(total - jug2, jug1, jug2, target, seen);
    }

    bool bfs(int jug1,int jug2,int target)
    {
        queue<int> q;
        unordered_set<int> seen;
        vector<int> step={jug1,-jug1,jug2,-jug2};
        q.push(0);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int s:step)
            {
               int tot=curr+s;
               if(tot==target)
               {
                 return true;
               }
               if(seen.count(tot)==0 && tot>=0 && tot<=jug1+jug2)
               {
                 seen.insert(tot);
                 q.push(tot);
               }
            }
        }
        return false;
    }
};
int main()
{
    sol s;
    int jug1,jug2,target;
    cout<<"Enter Jug1 Capacity :"<<endl;
    cin>>jug1;
    cout<<"Enter Jug2 Capacity :"<<endl;
    cin>>jug2;
    cout<<"Enter Target Capacity :"<<endl;
    cin>>target;
    if(s.measuredfs(jug1,jug2,target))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    if(s.bfs(jug1,jug2,target))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}