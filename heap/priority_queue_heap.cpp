#include "bits/stdc++.h"

using namespace std;

class Priority_queue_heap
{

private:
  void swap(int *a, int *b)
  {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
  }
  int get_element(int pos)
  {
    if ((pos > 1) && (pos < this->array_size))
    {
      return pos / 2;
    }
    return -1;
  }
  void max_heapify(int i)
  {
    int left = 2 * i;
    int right = 2 * i + 1;
    int max;
    if (left <= this->array_size && this->A[left] > this->A[i])
    {
      max = left;
    }
    else
    {
      max = i;
    }
    if (right <= this->array_size && this->A[right] > this->A[max])
    {
      max = right;
    }
    if (max != i)
    {
      int aux = this->A[i];
      this->A[i] = this->A[max];
      this->A[max] = aux;
      max_heapify(max);
    }
  }

public:
  int heap_size;
  int array_size;
  int *A;

  Priority_queue_heap()
  {
    this->heap_size = 0;
    this->array_size = 10000;
    this->A = (int *)malloc(10000 * sizeof(int));
  }

  int extract_max()
  {
    int maxm = this->A[1];
    this->A[1] = this->A[heap_size];
    heap_size--;
    this->max_heapify(1);
    return maxm;
  }

  void increase_key(int pos, int key)
  {
    this->A[pos] = key;
    while ((pos > 1) && (this->A[this->get_element(pos)] < this->A[pos]))
    {
      this->swap(&this->A[pos], &this->A[this->get_element((pos))]);
      pos = this->get_element(pos);
    }
  }

  void insert(int key)
  {
    this->heap_size++;
    this->A[this->heap_size] = INT16_MIN;
    this->increase_key(this->heap_size, key);
  }

  int heap_maximum()
  {
    return this->A[1];
  }

  void print()
  {
    cout << "[";

    for (int i = 1; i <= this->heap_size; i++)
    {
      if (i != this->heap_size)
      {
        cout << this->A[i] << ", ";
      }
      else
      {
        cout << this->A[i];
      }
    }
    cout << "]" << endl;
  }
};

int main()
{
  Priority_queue_heap pqh;

  int n;
  int value;

  cout << "fila de prioridade utilizando heap" << endl;

  cout << "digite a quantidade de elementos: ";
  cin >> n;

  for (size_t i = 0; i < n; i++)
  {
    cout << endl;
    cout << "digite um valor para inserir: ";
    cin >> value;
    cout << endl;
    pqh.insert(value);
    cout << "lista atual com " << i + 1 << " elemento(s) com uma capacidade de " << n << " no total" << endl;
    pqh.print();
    cout << "maior valor da lista atualmente: " << pqh.heap_maximum() << endl;
  }
  return 0;
}
