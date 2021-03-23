#include <limits.h>
#include <bits/stdc++.h>

using namespace std;

int Max(int a, int b, int c)
{
  int maior = 0;
  if (a > b)
  {
    maior = a;
  }
  else
  {
    maior = b;
  }

  /* cout << a << " " << b << " " << c << endl; */
  return max(maior, c);
}

int sum_mid_array(int arr[], int i, int m, int f)
{
  int sum = 0;
  int sum_esq = INT_MIN;
  int sum_dir = INT_MIN;

  for (size_t i = 0; i < m; i++)
  {
    sum += arr[i];
    if (sum > sum_esq)
      sum_esq = sum;
  }
  sum = 0;

  for (size_t i = m; i < f; i++)
  {
    sum += arr[i];
    if (sum > sum_dir)
      sum_dir = sum;
  }

  return Max(sum_esq + sum_dir, sum_esq, sum_dir);
}

int sum_array(int arr[], int i, int f)
{
  if (i == f)
    return arr[i];

  int m = (i + f) / 2;

  int esq = sum_array(arr, i, m);
  int dir = sum_array(arr, m + 1, f);
  int meio = sum_mid_array(arr, i, m, f);

  return Max(esq, dir, meio);
}

int main()
{
  int max = 10;
  /* cin >> max; */

  int arr[max] = {-2, 3, 2, -9};
  /* 
  for (size_t i = 0; i < max; i++)
  {
    cin >> arr[i];
  } */
  int res = sum_array(arr, 0, 4);

  cout << res << endl;
  return 0;
}
