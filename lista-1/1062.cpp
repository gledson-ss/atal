#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

int main()
{

  int wagons;
  int element = 1;
  while (true)
  {
    cin >> wagons;

    while (true)
    {

      vector<int> array_A;
      stack<int> station;
      vector<int> array_B;
      int larger = 0;

      for (size_t i = 0; i < wagons; i++)
      {
        cin >> element;

        if (element > larger)
        {
          larger = element;
        }
        if (!element)
        {
          break;
        }
        array_A.push_back(element);
      }

      if (!element)
      {
        break;
      }

      int element_current;
      while (!array_A.empty())
      {
        element_current = array_A.back();

        if (element_current == larger)
        {
          array_B.push_back(element_current);
          larger = larger - 1;

          while (!station.empty() && station.top() == larger)
          {
            array_B.push_back(station.top());
            larger = larger - 1;
            station.pop();
          }
        }
        else
        {
          station.push(element_current);
        }
        array_A.pop_back();
      }

      if (array_B.size() == wagons)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }

    if (!wagons and !element)
    {
      break;
    }
    cout << endl;
  }
  return 0;
}
