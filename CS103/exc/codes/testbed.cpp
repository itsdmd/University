#include <iostream>
using namespace std;



string Encryptor(string inp)
{
	char encryption_key[3] = { '\3', '\1', '\5' };
	int j = 0;

	string output = inp;

	for (int i = 0; i < inp.size(); i++)
	{
		output[i] = inp[i] ^ encryption_key[j];
		j++;

		if (j == 3)
			j = 0;
	}

	return output;
}



int main()
{
    string str = Encryptor("");
    cout << str;
    
    return 0;
}