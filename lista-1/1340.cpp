#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Queue
{
public:
  queue<int> qu;
  string name = "queue";
  bool is = true;
};

class Priority_queue
{
public:
  priority_queue<int> pq;
  string name = "priority queue";
  bool is = true;
};

class Stack
{
public:
  stack<int> st;
  string name = "stack";
  bool is = true;
};

class Answer
{
public:
  int count = 3;
  string show[4] = {"impossible", "", "not sure", "not sure"};
};
int main()
{

  int cases;
  int operation, value;

  while (cin >> cases)
  {
    Queue qu;
    Priority_queue pq;
    Stack st;
    Answer ans;

    for (size_t i = 0; i < cases; i++)
    {
      cin >> operation >> value;

      if (operation == 1)
      {
        qu.qu.push(value);
        pq.pq.push(value);
        st.st.push(value);
      }
      else
      {
        if (qu.qu.front() != value and qu.is)
        {
          qu.is = false;
          ans.count--;
        }

        if (pq.pq.top() != value and pq.is)
        {
          pq.is = false;
          ans.count--;
        }

        if (st.st.top() != value and st.is)
        {
          st.is = false;
          ans.count--;
        }

        qu.qu.pop();
        pq.pq.pop();
        st.st.pop();
      }
    }
    if (ans.count == 1)
    {
      if (pq.is)
      {
        cout << "priority queue" << endl;
      }
      if (qu.is)
      {
        cout << "queue" << endl;
      }
      if (st.is)
      {
        cout << "stack" << endl;
      }
    }
    else
    {
      cout << ans.show[ans.count] << endl;
    }
  }
  return 0;
}
