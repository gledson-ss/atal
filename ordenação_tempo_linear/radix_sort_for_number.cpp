#include <bits/stdc++.h>

using namespace std;
int getMax(int arr[], int n)
{
  int mx = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > mx)
      mx = arr[i];
  return mx;
}

void countSort(int arr[], int n, int exp)
{
  int output[n];
  int i, count[10] = {0};

  for (i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = n - 1; i >= 0; i--)
  {
    int value_arr = arr[i];
    int value_count = count[(value_arr / exp) % 10];
    output[value_count - 1] = value_arr;
    count[(value_arr / exp) % 10]--;
  }

  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixsort(int arr[], int n)
{

  int m = getMax(arr, n);

  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(arr, n, exp);
}

void print(int arr[], int n)
{
  cout << "[";
  for (int i = 0; i < n; i++)
  {
    if (i < n - 1)
      cout << arr[i] << ", ";
    else
      cout << arr[i];
  }
  cout << "]" << endl;
}

int main()
{
  int n;

  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  radixsort(arr, n);
  print(arr, n);
  return 0;
}
