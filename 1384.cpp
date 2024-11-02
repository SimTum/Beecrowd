#include <iostream>
#include <queue>

using namespace std;

void solver(bool **checker, int **matrix, queue <pair<int,int>> *discovery)
{   
    int x = discovery->front().first;
    int y = discovery->front().second;
    discovery->pop();
    int counter = 24;
    checker[y][x] = 0;
    for (int i = -2; i < 3; i++)
    {
        for (int j = -2; j < 3; j++)
        {
            if (checker[y - i][x - j])
            {
                if (matrix[y - i][x - j] > matrix[y][x] + abs(i) + abs(j) + 3 && (abs(i) == 2 && abs(j) == 2))
                {
                    counter--;
                    matrix[y - i][x - j] = matrix[y][x] + abs(i) + abs(j) + 3;
                }
                if (matrix[y - i][x - j] == 0 && (abs(i) == 2 || abs(j) == 2))
                {
                    counter--;
                    matrix[y - i][x - j] = matrix[y][x] + abs(i) + abs(j) + 3;
                }

                if (matrix[y - i][x - j] > matrix[y][x] + abs(i) + abs(j) + 1 && (abs(i) != 2 && abs(j) != 2))
                {
                    counter--;
                    matrix[y - i][x - j] = matrix[y][x] + abs(i) + abs(j) + 1;
                }
                if (matrix[y - i][x - j] == 0 && (abs(i) == 1 || abs(j) == 1))
                {
                    counter--;
                    matrix[y - i][x - j] = matrix[y][x] + abs(i) + abs(j) + 1;
                }
            }
        }
    }
    // cout << counter << " counter test ";
    if (counter != 24)
    {
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (checker[y - i][x - j])
                {   
                    checker[y - i][x - j] = 0;
                    pair <int,int> coordinates;
                    coordinates.first = x - j;
                    coordinates.second = y - i;
                    discovery->push(coordinates);
                    solver(checker,matrix,discovery);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue <pair<int,int>> discovery;
    int rows = 1, columns = 1;
    pair<int, int> mrfrog, mstoad;
    while (1)
    {
        cin >> columns >> rows;
        if (rows == 0 && columns == 0)
            break;
        cin >> mrfrog.first >> mrfrog.second >> mstoad.first >> mstoad.second;
        int wet_zones, swamp[rows + 4][columns + 4] = {0};
        bool checker[rows + 4][columns + 4] = {0};
        for (int i = 2; i < rows + 2; i++)
        {
            for (int j = 2; j < columns + 2; j++)
            {
                checker[i][j] = 1;
            }
        }
        cin >> wet_zones;
        for (int i = 0; i < wet_zones; i++)
        {
            pair<int, int> wet_size1, wet_size2;
            cin >> wet_size1.first >> wet_size1.second;
            cin >> wet_size2.first >> wet_size2.second;
        
            for (int j = wet_size1.second + 1; j <= wet_size2.second + 1; j++)
            {
                for (int k = wet_size1.first + 1; k <= wet_size2.first + 1; k++)
                {
                    checker[j][k] = 0;
                }
            }
        }

        int **array;
        bool **barray;
        array = new int *[rows + 4];
        barray = new bool *[rows + 4];
        for (int i = 0; i < rows + 4; i++)
        {
            array[i] = new int[columns + 4];
            barray[i] = new bool[columns + 4];
        }
        for (int i = 0; i < rows + 4; i++)
        {
            for (int j = 0; j < columns + 4; j++)
            {
                array[i][j] = swamp[i][j];
                barray[i][j] = checker[i][j];
                // cout << barray[i][j] << " ";
            }
            // cout << "\n";
        }
        mrfrog.first +=1;
        mrfrog.second +=1;
        discovery.push(mrfrog);
        solver(barray, array, &discovery);
        if(array[mstoad.second+1][mstoad.first+1] == 0) cout << "impossible\n";
        else cout << array[mstoad.second+1][mstoad.first +1] << "\n";
        // solver(barray, array, mrfrog.first + 2, mrfrog.second + 2);
        // cout << " TEST \n\n";
        // for (int i = 0; i < rows + 4; i++)
        // {
        //     for (int j = 0; j < columns + 4; j++)
        //     {
        //         cout << array[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    return 0;
}
