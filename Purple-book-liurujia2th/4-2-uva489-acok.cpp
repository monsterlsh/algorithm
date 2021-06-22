#include <iostream>
#include <cstring>
using namespace std;
#define RE
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    string str;
    size_t letters[26] = {0};
    size_t kase, strokes,flag=-1;
    while (scanf("%zd", &kase) && kase != flag)
    {
        printf("Round %zd\n",kase);
        memset(letters, 0, sizeof(letters));
        strokes = 7;
        cin >> str;
        size_t sum = 0;
        for (char c : str)
            letters[c - 'a']=1;
        for(size_t dx :letters)
            dx>=1?++sum:0;  
        cin >> str;
        size_t win = 2;
        for (char c : str)
        {
           size_t dx=c-'a';
           if(letters[dx]==1){
                sum--;
                letters[dx]=2;
           }
           if(letters[dx]==0){
                strokes--;
                letters[dx]=3;
           }
            if (strokes <= 0)
            {
                win = 0;
                break;
            }
            if (sum == 0)
            {
                win = 1;
                break;
            }
        }
        if (win == 0)
            printf("You lose.\n");
        else if (win == 2)
            printf("You chickened out.\n");
        else
            printf("You win.\n");
    }
}
