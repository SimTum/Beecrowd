#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int width, height;
    cin >> width >> height;
    char layout[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> layout[i][j];
        }
    }
    int i = 0, j = 0;
    if (layout[0][0] == '.')
    {
        cout << "!";
        return 0;
    }
    while (true)
    {
        char dir;
        switch (layout[i][j])
        {
        case '>':
        {
            layout[i][j] = '!';
            dir = 'r';
            break;
        }
        case '<':
        {
            layout[i][j] = '!';
            dir = 'l';
            break;
        }
        case '^':
        {
            layout[i][j] = '!';
            dir = 'u';
            break;
        }
        case 'v':
        {
            layout[i][j] = '!';
            dir = 'd';
            break;
        }
        case '.':
        {
            break;
        }
        case '*':
        {
            cout << "*\n";
            return 0;
        }

        default:
            cout << "!\n";
            return 0;
        }

        switch (dir)
        {
        case 'r':
        {
            j++;
            break;
        }
        case 'l':
        {
            j--;
            break;
        }
        case 'u':
        {
            i--;
            break;
        }
        case 'd':
        {
            i++;
            break;
        }
        default:
            break;
        }
        if (i > height || j > width)
        {
            cout << "!\n";
            return 0;
        }
    }
    return 0;
}