#include <iostream>
using namespace std;

int main()
{
  int i, n, e, x, p, t, j;

  cout << "enter the size of the array" << endl;
  cin >> n;
  int a[n];
  cout << "enter the array elements" << endl;
  for (i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  cout << "enter the element to be deletion" << endl;
  cin >> e;

  for (i = 0; i < n; i++)
  {
    if (e == a[i])
    {
      p = i;
      t = 1;
    }
  }

  if (t = 1)
  {
    for (i = p + 1; i < n; i++)
    {
      a[i - 1] = a[i];
    }
  }
  else
  {
    cout << "element is not present in array";
  }

  cout << "new array is" << endl;
  for (i = 0; i < n - 1; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}