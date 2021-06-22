#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;
#define RE
#define out fin
#define STR "This puzzle has no final configuration.";
char arr[5][6];
size_t swaps(char c, size_t &i, size_t &j)
{

    switch (c)
    {
    case 'A':
        if (i > 0)
        {
            swap(arr[i][j], arr[i - 1][j]);
            i--;
        }
        else
            return 0;
        /* code */
        break;
    case 'B':
        if (i < 4)
        {
            swap(arr[i][j], arr[i + 1][j]);
            i++;
        }
        else
            return 0;
        /* code */
        break;
    case 'L':
        if (j > 0)
        {
            swap(arr[i][j], arr[i][j - 1]);
            j--;
        }
        else
            return 0;
        /* code */
        break;
    case 'R':
        if (j < 4)
        {
            swap(arr[i][j], arr[i][j + 1]);
            j++;
        }
        else
            return 0;
        /* code */
        break;
    default:
        return 0;
        break;
    }
    return 1;
}
//wrong
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    size_t ix = -1, jx = -1, kase = 0;
    while (true)
    {
        if (kase)
            cout << endl;
        ix = -1, jx = -1;
        char ch;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {

                ch = getchar();
                if (ch == '\n')
                    ch = getchar();
                arr[i][j] = ch;
                if (arr[0][0] == 'Z')
                    return 0;
               
                if (arr[i][j] == ' ')
                {
                    ix = i;
                    jx = j;
                   
                }
            }
        }
         if (kase)cout << endl;
        char move;
        bool flag = 1;
        while (scanf("%c", &move) && move != '0')
        {
            if (move == '\n')
                continue;

            if (swaps(move, ix, jx) == 0)
                flag = 0;
        }
        getchar();
        printf("Puzzle #%zd:\n", ++kase);
        if (flag)
        {
            for (size_t i = 0; i < 5; i++)
            {
                for (size_t j = 0; j < 4; j++)
                    printf("%c ", arr[i][j]);
                printf("%c%s", arr[i][4], (i == 4) ? "" : "\n");
            }
        }
        else
            cout << STR;
    }
}