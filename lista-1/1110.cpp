#include <bits/stdc++.h>
#include <vector>
#include <list>

using namespace std;

int main()
{
  list<int> cards_stack;
  list<int> discarded_cards;
  int remaining_card;
  int size;
  bool isDiscarted = true;
  while (true)
  {
    cin >> size;
    if (!size)
    {
      break;
    }

    for (size_t i = 1; i <= size; i++)
    {
      cards_stack.push_back(i);
    }

    while (!cards_stack.empty())
    {
      discarded_cards.push_back(cards_stack.front());
      cards_stack.pop_front();
      cards_stack.push_back(cards_stack.front());
      cards_stack.pop_front();
    }
    remaining_card = discarded_cards.back();
    discarded_cards.pop_back();

    int count = discarded_cards.size();
    cout << "Discarded cards: ";
    for (size_t i = 0; i < count; i++)
    {
      if (i == count - 1)
      {
        cout << discarded_cards.front() << endl;
      }
      else
      {
        cout << discarded_cards.front() << ", ";
      }
      discarded_cards.pop_front();
    }

    cout << "Remaining card: " << remaining_card << endl;
  }

  return 0;
}
