#include <stdio.h>

int main()
{
  int m, t;
  scanf("%d %d", &m, &t);

  // TOTAL DOS QUE FORAM
  int totalIda[m];

  for (int i = 0; i < m; i++)
  {
    totalIda[i] = i + 1;
  }

  // TODOS QUE VOLTARAM
  int totalVolta[t];

  for (int i = 0; i < t; i++)
  {
    int x;
    scanf("%d", &x);
    if (x <= m)
    {
      totalVolta[i] = x;
    }
  }

  for (int i = 0; i < t; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (totalVolta[i] == totalIda[j])
      {
        totalIda[j] = 0;
      }
    }
  }

  if (m == t)
  {
    printf("%s", "*");
  }
  else
  {
    for (int i = 0; i < m; i++)
    {
      if (totalIda[i] != 0 && totalIda[i] != -1)
      {
        printf("%d ", totalIda[i]);
      }
    }
  }

  return 0;
}
