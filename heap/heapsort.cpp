#include <bits/stdc++.h>

using namespace std;

void max_Heapify(int *vetor, int i, int tamVetor)
{
  int left = 2 * i;
  int right = 2 * i + 1;
  int max;
  if (left <= tamVetor && vetor[left] > vetor[i])
  {
    max = left;
  }
  else
  {
    max = i;
  }
  if (right <= tamVetor && vetor[right] > vetor[max])
  {
    max = right;
  }
  if (max != i)
  {
    int aux = vetor[i];
    vetor[i] = vetor[max];
    vetor[max] = aux;
    max_Heapify(vetor, max, tamVetor);
  }
}

void build_Heap(int *vetor, int tamVetor)
{

  for (int i = tamVetor / 2; i >= 0; i--)
  {
    max_Heapify(vetor, i, tamVetor);
  }
}

void Heapsort(int *vetor, int tamVetor)
{
  build_Heap(vetor, tamVetor);
  for (int i = tamVetor; i >= 1; i--)
  {
    int aux = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = aux;
    tamVetor--;
    max_Heapify(vetor, 0, tamVetor);
  }
}
int main()
{
  int n;

  cout << "digite a quantidade de elementos: ";
  cin >> n;

  int arr[n];

  for (size_t i = 0; i < n; i++)
  {
    cout << "insira um elemento: ";
    cin >> arr[i];
  }

  Heapsort(arr, n);

  cout << "arr ordenado pelo heapsort:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
