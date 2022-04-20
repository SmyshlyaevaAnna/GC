#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N, M, opt = 0, obj = -1, p, q;
    cin >> N >> M;
    vector<pair<int, int>> connect;
    vector<vector<int>> matrix;
    matrix.resize(N);
    for (int i = 0; i < N; i++)
    {
        matrix[i].resize(N);
    }
    connect.resize(N, make_pair(0, 0));
    for (int i = 0; i < M; i++)
    {
        cin >> p >> q;
        matrix[p][q] = 1;
        matrix[q][p] = 1;
        connect[p].first += 1;
        connect[q].first += 1;
        connect[p].second = p;
        connect[q].second = q;
    }
    sort(connect.begin(), connect.end());
    vector<int> count;
    for (int i =N - 1; i > -1; i--) 
    {
        count.push_back(connect[i].second);
    }
    vector<int>color(N, -1);
    for (int it : count) 
    {
        int i = it;
        vector<bool> c(N, false);
        for (int j = 0; j < N; j++) 
        {
            if (matrix[i][j] == 1) 
            {
                if (color[j] > -1) 
                {
                    c[color[j]] = true;
                }
            }
        }
        for (int k = 0; k < N; k++) 
        {
            if (c[k] == false) 
            {
               color[i] = k;
               break;
            }
        }
    }
    for (int i = 0; i <color.size(); i++) 
    {
        if (color[i] > obj) 
        {
            obj = color[i];
        }
    }
    cout << obj+1 << " " << opt << " " << endl;
   // for (int i = 0; i < N; i ++) 
   // {
      //  cout << color[i] << " ";
    //}
}