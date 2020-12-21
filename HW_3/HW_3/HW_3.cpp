#include "pch.h"
#include <iostream>
#include <vector>
#include <Math.h>



using namespace std;

// 1.1
long long Fibonacci_iter(int n)
{
	if (n == 0 || n == 1)
		return n;

	long long n0 = 0, n1 = 1;
	long long temp;
	long long next = n0 + n1;

	for (int i = 2;  i <= n;  i++)
	{
		next = n0 + n1;

		n0 = n1; 
		n1 = next;
	}
	return next;
}
// 1.2
long long Fibonacci_Rec_simple(int n)
{
	if (n == 0 || n == 1)
		return n;
	return Fibonacci_Rec_simple(n - 2) + Fibonacci_Rec_simple(n - 1);
}
// 1.3

long long Fib_Rec_Memoi_Helper(vector<long long> &V, int n)
{
	if (V[n] != -1)
		return V[n];

	return V[n] = Fib_Rec_Memoi_Helper(V,n - 2) + Fib_Rec_Memoi_Helper(V,n - 1);
}
long long Fibonacci_Rec_Memoization(int n)
{
	vector<long long> V(n + 1, -1);
	V[0] = 0, V[1] = 1;

	return Fib_Rec_Memoi_Helper(V, n);
}
// ____________________________________________________________________________________________

//2.1)  Mathematical Formulation or Mathematical Induction / Recursion :
//		Tri_Sum(N) = Tri_Sum(N-3) + Tri_Sum(N-2) + Tri_Sum(N-1)

//		Hypothesis / Base Case : when N = 0, 1, 2 then Tri_Sum(N) = N

// 2.2
long long Tri_Sum_iter(int n)
{
	if (n == 0 || n == 1 || n == 2)
		return n;

	long long n0 = 0, n1 = 1, n2 = 2;
	long long temp;
	long long next = n0 + n1;

	for (int i = 3; i <= n; i++)
	{
		next = n0 + n1 + n2;

		n0 = n1;
		n1 = n2;
		n2 = next;
	}
	return next;
}

// 2.3
long long Tri_Sum_Rec_simple(int n)
{
	if (n == 0 || n == 1 || n == 2)
		return n;
	return Tri_Sum_Rec_simple(n - 3) + Tri_Sum_Rec_simple(n - 2) + Tri_Sum_Rec_simple(n - 1);
}

// 2.4
long long Tri_Sum_Rec_Memoi_Helper(vector<long long> &V, int n)
{
	if (V[n] != -1)
		return V[n];

	return V[n] = Tri_Sum_Rec_Memoi_Helper(V, n - 3) + Tri_Sum_Rec_Memoi_Helper(V, n - 2) + Tri_Sum_Rec_Memoi_Helper(V, n - 1);
}
long long Tri_Sum_Rec_Memoization(int n)
{
	vector<long long> V(n + 1, -1);
	V[0] = 0, V[1] = 1, V[2] = 2;

	return Tri_Sum_Rec_Memoi_Helper(V, n);
}
// ____________________________________________________________________________________________

//3.1 
long long N_Sum_1(int n) // 1+2+3+...+N
{
	if (n == 1)	
		return n;

	return n + N_Sum_1(n - 1);
}
//3.2 
long long N_Sum_2_Helper(int n)
{
	if (n == 1)
		return n;

	return n + N_Sum_1(n - 2);
}

long long N_Sum_2(int n) // 1 + 3 + 5 + ... + N (N Odd)
{
	if (n % 2 == 0)
	{
		cout << "\nN is Even!\n";
		return -1;
	}

	return N_Sum_2_Helper(n);
}
//3.3 
long long N_Sum_3(int n) // 1 + 2 + 4 + 8 + ... + 2^N
{
	if (n == 0)
		return pow(2, 0);

	return pow(2, n) + N_Sum_3(n - 1);
}
//3.4 
long long N_Sum_4(int n) // 1 + 3 + 9 + ... + 3^N"
{
	if (n == 0)
		return pow(3, 0);

	return pow(3, n) + N_Sum_4(n - 1);
}
//3.5 
long long N_Sum_5(int n) // 1 + 3 + 9 + ... + N/9 + N/3 + N"
{
	if (n <= 1)
		return n;

	return n + N_Sum_1(n/3);
}
//3.6 
long long N_Sum_6(int n) // 1 + 2 + 4 + 8 + ... + N/2 + N";
{
	if (n == 1)
		return n;

	return n + N_Sum_6(n / 2);
}

// ____________________________________________________________________________________________
//4.1
int NPR(int n, int r)
{
	if (r == 0)
		return 1;
	return n * NPR(n - 1, r - 1);
}

//4.2
int NCR(int n, int r)
{
	if (n == r || r == 0)
		return 1;

	return NCR(n - 1, r) + NCR(n - 1, r - 1);
}
// ____________________________________________________________________________________________

//5.1
int Linear_Search(vector<int> V, int size, int t)
{
	if (size == -1)
		return -1;
	else if (V[size - 1] == t) 
	{
		return size - 1;
	}
	return Linear_Search(V, size - 1, t);
}

//5.2

int Linear_Search_left_To_Right(vector<int> V, int size, int t, int s)
{
	if (size == s)
		return -1;
	else if (V[s] == t)
	{
		return s;
	}
	return Linear_Search_left_To_Right(V, size, t, s++);
}

void Task_5()
{
	vector<int> V(100);
	int n, choice, index;

	for (int i = 0; i < V.size(); i++)
	{
		V[i] = (rand() % 100) + 1;
	}
	cout << "Which Number you want to search : ";
	cin >> n;

	cout << "\n Option 1 : From Left to Right"
		<< "\n Option 2 : From Right To Left";

	cout << "\nEnter Option : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		index = Linear_Search(V, V.size(), n);
		if (index == -1)
			cout << "\n" << n << " is not found.";
		else
			cout << "\n" << n << " is found at Index : " << index;
		break;
	case 2:
		index = Linear_Search_left_To_Right(V, V.size(), n,0);
		if (index == -1)
			cout << "\n" << n << " is not found.";
		else
			cout << "\n" << n << " is found at Index : " << index;
		break;
	}
}
// ____________________________________________________________________________________________
//6
int BSrec(vector<int> V, int s, int e, int T)
{
	int mid = (s + e) / 2;
	if (s > e)
	{
		return -1;
	}
	if (V[mid] == T)
	{
		return mid;
	}
	else if (T > V[mid])
	{
		return BSrec(V, mid + 1, e, T);
	}
	else if (T < V[mid])
	{
		return BSrec(V, s, mid - 1, T);
	}
}

int Search(vector<int> V, int size, int T)
{
	return BSrec(V, 0, size - 1, T);
}

void Task_6()
{
	vector<int> V(10000);
	int n, index;

	for (int i = 0; i < V.size(); i++)
	{
		V[i] = (rand() % 100) + 1;
	}

	cout << "Which Number you want to search : ";
	cin >> n;

	index = Search(V, V.size(), n);
	if (index == -1)
		cout << "\n" << n << " is not found.";
	else
		cout << "\n" << n << " is found at Index : " << index;
}
// ____________________________________________________________________________________________
// 7
int Power(int x, int y)
{
	if (y == 0)
		return 1;
	return x * Power(x, y - 1);
}
void limit_Power(int x, int y, int m)
{
	int temp = Power(x, y);
	cout << "\n\nX^y = " << x << "^" << y << " = " << temp << "\n\n";
	cout << "\n\n(X^y) % m = (" << x << "^" << y << ") % " << m << " = " << (temp%m) << "\n\n";
}
int Fast_Power(int x, int y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
	{
		return pow(Fast_Power(x, (y / 2)), 2);
	}
	else
		return x * pow(Fast_Power(x, y / 2), 2);
}

void limit_Fast_Power(int x, int y, int m)
{
	int temp = Fast_Power(x, y);
	cout << "\n\nX^y = " << x << "^" << y << " = " << temp << "\n\n";
	cout << "\n\n(X^y) % m = (" << x << "^" << y << ") % " << m << " = " << (temp%m) << "\n\n";
}

void Task_7()
{
	int x, y, m;
	int choice;

	cout << "Enter X : ";
	cin >> x;
	cout << "Enter y : ";
	cin >> y;
	cout << "Enter m : ";
	cin >> m;

	cout << "\n Option 1 : Power (O(Y))"
		<< "\n Option 2 : Fast Power (O(LogY))";

	cout << "\nEnter Option : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		limit_Power(x,y,m);
		break;
	case 2:
		limit_Fast_Power(x,y,m);
		break;
	}
}

// ____________________________________________________________________________________________


//8
int Add_A_B_times(int A, int B)
{
	if (B == 0)
		return 0;
	int T = 1, Result = A;
	while (T + T <= B)
	{
		Result += Result;
		T += T;
	}
	return Result + Add_A_B_times(A, B - T);
}

int Mult(int A, int B)
{
	return Add_A_B_times(A, B);
}

void Task_8()
{
	int a, b;

	cout << "\nEnter A : ";
	cin >> a;

	cout << "\nEnter B : ";
	cin >> b;

	cout << "\nAXB = " << Mult(a,b);
}


void Menu()
{
	cout <<
		"Task No 1 : Fibonacci\n"
		"Task No 2 : Tri_Sum\n"
		"Task No 3 : N - Series Sum\n"
		"Task No 4 : nPr _ nCr\n"
		"Task No 5 : Linear Search\n"
		"Task No 6 : Binary Search\n"
		"Task No 7 : (X^y) % m \n"

		"Task No 8 : A X B\n"



		<<"\nTask No 10 : Exit";

	cout << "\n\nEnter Task No : ";

}
void sec_Menu_3_Options()
{
	cout << "\n Option 1 : Iteratively"
		<< "\n Option 2 : Recursively"
		<< "\n Option 3 : Recursive with memoization/Dynamic Programming";


	cout << "\nEnter Option : ";
}
void sec_Menu()
{
	cout << "\n Option 1 : Iteratively"
		<< "\n Option 2 : Recursively";

	cout << "\nEnter Option : ";
}
void sec_Menu_N_series()
{
	cout << "\n Option 1 : 1 + 2 + 3 + ... + N"
		<< "\n Option 2 :  1 + 3 + 5 + ... + N (N Odd)"
		<< "\n Option 3 :  1 + 2 + 4 + 8 + ... + 2^N"
		<< "\n Option 4 :  1 + 3 + 9 + ... + 3^N"
		<< "\n Option 5 :  1 + 3 + 9 + ... + N/9 + N/3 + N"
		<< "\n Option 5 :  1 + 2 + 4 + 8 + ... + N/2 + N";

	cout << "\nEnter Option : ";
}

void sec_Menu_nPr_nCr()
{
	cout << "\n Option 1 : nCr"
		<< "\n Option 2 : nPr";

	cout << "\nEnter Option : ";
}

void main()
{
	int choice,N;

	while (true)
	{
		Menu();
		cin >> choice;

		switch (choice)
		{
			case 1:
				sec_Menu_3_Options();
				cin >> choice;
				cout << "\nEnter N : ";
				cin >> N;
				switch (choice)
				{
				case 1:
					cout << "\n\nFibonacci ( " << N << " ) : " << Fibonacci_iter(N);
					break;
				case 2:
					cout << "\n\nFibonacci ( " << N << " ) : " << Fibonacci_Rec_simple(N);
					break;
				case 3:
					cout << "\n\nFibonacci ( " << N << " ) : " << Fibonacci_Rec_Memoization(N);
					break;
				}
				break;


			case 2:
				sec_Menu_3_Options();
				cin >> choice;
				cout << "\nEnter N : ";
				cin >> N;
				switch (choice)
				{
				case 1:
					cout << "\n\nTri_Sum( " << N << " ) : " << Tri_Sum_iter(N);
					break;
				case 2:
					cout << "\n\nTri_Sum ( " << N << " ) : " << Tri_Sum_Rec_simple(N);
					break;
				case 3:
					cout << "\n\nTri_Sum ( " << N << " ) : " << Tri_Sum_Rec_Memoization(N);
					break;
				}
				break;

			case 3:
				sec_Menu_N_series();
				cin >> choice;
				cout << "\nEnter N : ";
				cin >> N;
				switch (choice)
				{
				case 1:
					cout << "\n\n1 + 2 + 3 + ... + N(" << N << " ) : " << N_Sum_1(N);
					break;
				case 2:
					cout << "\n\n 1 + 3 + 5 + ... + N( " << N << " ) : " << N_Sum_2(N);
					break;
				case 3:
					cout << "\n\n 1 + 2 + 4 + 8 + ... + 2^N( " << N << " ) : " << N_Sum_3(N);
					break;
				case 4:
					cout << "\n\n 1 + 3 + 9 + ... + 3^N( " << N << " ) : " << N_Sum_4(N);
					break;
				case 5:
					cout << "\n\n1 + 3 + 9 + ... + N/9 + N/3 + N( " << N << " ) : " << N_Sum_5(N);
					break;
				case 6:
					cout << "\n\n 1 + 2 + 4 + 8 + ... + N/2 + N( " << N << " ) : " << N_Sum_6(N);
					break;
				}
				break;

			case 4:
				sec_Menu_nPr_nCr();
				cin >> choice;
				int r;
				cout << "Enter N : ";
				cin >> N;
				cout << "Enter R (must be smaller than N) : ";
				cin >> r ;
				switch (choice)
				{
				case 1:
					cout << "\n\n" << N << "C" << r << " = " << NCR(N, r);
					break;
				case 2:
					cout << "\n\n" << N << "P"<<r<<" = " << NPR(N,r);
					break;
				}
				break;
			case 5:
				Task_5();
				return;
			case 6:
				Task_6();
				return;
			case 7:
				Task_7();
				return;
			case 8:
				Task_8();
				return;
			case 10:
				return;
		}
		cout << "\n\n";
	}
	

    cout << "\n\n"; 
}
