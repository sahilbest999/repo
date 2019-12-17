#include<iostream>
using namespace std;

int main()
{
int n, i, j,temp,d=0;

cout << "Enter the size of the array: ";
cin >> n;

int a[n],b[n];

for (i = 0; i <= n - 1; i++)
{
cout << "Enter element " << i + 1 << ": ";
cin >> a[i];
b[i] = a[i];
}

while (d != 3)
{
	
for (i = 0; i <= n - 1; i++)
{
for (j = i+1; j <= n - 1; j++)
{
if ((b[i] % 10) > (b[j] % 10))
{

temp = b[i]; //
b[i]=b[j];   //
b[j]=temp;   //

temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}

for (i = 0; i <= n - 1; i++) //
{
b[i] = b[i]/10;
}

++d;
}

for (i = 0; i <= n - 1; i++)
{
cout << "New : " << a[i] << endl;
}

return 0;
}
