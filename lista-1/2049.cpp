#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{

  bool hasSignature;
  bool contaim;
  int instance = 1;
  while (true)
  {
    string signature;
    string block;

    cin >> signature;

    if (signature[0] == '0')
    {
      break;
    }
    if (instance > 1)
    {
      cout << endl;
    }
    cin >> block;
    hasSignature = false;
    for (size_t i = 0; i < block.size(); i++)
    {

      if (signature[0] == block[i])
      {

        contaim = true;
        for (size_t j = 0, k = i; j < signature.size(); j++, k++)

        {

          if (signature[j] != block[k])
          {
            contaim = false;
            break;
          }
          i = k;
        }
        if (contaim)
        {
          hasSignature = true;
        }
      }
    }
    cout << "Instancia " << instance << endl;
    instance++;
    if (hasSignature)
    {
      cout << "verdadeira" << endl;
    }
    else
    {
      cout << "falsa" << endl;
    }
  }
  return 0;
}
