#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, p, q, obj = 0, opt = 0;
    cin >> N >> M;
    vector <vector <int>> arr;
    vector <vector <int>> matrix;
    vector <int> color;
    vector <int> sum;
    arr.resize(M);
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
        arr[i].resize(2);
        cin >> p >> q;
        arr[i][0] = p;
        arr[i][1] = q;
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
        while (u == 0)
        {

            t = 1;
            for (int i = 0; i < N; i++)
            {
                if (sum[i] > max) max = sum[i];
                k = i;
            }
            color[k] = c;
            for (int i = 0; i < N; i++)
            {
                if (color[i] == 0) t = 0;
            }
            for (int i = 0; i < N; i++)
            {

            }

        }

    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        };
        cout << endl;

    }


}
