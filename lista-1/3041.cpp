#include <bits/stdc++.h>

using namespace std;

int main()
{
  int reviewers;

  while (true)
  {
    cin >> reviewers;

    if (not reviewers)
    {
      break;
    }

    int sum = 0;
    int articles = 0;
    int number = 0;
    int answer[reviewers] = {};
    int array[reviewers];
    int index;
    int limit;

    for (size_t i = 0; i < reviewers; i++)
    {
      cin >> array[i];
      sum += array[i];
    }
    cin >> articles;

    if (sum < articles)
    {
      cout << "Impossible" << endl;
    }
    else
    {
      sort(array, array + reviewers, greater<int>());
      index = 0;
      limit = reviewers;

      while (articles > 0)
      {
        if (array[index] > 0)
        {
          array[index]--;
          answer[index]++;
          articles--;
        }

        index++;

        if (index == limit)
        {
          index = 0;
        }
      }
      for (size_t i = 0; i < reviewers; i++)
      {
        cout << answer[i] << endl;
      }
    }
  }

  return 0;
}
