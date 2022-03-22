#include <iostream>
#include <vector>



/// ------------------------------------------------------------------------ ///
///                               Declarations                               ///
/// ------------------------------------------------------------------------ ///

struct VECTOR
{
	std::vector<int> keys;
};

void 	PrintVct(const VECTOR &);

VECTOR	NewVct(),
		LinearProbing(const VECTOR &),
		QuadraticProbing(const VECTOR &),
		DoubleHashing(const VECTOR &);



/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

int main()
{
	int size;
	
	std::cout << "Hash table size: ";
	std::cin >> size;
	
	VECTOR input;
	for (int i = 0; i < size; i++)
	{
		int inp;
		
		std::cout << "Enter number " << i + 1 << " (-1 to stop): ";
		std::cin >> inp;
		
		if (inp == -1)
		{
			for (int j = 0; j < (size - i); j++)
			{
				input.keys.push_back(-1);
			}
			
			break;
		}
		
		else input.keys.push_back(inp);
	}
	
	PrintVct(LinearProbing(input));
	PrintVct(QuadraticProbing(input));
	PrintVct(DoubleHashing(input));
	
	return 0;
}

void PrintVct(const VECTOR &vct)
{
	for (int i = 0; i < vct.keys.size(); i++)
	{
		if (vct.keys[i] == -1) std::cout << "--" << " ";
		else std::cout << vct.keys[i] << " ";
	}
	
	std::cout << "\n\n";
}

VECTOR NewVct()
{
	VECTOR vct;
	
	for (int i = 0; i < 100; i++)
	{
		vct.keys.push_back(-1);
	}
	
	return vct;
}

VECTOR LinearProbing(const VECTOR &input)
{
	VECTOR output;
	int size = input.keys.size();
	
	for (int i = 0; i < size; i++)
	{
		output.keys.push_back(-1);
	}
	
	for (int i = 0; i < size; i++)
	{
		if (input.keys[i] == -1) break;
		
		int h1 = input.keys[i] % size;
		
		if (output.keys[h1] == -1)
		{
			output.keys[h1] = input.keys[i];
		}
		
		else
		{
			if (output.keys[h1] == input.keys[i])
			{
				continue;
			}
			
			else
			{
				bool dup = false;
				
				do
				{
					h1++;
					
					if (output.keys[h1] == input.keys[i])
					{
						dup = true;
						break;
					}
					
					if (h1 >= size)
					{
						h1 = 0;
					}
				}
				while (output.keys[h1] != -1);
				
				if (dup == false) output.keys[h1] = input.keys[i];
			}
		}
	}
	
	return output;
}

VECTOR QuadraticProbing(const VECTOR &input)
{
	VECTOR output;
	int size = input.keys.size();
	
	for (int i = 0; i < size; i++)
	{
		output.keys.push_back(-1);
	}
	
	for (int i = 0; i < size; i++)
	{
		if (input.keys[i] == -1) continue;
		
		int h1 = input.keys[i] % size;
		
		if (output.keys[h1] == -1)
		{
			output.keys[h1] = input.keys[i];
		}
		
		else
		{
			if (output.keys[h1] == input.keys[i])
			{
				continue;
			}
			
			else
			{
				for (int j = 0; j < size; j++)
				{
					int x = (h1 + j * j) % size;
					
					if (output.keys[x] == input.keys[i])
					{
						break;
					}
					
					else if (output.keys[x] == -1)
					{
						output.keys[x] = input.keys[i];
						break;
					}
				}
			}
		}
	}
	
	return output;
}

VECTOR DoubleHashing(const VECTOR &input)
{
	VECTOR output;
	int size = input.keys.size();
	
	for (int i = 0; i < size; i++)
	{
		output.keys.push_back(-1);
	}
	
	for (int i = 0; i < size; i++)
	{
		if (input.keys[i] == -1)
		{
			break;
		}
		
		
		int h1 = input.keys[i] % size;
		
		if (output.keys[h1] == -1)
		{
			output.keys[h1] = input.keys[i];
			
			// PrintVct(output, size);
		}
		
		else
		{
			if (output.keys[h1] == input.keys[i])
			{
				continue;
			}
			
			else
			{
				for (int j = 1; j < size; j++)
				{
					//? Secondary hash function
					int h2 = (h1 + j*((input.keys[i] % 9) + 1)) % size;
					
					if (output.keys[h2] == input.keys[i])
					{
						break;
					}
					
					else if (output.keys[h2] == -1)
					{
						output.keys[h2] = input.keys[i];
						
						// PrintVct(output, size);
						// std::cout << "\th1=" << h1 << "\th2=" << h2 << "\tj=" << j << "\n";
						break;
					}
				}
			}
		}
	}
	
	return output;
}