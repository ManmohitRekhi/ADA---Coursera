#include<iostream>
#include<fstream>
//#include<conio.h> // For Windows only
#define N 100000

using namespace std;
long long int merge(long int a[], long int start, long int middle, long int end)
{
	long int i = start;
	long int j = middle;
	long int b[end - start];
	long int z = 0 , k = 0;
	long long int sum = 0;
	for(k = 0; k < end - start; k++)
	{
		if(a[i] < a[j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
			sum += middle - i;
		}
		if(i == middle)
		{
			z = 1;
			k++;
			break;	
		}
		if(j == end)
		{
		 	z = 2;
		 	k++;
		 	break;
		}
	}
	if(z == 1)
	{
		for(; k < end - start; k++)
		{
			b[k] = a[j];
			j++;
		}
	}
	else if(z == 2)
	{
		for(; k < end - start; k++)
		{
			b[k] = a[i];
			i++;
			//sum += end - middle;
		}
	}
	for(long int x = 0; x < end-start; x++)
	{
		a[start + x] = b[x];
	}
	return sum;
}

long long int mergesort(long int a[], long int start, long int end)
{
	long long int sum = 0;
	if(end-start == 1) return 0;
	sum += mergesort(a, start, (start + end)/2); //The first array is from start to end/2
	sum += mergesort(a,(start + end)/2, end);	//The second array is from end/2 to end
	sum += merge(a,start,(start + end)/2,end);
	return sum;
}

int main()
{
	long int a[N];
	long long int sum = 0;
	fstream fp ("input1.txt", ios::in); // Provide the full path name for the input file
	for(long int i = 0; i < N; i++)
	{
		fp >> a[i];
	}
	sum = mergesort(a,0,N);
	for(long int i = 0 ; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout<< endl;
	cout << sum;
	//getch();
	return 0;
}
