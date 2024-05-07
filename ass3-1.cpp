#include<bits/stdc++.h>
using namespace std;
#define v 9

void print(int dist[])
{
    cout<<"Vertex"<<"\t\t\t\t"<<"Source"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<"\t\t\t\t"<<dist[i]<<endl;
    }
}

int mindist(int dist[], bool visit[])
{
    int mini=INT_MAX,minidx;
    for(int i=0;i<v;i++)
    {
        if(dist[i]<=mini && visit[i]==false)
        {
            mini=dist[i];
            minidx=i;
        }
    }
    return minidx;
}

void dijkstra(int graph[v][v],int src)
{
    int dist[v];
    bool visit[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
        visit[i]=false;
    }

    dist[src]=0;
    for(int c=0;c<v-1;c++)
    {
        int u=mindist(dist,visit);
        visit[u]=true;
        for(int i=0;i<v;i++)
        {
            if(!visit[i] && graph[u][i] && dist[u]!=INT_MAX && dist[u]+graph[u][i]<dist[i])
            {
                dist[i]=dist[u]+graph[u][i];
            }
        }
    }
    print(dist);
}

int main()
{
   int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 0);
    return 0;
}