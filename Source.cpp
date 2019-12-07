#include<iostream>

using namespace std;

bool pointInWord(char* word)
{
	for (short int i = 0; word[i] != '\0' && i != 256; i++)
	{
		if (word[i] == '.')
		{
			return true;
		}
	}
	return false;
}

void sequenceReading(char* preparedString, short int* indexOfLastItem)
{
	char* word = new char[256];
	while (pointInWord(word) == false)
	{
		cin >> word;
		for (short int i = 0; word[i] != '\0' && i != 256; i++)
		{
			preparedString[*indexOfLastItem] = word[i];
			*indexOfLastItem += 1;
		}
		preparedString[*indexOfLastItem] = ' ';
		*indexOfLastItem += 1;
	}
	*indexOfLastItem -= 1;
	preparedString[*indexOfLastItem] = '\0';

	delete[] word;
}

void sequenceSpaceProcessing()
{

}

void sequenceSignsProcessing()
{

}

void sequenceRegisterProcessing()
{

}

void sequenceTask()
{

}

int main()
{
	char* preparedString = new char[1024 * 1024];
	short int* indexOfLastItem = new short int(0);
	sequenceReading(preparedString, indexOfLastItem);
	cout << preparedString;
	system("pause");

	delete[] preparedString;
	delete indexOfLastItem;
	return 0;
}