#include <stdio.h>

// int par_de_soma_s(int a[], int n, int s)
// {
//     int i, j;
//     for (i = 0; i < n; ++i)
//         for (j = i + 1; j < n; ++j)
//             if (a[i] + a[j] == s)
//                 return 1;
//     return 0;
// }
int par_soma_s(int a[], int n, int s){
    int i, j;
    for(i = 0; i < n; ++i){
        for(j = i + 1; j < n; ++j){
            if(a[i] + a[j] == s)
                return 1;
        }
    }

    return 0;
}