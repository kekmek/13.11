#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n , m;
    scanf("%d%d", &n, &m);
    if( n%2 == 0)
        n = n + 1;
    else
        n = n;
    if( m%2 == 0)
        m = m + 1;
    else
        m = m;
    int ** p = (int**)malloc(sizeof(int*)*n);
    int i = 0;

    for(i = 0; i < n ; i++)
    {
        p[i] = (int*)malloc(sizeof(int)*m);
    }
    int k = 0, j = 0;
    int maxx = -1;
    for( i = 0; i < n*m; i++)
    {
        if(i % 10 == 9)
        {
            maxx = i;
        }
        else
            continue;
    }
    while (  k<= n+m )
    {
        for( i = 0 + k; i < n - k; i++)
        {
           for( j = 0 + k; j < m-k; j++)
           {
               p[i][j] =  maxx - 10*k;
           }
        }
        k++;
    }



    FILE *f = fopen("a.txt", "w+");
    for(i = 0 ;  i< n ; i++)
    {
        for( j = 0; j < m ; j++)
        {
            fprintf(f, "%d ", p[i][j]);
        }
        fprintf(f, "\n", p[i][j] );

    }
    for(i = 0 ; i < n; i++)
    {
        free(p[i]);
    }
    free(p);
    fclose(f);
    return 0;
}



