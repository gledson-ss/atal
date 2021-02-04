#include <iostream>
#include <stack>

using namespace std;
int main()
{
  stack<int> pilha;

  for (size_t i = 0; i < 6; i++)
  {
    pilha.push(i);
  }

  while (pilha.top() == 5 - 1)
  {
    cout << pilha.top() << endl;
    pilha.pop();
  }

  return 0;
}
