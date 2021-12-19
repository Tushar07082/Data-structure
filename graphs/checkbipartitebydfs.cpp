#include <iostream>
#include <queue>
using namespace std;
int *color;
vector<int> *adj;

bool isbipartite(int j)
{
        cout << j << " ";
        for (int i = 0; i < adj[j].size(); i++)
        {
                if (color[adj[j][i]] == -1)
                {
                        if (color[j] == 0)
                        {
                                color[adj[j][i]] = 1;
                        }
                        else
                                color[adj[j][i]] = 0;
                        if (!isbipartite(adj[j][i]))
                        {
                                return false;
                        }
                }
                else if (color[adj[j][i]] == color[j])
                {
                        return false;
                }
        }
        return true;
}
int main()
{
        int n, m;
        cin >> n >> m;
        color = new int[n];
        for (int i = 0; i < n; i++)
        {
                color[i] = -1;
        }
        adj = new vector<int>[n];
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                adj[a].push_back(b);
                adj[b].push_back(a);
        }
        for (int i = 0; i < n; i++)
        {
                if (color[i] == -1)
                {
                        color[i] = 0;
                        if (!isbipartite(i))
                        {
                                cout << "Not a bipartite";
                                return 0;
                        }
                }
        }
        cout << "A pure bipartite graph";
}