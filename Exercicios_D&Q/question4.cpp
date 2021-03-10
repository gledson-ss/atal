#include <bits/stdc++.h>

using namespace std;

int quick_select(int arr[], int l, int r, int k)
{
  int v = arr[r];
  int i = l;

  for (size_t j = l; j < r; j++)
  {
    if (arr[j] <= v)
    {
      swap(arr[i], arr[j]);
      i++;
    }
  }

  swap(arr[i], arr[r]);

  int index = i;

  if (index - l == k - 1)
  {
    return arr[index];
  }

  if (index - l > k - 1)
  {
    return quick_select(arr, l, index - 1, k);
  }

  return quick_select(arr, index + 1, r, k - index + l - 1);
}

void showArr(int arr[], int count)
{
  for (size_t i = 0; i < count; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int max = 8;
  int res;
  int arr[max] = {43, 1, 3, 8, 7, 12, 0, 2};
  int arr2[max] = {3, 10, 1, 19, 18, 2, 13, 9};

  showArr(arr, max);
  res = quick_select(arr, 0, max - 1, 5);
  cout << "k = 5, "
       << "k-ésimo menor elemento: " << res << endl
       << endl;

  showArr(arr2, max);
  res = quick_select(arr2, 0, max - 1, 4);
  cout << "k = 4, "
       << "k-ésimo menor elemento: " << res << endl
       << endl;

  return 0;
}
