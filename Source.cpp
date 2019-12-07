#include<iostream>

#define WORD_FROM_INPUT_STREAM_LAST_ITEM_INDEX 255

using namespace std;

bool pointInWord(char* wordFromInputStream)
{
	for (short int i = 0; wordFromInputStream[i] != '\0' && i != WORD_FROM_INPUT_STREAM_LAST_ITEM_INDEX; i++)
	{
		if (wordFromInputStream[i] == '.')
		{
			return true;
		}
	}
	return false;
}

void sequenceReading(char* preparedString, short int* indexOfLastItem)
{
	char* wordFromInputStream = new char[256];
	while (pointInWord(wordFromInputStream) == false)
	{
		cin >> wordFromInputStream;
		for (short int i = 0; wordFromInputStream[i] != '\0' && i != WORD_FROM_INPUT_STREAM_LAST_ITEM_INDEX; i++)
		{
			preparedString[*indexOfLastItem] = wordFromInputStream[i];
			*indexOfLastItem += 1;
		}
		preparedString[*indexOfLastItem] = ' ';
		*indexOfLastItem += 1;
	}
	*indexOfLastItem -= 1;
	preparedString[*indexOfLastItem] = '\0';

	delete[] wordFromInputStream;
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