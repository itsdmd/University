#include <iostream>
#include <string>

using namespace std;

// 26,42,5,44,92,59,40,36,12


/// ------------------------------------------------------------------------ ///
///                               Declarations                               ///
/// ------------------------------------------------------------------------ ///

struct ARRAY
{
	int arr[100];
};

void PrintArray(const ARRAY &, int);

ARRAY LinearProbing(const ARRAY &, int), QuadraticProbing(const ARRAY &, int), DoubleHashing(const ARRAY &, int);



/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

int main()
{
	int size;
	
	cout << "Hash table size: ";
	cin >> size;
	
	ARRAY input;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> input.arr[i];
	}
	
	PrintArray(LinearProbing(input, size), size);
	PrintArray(QuadraticProbing(input, size), size);
	PrintArray(DoubleHashing(input, size), size);
	
	return 0;
}

void PrintArray(const ARRAY &arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr.arr[i] == -1) cout << "N" << " ";
		else cout << arr.arr[i] << " ";
	}
	
	cout << endl;
}

ARRAY LinearProbing(const ARRAY &input, int size)
{
	ARRAY output;
	
	for (int i = 0; i < size; i++)
	{
		output.arr[i] = -1;
	}
	
	for (int i = 0; i < size; i++)
	{
		if (input.arr[i] == -1) continue;
		
		int pos = input.arr[i] % size;
		
		if (output.arr[pos] == -1)
		{
			output.arr[pos] = input.arr[i];
		}
		
		else
		{
			if (output.arr[pos] == input.arr[i])
			{
				continue;
			}
			
			else
			{
				bool dup = false;
				
				do
				{
					pos++;
					
					if (output.arr[pos] == input.arr[i])
					{
						dup = true;
						break;
					}
					
					if (pos >= size)
					{
						pos = 0;
					}
				}
				while (output.arr[pos] != -1);
				
				if (dup == false) output.arr[pos] = input.arr[i];
			}
		}
	}
	
	return output;
}

ARRAY QuadraticProbing(const ARRAY &input, int size)
{
	ARRAY output;
	
	for (int i = 0; i < size; i++)
	{
		output.arr[i] = -1;
	}
	
	for (int i = 0; i < size; i++)
	{
		if (input.arr[i] == -1) continue;
		
		int pos = input.arr[i] % size;
		
		if (output.arr[pos] == -1)
		{
			output.arr[pos] = input.arr[i];
		}
		
		else
		{
			if (output.arr[pos] == input.arr[i])
			{
				continue;
			}
			
			else
			{
				for (int j = 0; j < size; j++)
				{
					int x = (pos + j * j) % size;
					
					if (output.arr[x] == input.arr[i])
					{
						break;
					}
					
					else if (output.arr[x] == -1)
					{
						output.arr[x] = input.arr[i];
						break;
					}
				}
			}
		}
	}
	
	return output;
}

ARRAY DoubleHashing(const ARRAY &input, int size)
{
	ARRAY output;
	
	for (int i = 0; i < size; i++)
	{
		output.arr[i] = -1;
	}
	
	for (int i = 0; i < size; i++)
	{
		if (input.arr[i] == -1) continue;
		
		int pos = input.arr[i] % size;
		
		if (output.arr[pos] == -1)
		{
			output.arr[pos] = input.arr[i];
		}
		
		else
		{
			if (output.arr[pos] == input.arr[i])
			{
				continue;
			}
			
			else
			{
				for (int j = 0; j < size; j++)
				{
					int x = (pos + j*((pos % 9) + 1)) % size;
					
					if (output.arr[x] == input.arr[i])
					{
						break;
					}
					
					else if (output.arr[x] == -1)
					{
						output.arr[x] = input.arr[i];
						break;
					}
				}
			}
		}
	}
	
	return output;
}