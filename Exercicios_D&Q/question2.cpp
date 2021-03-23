#include <bits/stdc++.h>

using namespace std;

void Insertion_sort(int *lista, int ini, int tam)
{
  int aux;
  for (int j = ini; j < tam; j++)
  {
    int n = lista[j];
    aux = j - 1;

    while (aux >= 0 && lista[aux] > n)
    {
      lista[aux + 1] = lista[aux];
      aux--;
    }

    lista[aux + 1] = n;
  }
}

void merge(int *lista, int ini, int meio, int fim)
{
  int t1 = meio - ini + 1;
  int t2 = fim - meio;

  int esq[t1], dir[t2];

  for (int i = 0; i < t1; i++)
  {
    esq[i] = lista[ini + i];
  }
  for (int i = 0; i < t2; i++)
  {
    dir[i] = lista[meio + i + 1];
  }

  int i = 0;
  int j = 0;
  int k = ini;

  while (i < t1 && j < t2)
  {
    if (esq[i] <= dir[j])
    {
      lista[k] = esq[i++];
    }
    else
    {
      lista[k] = dir[j++];
    }
    k++;
  }
  while (i < t1)
  {
    lista[k] = esq[i++];
    k++;
  }

  while (j < t2)
  {
    lista[k] = dir[j++];
    k++;
  }
}

void mergeSort(int *lista, int i, int f)
{
  if (f - i <= 100)
  {
    Insertion_sort(lista, i, f);
    cout << "usou" << endl;
  }
  else
  {
    if (i < f)
    {
      int m = (i + f) / 2;
      mergeSort(lista, i, m);
      mergeSort(lista, m + 1, f);
      merge(lista, i, m, f);
    }
  }
}

void showArr(int *arr, int count)
{
  for (size_t i = 0; i < count; i++)
  {
    std::cout << arr[i] << " ";
  }
  cout << endl;
  cout << endl;
}
int main()
{
  clock_t start, end;
  int max;
  max = 100;
  srand(time(0));

  int arrForMerge[max];
  int arrForInsertion[max];

  for (size_t i = 0; i < max; i++)
  {
    arrForMerge[i] = rand() % max; //create random numbers for arrForMerge
  }
  for (size_t i = 0; i < max; i++)
  {
    arrForInsertion[i] = rand() % max; //create random numbers for arrForInsertion
  }

  cout << "arr 1" << endl;
  showArr(arrForMerge, max);
  cout << "arr 2" << endl;
  showArr(arrForInsertion, max);
  cout << endl;

  cout << endl;

  start = clock();
  mergeSort(arrForMerge, 0, max);
  end = clock();

  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

  cout << "merge sort taken " << time_taken << "seconds" << endl;
  cout << "arr 1 ordened" << endl;
  showArr(arrForMerge, max);

  start = clock();
  Insertion_sort(arrForInsertion, 0, max);
  end = clock();
  time_taken = double(end - start) / double(CLOCKS_PER_SEC);

  cout << "insertion sort taken " << time_taken << "seconds" << endl;
  cout << "arr 2 ordened" << endl;
  showArr(arrForInsertion, max);

  cout << "apos implementar o insertion sort dentro do merge sorte, pude ver um melhor tempo de execução do algortimo" << endl;
  cout << "o merge passou de aproximadamente 7~5 e-05 segundos, para aproximadamente 4~3 e-05 segundos, para os casos de testes utilizados" << endl;
  return 0;
}
