#include <stdio.h>
#define n 4
int preference_check(int men_preference[n][n], int women_preference[n][n], int matching[n][2], int j, int p)
{

    for (int i = 0; i < n; i++)
    {
        if (matching[i][1] == p)
        {
            for (int x = 0; x < n; x++)
            {
                // printf("ok7\n");
                // printf("i=%d x=%d j=%d p=%d\n", i, x, j, p);
                if (women_preference[p][x] == i)
                {
                    // printf("ok\n");
                    return -1;
                }
                else if (women_preference[p][x] == j)
                {
                    // printf("ok8\n");
                    return i;
                }
            }
        }
    }
}
void stable_matching(int men_preference[n][n], int women_preference[n][n])
{
    int m_free[n];
    int w_free[n];
    int matching[n][2];
    for (int i = 0; i < n; i++)
        m_free[i] = -1;
    for (int i = 0; i < n; i++)
        w_free[i] = -1;
    for (int i = 0; i < n; i++)
    {
        matching[i][0] = -1;
        matching[i][1] = -1;
    }
    int freecount = n;
    while (freecount > 0)
    {
        int i;
        int j = 0;
        // for(int m=0;m<n;m++)
            // printf("%d ",m_free[m]);
        // printf("\n");
        for (i = 0; i < n; i++)
        {
            if (m_free[i] == -1)
            {
                // printf("ok1\n");
                break;
            }
        }
        for (int p = 0; p < n; p++)
        {
            if (w_free[men_preference[i][p]] == -1)
            {
                // printf("ok2\n");
                // printf("i=%d,men_preference[i][p]=%d\n",i,men_preference[i][p]);
                matching[i][0] = i;
                matching[i][1] = men_preference[i][p];
                m_free[i] = 0;
                w_free[men_preference[i][p]] = 0;
                freecount--;
                // for (int i = 0; i < n; i++)
                    // printf("%d %d\n", matching[i][0], matching[i][1]);
                break;
            }
            else
            {
                // printf("ok3\n");
                int compare = preference_check(men_preference, women_preference, matching, i, p);
                if (compare != -1)
                {
                    matching[compare][0] = -1;
                    matching[compare][1] = -1;
                    m_free[compare] = -1;
                    m_free[i] = 0;
                    // printf("compare== %d\n",compare);
                    matching[i][0] = i;
                    matching[i][1] = men_preference[i][p];
                    // for (int i = 0; i < n; i++)
                        // printf("%d %d\n", matching[i][0], matching[i][1]);
                    break;
                }
            }
        }
        // printf("\n");
    }
    // printf("\n\n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", matching[i][0], matching[i][1]);
}
int main()
{
    int men_preference[n][n] = {{0, 1,2,3}, 
                                {1, 0,3,2},
                                {0,2,1,3},
                                {2,1,3,0}};
    int women_preference[n][n] = {{2,1,0,3}, 
                                {0, 3,2,1},
                                {1,2,3,0},
                                {3,0,1,2}};
    // int men_preference[n][n] = {{0, 1}, 
    //                             {1, 0},};
    // int women_preference[n][n] = {{1,0}, 
    //                             {0,1},};
    stable_matching(men_preference, women_preference);
    return 0;
}