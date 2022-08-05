#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int t, w, h;
string board[1000];
int sang_vis[1000][1000];
int fire_vis[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> w >> h;
        fill(sang_vis[0],sang_vis[1000],0);
        fill(fire_vis[0],fire_vis[1000],0);
        queue<pair<int, int>> sang_pos;
        queue<pair<int, int>> fire_pos;
        for (int i = 0; i < h; i++)
            cin >> board[i];
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == '@')
                {
                    sang_pos.push({i, j});
                    sang_vis[i][j] = 1;
                }
                else if (board[i][j] == '*')
                {
                    fire_pos.push({i, j});
                    fire_vis[i][j] = 1;
                }
            }
        }
        while (!sang_pos.empty())
        {
            int x, y;
            tie(x, y) = sang_pos.front(); sang_pos.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 or nx >= h or ny < 0 or ny >= w) continue;
                if (board[nx][ny] != '.' or sang_vis[nx][ny] > 0)
                    continue;
                sang_vis[nx][ny] = sang_vis[x][y] + 1;
                sang_pos.push({nx, ny});
            }
        }
        while (!fire_pos.empty())
        {
            int x, y;
            tie(x, y) = fire_pos.front(); fire_pos.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 or nx >= h or ny < 0 or ny >= w)
                    continue;
                if (board[nx][ny] == '#' or fire_vis[nx][ny] > 0)
                    continue;
                fire_vis[nx][ny] = fire_vis[x][y] + 1;
                fire_pos.push({nx, ny});
            }
        }
        int mn = INT32_MAX;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                // cout << sang_vis[i][j] << ' ';
                if(i==0 or i==h-1 or j==0 or j==w-1){
                    if(sang_vis[i][j] != 0 and (fire_vis[i][j] == 0 or sang_vis[i][j] < fire_vis[i][j])){
                        mn = min(mn,sang_vis[i][j]);
                    }
                }
            }
            
            // cout << "\n";
        }
        if(mn == INT32_MAX) cout << "IMPOSSIBLE" << "\n";
        else cout << mn << "\n";
    }
}