#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
  map<string, double> market;
  int cases;
  int products;
  int requests;
  string product_name;
  double product_value;
  double cash_value;
  int amount;
  cout << fixed << setprecision(2);
  cin >> cases;

  for (int i = 0; i < cases; i++)
  {
    cin >> products;
    cash_value = 0;
    for (size_t j = 0; j < products; j++)
    {
      cin >> product_name;
      cin >> product_value;

      market[product_name] = product_value;
    }

    cin >> requests;

    for (size_t k = 0; k < requests; k++)
    {
      cin >> product_name;
      cin >> amount;
      cash_value += market[product_name] * amount;
    }

    cout << "R$ " << cash_value << endl;
  }
  return 0;
}
