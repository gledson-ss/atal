#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
  map<char, double> notes = {{'W', 1.0}, {'H', (1.0 / 2.0)}, {'Q', (1.0 / 4.0)}, {'E', (1.0 / 8.0)}, {'S', (1.0 / 16.0)}, {'T', (1.0 / 32.0)}, {'X', (1.0 / 64.0)}};

  int answer;
  double count_temp;
  while (true)
  {
    string measure;
    cin >> measure;
    answer = 0;
    count_temp = 0;
    if (measure[0] == '*')
    {
      break;
    }

    for (size_t i = 0; i < measure.size(); i++)
    {
      if (measure[i] == '/')
      {
        if (count_temp == 1.0)
        {
          answer++;
        }
        count_temp = 0;
      }
      else
      {
        count_temp += notes[measure[i]];
      }
    }
    cout << answer << endl;
  }
  return 0;
}
