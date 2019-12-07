#include<iostream>

#define WORD_FROM_INPUT_STREAM_LAST_ITEM_INDEX 255
#define PREPARED_STRING_LAST_ITEM_INDEX ((1024 * 1024) - 1)

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

bool excessSigns(char now, char buffer)
{
	if ((now == ',' and buffer == ',') or (now == ';' and buffer == ';') or (now == ':' and buffer == ':'))
	{
		return true;
	}
	else
	{
		return false;
	}
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

void sequenceExcessSignsProcessing(char* preparedString)
{
	char* buffer = new char(' ');
	for (short int i = 0; preparedString[i] != '\0' && i != PREPARED_STRING_LAST_ITEM_INDEX; i++)
	{
		if (preparedString[i - 1] != ' ' and i != 0)
		{
			*buffer = preparedString[i - 1];
		}
		if (excessSigns(preparedString[i], *buffer) == true)
		{
			preparedString[i] = ' ';
		}
	}
	delete buffer;
}

void sequenceSignsTruePositionsProcessing(char* preparedString, short int* indexOfLastItem)
{
	short int* counter = new short int(1);
	while (*counter != 0)
	{
		*counter = 0;
		for (short int i = 0; preparedString[i] != '\0' && i != PREPARED_STRING_LAST_ITEM_INDEX; i++)
		{
			if (preparedString[i] == '.' and preparedString[i - 1] == ' ')
			{
				preparedString[i - 1] = '.';
				preparedString[i] = '\0';
				*indexOfLastItem -= 1;
				break;
			}
			if (preparedString[i] == ',' and preparedString[i - 1] == ' ')
			{
				preparedString[i - 1] = ',';
				preparedString[i] = ' ';
				*counter += 1;
			}
			else if (preparedString[i] == ';' and preparedString[i - 1] == ' ')
			{
				preparedString[i - 1] = ';';
				preparedString[i] = ' ';
				*counter += 1;
			}
			else if (preparedString[i] == ':' and preparedString[i - 1] == ' ')
			{
				preparedString[i - 1] = ':';
				preparedString[i] = ' ';
				*counter += 1;
			}
		}
	}
	delete counter;
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
	cout << preparedString << "\n";
	cout << *indexOfLastItem << "\n";
	sequenceExcessSignsProcessing(preparedString);
	cout << preparedString << "\n";
	cout << *indexOfLastItem << "\n";
	sequenceSignsTruePositionsProcessing(preparedString, indexOfLastItem);
	cout << preparedString << "\n";
	cout << *indexOfLastItem << "\n";
	system("pause");

	delete[] preparedString;
	delete indexOfLastItem;
	return 0;
}