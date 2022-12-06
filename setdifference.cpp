#include<bits/stdc++.h>
using namespace std;

void SetDifference(int a[], int m, int b[], int n)
{
    int c[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < m)
    {
        c[k++] = a[i++];
    }
    cout << "Array After Set Difference :\n";
    for (int i = 0; i < k; i++)
        cout << c[i] << " ";
    cout << endl;
}
int main()
{
    int n, m;
    cout<<"enter the both array size"<<endl;
    cin >> n >> m;
    int a[n], b[m];

    cout<<"enter the both arrays"<<endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];
        
    SetDifference(a, n, b, m);
 return 0;
}

