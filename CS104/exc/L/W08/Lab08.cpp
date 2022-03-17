#include <iostream>
#include <string>

using namespace std;

// 26,42,5,44,92,59,40,36,12


/// ------------------------------------------------------------------------ ///
///                               Declarations                               ///
/// ------------------------------------------------------------------------ ///

struct ARRAY
{
	int arr[100] =  {26,42,5,44,92,59,40,36,12};
};

void PrintArray(const ARRAY &, int);

ARRAY LinearProbing(const ARRAY &, int), QuadraticProbing(const ARRAY &, int), DoubleHashing(const ARRAY &, int);



/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

int main()
{
	int size;
	
	size = 11;
	
	// cout << "Hash table size: ";
	// cin >> size;
	
	ARRAY input;
	// for (int i = 0; i < size; i++)
	// {
	// 	cout << "Enter number " << i + 1 << ": ";
	// 	cin >> input.arr[i];
	// }
	
	DoubleHashing(input, size);
	
	// PrintArray(LinearProbing(input, size), size);
	// PrintArray(QuadraticProbing(input, size), size);
	// PrintArray(DoubleHashing(input, size), size);
	
	return 0;
}

void PrintArray(const ARRAY &arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr.arr[i] == -1) cout << "--" << " ";
		else cout << arr.arr[i] << " ";
	}
	
	cout << "\n\n";
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
		
		int h1 = input.arr[i] % size;
		
		if (output.arr[h1] == -1)
		{
			output.arr[h1] = input.arr[i];
		}
		
		else
		{
			if (output.arr[h1] == input.arr[i])
			{
				continue;
			}
			
			else
			{
				bool dup = false;
				
				do
				{
					h1++;
					
					if (output.arr[h1] == input.arr[i])
					{
						dup = true;
						break;
					}
					
					if (h1 >= size)
					{
						h1 = 0;
					}
				}
				while (output.arr[h1] != -1);
				
				if (dup == false) output.arr[h1] = input.arr[i];
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
		
		int h1 = input.arr[i] % size;
		
		if (output.arr[h1] == -1)
		{
			output.arr[h1] = input.arr[i];
		}
		
		else
		{
			if (output.arr[h1] == input.arr[i])
			{
				continue;
			}
			
			else
			{
				for (int j = 0; j < size; j++)
				{
					int x = (h1 + j * j) % size;
					
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
		if (input.arr[i] == -1)
		{
			PrintArray(output, size);
			continue;
		}
		
		
		int h1 = input.arr[i] % size;
		
		if (output.arr[h1] == -1)
		{
			output.arr[h1] = input.arr[i];
			PrintArray(output, size);
		}
		
		else
		{
			if (output.arr[h1] == input.arr[i])
			{
				PrintArray(output, size);
				continue;
			}
			
			else
			{
				for (int j = 1; j < size; j++)
				{
					int h2 = (h1 + j*((input.arr[i] % 9) + 1)) % size;
					
					if (output.arr[h2] == input.arr[i])
					{
						PrintArray(output, size);
						// cout << "\tx=" << x << "\tpos=" << pos << "\tj=" << j << "\n";
						break;
					}
					
					else if (output.arr[h2] == -1)
					{
						output.arr[h2] = input.arr[i];
						
						PrintArray(output, size);
						// cout << "\tx=" << x << "\tpos=" << pos << "\tj=" << j << "\n";
						break;
					}
				}
			}
		}
	}
	
	return output;
}