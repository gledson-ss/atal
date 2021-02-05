#include <bits/stdc++.h>

using namespace std;

int main()
{
  int size;
  int points;

  cin >> size >> points;
  int point_list[size];

  for (int i = 0; i < points; i++)
  {
    cin >> point_list[i];
  }

  int dif_begin = point_list[0] - 1;
  int dif_end = size - point_list[points - 1];
  int dif_larger = 0;

  if (dif_end > dif_begin)
  {
    dif_larger = dif_end;
  }
  else
  {
    dif_larger = dif_begin;
  }
  int dif_aux = 0;
  for (size_t i = 0; i < points - 1; i++)
  {
    dif_aux = (point_list[i + 1] - point_list[i]) / 2;
    if (dif_aux > dif_larger)
    {
      dif_larger = dif_aux;
    }
  }
  cout << dif_larger << endl;
  return 0;
}
