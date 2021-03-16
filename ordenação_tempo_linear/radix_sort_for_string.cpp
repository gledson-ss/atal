#include <bits/stdc++.h>

using namespace std;

void countSort(string arr[], int n, int exp)
{
  string output[n];
  int i, count[27 + 97] = {0};

  for (i = 0; i < n; i++)
  {
    /* cout << int(arr[i][exp]) << endl; */
    count[int(arr[i][exp])]++;
  }

  /* for (size_t j = 97; j < 27 + 97; j++)
  {
    cout << j << " = " << count[j] << endl;
  } */

  for (i = 1 + 97; i < 27 + 97; i++)
    count[i] += count[i - 1];

  for (i = n - 1; i >= 0; i--)
  {
    char value_arr = arr[i][exp];
    int value_count = count[int(value_arr)];
    output[value_count - 1] = arr[i];
    count[int(value_arr)]--;
  }

  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixsort(string arr[], int n)
{

  for (int i = 4; i >= 0; i--)
  {
    countSort(arr, n, i);
  }
}

void print(string arr[], int n)
{
  cout << endl;
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

  string arr[n];

  for (int j = 0; j < n; j++)
  {
    cin >> arr[j];
  }

  radixsort(arr, n);
  print(arr, n);
  return 0;
}
