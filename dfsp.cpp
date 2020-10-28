#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int vis[100001];
int level[100001];
vector <int> v[100001];
int dfs(int r)
{   int i;
     for(i=0;i<v[r].size();i++)
     {
         int p=v[r][i];
         if(vis[p]==0)
         {
              vis[p]=1;
              dfs(p);
         }

     }
     return 0;
}
int main()
{
    int n,m;
    memset(vis,0,sizeof(vis));
    cin >> n >> m;
    int i;

    for(i=0;i<m;i++)
    {
        int x,y;
        cin >> x>> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int l;
    cin >> l;
    vis[l]=1;
    dfs(l);
    int c=0;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            c++;
    }
  cout << c;
}
