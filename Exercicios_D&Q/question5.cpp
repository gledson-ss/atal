#include <bits/stdc++.h>

using namespace std;

int medianTwoArrays(int arrA[], int arrB[], int n)
{
  int i = 0;
  int j = 0;

  int med1 = -1;
  int med2 = -1;

  for (size_t count = 0; count <= n; count++)
  {

    if (i == n)
    {
      med1 = med2;
      med2 = arrB[0];
      break;
    }

    else if (j == n)
    {
      med1 = med2;
      med2 = arrA[0];
      break;
    }

    if (arrA[i] <= arrB[j])
    {
      med1 = med2;
      med2 = arrA[i];
      i++;
    }
    else
    {
      med1 = med2;
      med2 = arrB[j];
      j++;
    }
  }

  return (med1 + med2) / 2;
}

int main()
{
  int n;
  cout << "digite o tamanho do vetor:" << endl;
  cin >> n;

  int arrA[n], arrB[n];

  cout << "digite os valores " << n << " para arrA" << endl;

  for (size_t i = 0; i < n; i++)
  {
    cin >> arrA[i];
  }
  cout << endl;
  cout << "digite os valores " << n << " para arrB" << endl;

  for (size_t i = 0; i < n; i++)
  {
    cin >> arrB[i];
  }
  cout << endl;

  int mediaArrays = medianTwoArrays(arrA, arrB, n);
  cout << "o valor da mediana total entre eles eh: " << mediaArrays << endl;
  return 0;
}
