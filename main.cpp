#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cerr << "Error: cannot open input.txt\nPlease check the file name.\n";
        return 1;
    }

    ofstream fout("output.txt");
    if (!fout) {
        cerr << "Error: cannot open output.txt for writing\n";
        return 1;
    }

    int Row, Column;
    fin >> Row >> Column;

    vector< vector<int> > grid(Row, vector<int>(Column));
    for (int i = 0; i < Row; ++i)
        for (int j = 0; j < Column; ++j)
            fin >> grid[i][j];

    vector< vector<bool> > visited(
        Row, vector<bool>(Column, false)
    );
    vector< vector< pair<int,int> > > parent(
        Row, vector< pair<int,int> >(Column, pair<int,int>(-1, -1))
    );
    vector< vector<char> > moveDir(
        Row, vector<char>(Column, '\0')
    );

    int dr[4] = { -1, 0, 1,  0 };
    int dc[4] = {  0, 1, 0, -1 };
    char dch[4] = { 'N','E','S','W' };

    queue< pair<int,int> > q;
    visited[0][0] = true;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        int i = cur.first, j = cur.second;
        int step = grid[i][j];

        for (int d = 0; d < 4; ++d) {
            int ni = i + dr[d] * step;
            int nj = j + dc[d] * step;
            if (ni >= 0 && ni < Row && nj >= 0 && nj < Column
                && !visited[ni][nj])
            {
                visited[ni][nj] = true;
                parent[ni][nj] = make_pair(i, j);
                moveDir[ni][nj] = dch[d];
                q.push(make_pair(ni, nj));
            }
        }
    }

    if (!visited[Row-1][Column-1]) {
        fout << "No path found\n";
    } else {
        vector<char> path;
        int ci = Row-1, cj = Column-1;
        while (ci != 0 || cj != 0) {
            path.push_back(moveDir[ci][cj]);
            pair<int,int> p = parent[ci][cj];
            ci = p.first;
            cj = p.second;
        }
        for (int k = path.size() - 1; k >= 0; --k) {
            fout << path[k] << (k > 0 ? ' ' : '\n');
        }
    }

    return 0;
}
