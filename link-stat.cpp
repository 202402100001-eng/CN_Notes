#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout << "Enter the number of nodes: ";
    cin >> n;

    int dist[20], visited[20] = {0}, cost[20][20];

    cout << "\nEnter cost matrix: " << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int src; 
    cout << "ENter source: ";
    cin >> src; 
    src--;

    for(int i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
    }

    visited[src] = 1;
    dist[src] = 0;

    //Algorithm
    for(int c = 1; c < n -1; c++)
    {
        int u = -1, minDist = 9999;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = cost[u][v] + dist[u];
            }
        }


    }

    cout << "Shortest distace from node : " << src + 1 << "\n";
    for(int i = 0; i< n; i++)
    {
        cout << "To node " << i + 1 << " = " << dist[i] << endl;
    }

    return 0;
}