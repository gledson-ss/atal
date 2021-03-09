#include <bits/stdc++.h>

using namespace std;

int soma_max(int a[], int tam)
{
  int soma = 0;
  int maior_soma = 0;
  for (size_t i = 0; i < tam; i++)
  {
    soma += a[i];

    soma = max(soma, 0);
    maior_soma = max(soma, maior_soma);
  }
  return maior_soma;
}

int main()
{
  int tam;
  while (true)
  {

    cin >> tam;

    if (tam == 0)
    {
      break;
    }
    int lista[100000] = {};

    for (int i = 0; i < tam; i++)
    {
      cin >> lista[i];
    }

    int resposta = soma_max(lista, tam);

    if (resposta)
    {
      cout << "The maximum winning streak is " << resposta << "." << endl;
    }
    else
    {
      cout << "Losing streak." << endl;
    }
  }
  return 0;
}
