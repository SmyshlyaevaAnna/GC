#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, p, q, obj = 0, opt = 0;
    cin >> N >> M;
    vector <vector <int>> matrix;
    vector <int> color;
    vector <int> sum;
    color.resize(N);
    matrix.resize(N);
    sum.resize(N);
    for (int i = 0; i < N; i++)
    {
        color[i] = 0;
        matrix[i].resize(N);
        sum[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> p >> q;
        p--;
        q--;
        matrix[p][q] = 1;
        matrix[q][p] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum[i] = sum[i] + matrix[i][j];
        };
    }

    int t = 0, max = 0, k, c = 0, u = 0;
    while (t == 0)
    {
        c++;
        t = 1;
        u = 1;
        for (int i = 0; i < N; i++)
        {
            if ((sum[i] > max) && (color[i]==0)) max = sum[i];
            k = i;
        }
        color[k] = c;
        while (u == 0)
        {

            for (int i = 0; i < N; i++)
            {
                if (matrix[k][i] == 1)
                {
                    matrix[k][i] = 2;
                    matrix[i][k] = 2;
                } 
            }
            for (int i = 0; i < N; i++)
            {
                if ((matrix[k][i] == 0) && (color[i] == 0))
                {
                    color[i] = c;
                    k = i;
                    break;
                }
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (matrix[i][j] == 1) u = 0;
                };
                cout << endl;

            }

        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == 2) matrix[i][j] = 1;
            };
            cout << endl;

        }

        for (int i = 0; i < N; i++)
        {
            if (color[i] == 0) t = 0;
        }

    }

    cout << c << " " << opt << endl;
    for (int i = 0; i < N; i++)
    {
        cout << color[i] << " ";
    }


}
