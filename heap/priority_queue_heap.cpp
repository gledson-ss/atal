#include "bits/stdc++.h"

using namespace std;

class Priority_queue_heap
{

private:
  int heap_size;
  int array_size;
  int *A;
  void swap(int *a, int *b)
  {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
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
  Priority_queue_heap()
  {
    this->heap_size = 0;
    this->array_size = 10000;
    this->A = (int *)malloc(10000 * sizeof(int));
  }

  int remove_heap_maximum()
  {
    int maxm = this->A[1];
    this->A[1] = this->A[heap_size];
    heap_size--;
    this->max_heapify(1);
    return maxm;
  }

  void insert(int key)
  {
    this->heap_size++;
    this->A[this->heap_size] = INT16_MIN;
    this->increase_key(this->heap_size, key);
  }

  int get_heap_maximum()
  {
    return this->A[1];
  }

  int get_array_size()
  {
    return this->heap_size;
  }
};

int main()
{
  Priority_queue_heap pqh;

  int n;
  int value;
  int option;
  cout << "fila de prioridade utilizando heap" << endl;

  cout << "digite a quantidade de iterações, se quer inserir ou remover: ";
  cin >> n;

  for (size_t i = 0; i < n; i++)
  {
    cout << endl;
    cout << "inserir digite 1, remover digite 2" << endl;
    cin >> option;
    if (option == 1)
    {
      cout << "digite um valor: ";
      cin >> value;
      pqh.insert(value);
      cout << endl;
    }
    else
    {
      if (!pqh.get_array_size())
      {
        cout << "não há elementos para remover" << endl;
      }
      else
      {
        pqh.remove_heap_maximum();
      }
    }

    cout << "lista atual com " << i + 1 << " elemento(s)." << endl;
    cout << "maior valor da lista atualmente: " << pqh.get_heap_maximum() << endl;
  }
  cout << "lista final com tamanho " << pqh.get_array_size() << endl;

  return 0;
}
