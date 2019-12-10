#include<iostream>
#include<sstream>

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

bool thisCharIsNumber(char now)
{
	if ((int(now) > 47) and (int(now) < 58))
	{
		return true;
	}
	else
	{
		return false;
	}
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

bool excessSpace(char now, char buffer)
{
	if (now == ' ' and buffer == ' ')
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

void sequenceExcessSpaceProcessing(char* preparedString, short int* indexOfLastItem)
{
	short int* counter = new short int(1);
	while (*counter != 0)
	{
		*counter = 0;
		for (short int i = 0; preparedString[i] != '\0' && i != PREPARED_STRING_LAST_ITEM_INDEX; i++)
		{
			if (excessSpace(preparedString[i], preparedString[i - 1]) == true and i != 0)
			{
				for (short int j = i; j < *indexOfLastItem - 1; j++)
				{
					preparedString[j] = preparedString[j + 1];
				}
				*indexOfLastItem -= 1;
				*counter += 1;
			}
		}
	}
	preparedString[*indexOfLastItem] = '\0';
	delete counter;
}

void sequenceRegisterProcessing(char* preparedString)
{
	for (short int i = 0; preparedString[i] != '\0' && i != PREPARED_STRING_LAST_ITEM_INDEX; i++)
	{
		if (i != 0)
		{
			preparedString[i] = tolower(preparedString[i]);
		}
		else
		{
			preparedString[i] = toupper(preparedString[i]);
		}
	}
}

void sequenceTask(char* preparedString, short int* indexOfLastItem)
{
	char* wordFromInputStream = new char[256];
	short int* counterNumber = new short int(0);
	short int* i = new short int;
	for (short int j = 0; j < 3; j++)
	{
		istringstream stream(preparedString);
		wordFromInputStream[0] = '\0';
		while (pointInWord(wordFromInputStream) == false)
		{
			stream >> wordFromInputStream;
			for (*i = 0; wordFromInputStream[*i] != '\0' && *i != WORD_FROM_INPUT_STREAM_LAST_ITEM_INDEX; *i += 1)
			{
				if (thisCharIsNumber(wordFromInputStream[*i]) == true)
				{
					*counterNumber += 1;
				}
			}
			if (j == 0 and *counterNumber == 0)
			{
				cout << wordFromInputStream << " ";
			}
			if (j == 1 and *counterNumber != 0 and *counterNumber != *i)
			{
				cout << wordFromInputStream << " ";
			}
			if (j == 2 and *counterNumber != 0 and *counterNumber == *i)
			{
				cout << wordFromInputStream << " ";
			}
			*counterNumber = 0;
		}
	}
	cout << "\n";

	delete[] wordFromInputStream;
	delete counterNumber;
	delete i;
}

int main()
{
	char* preparedString = new char[1024 * 1024];
	short int* indexOfLastItem = new short int(0);
	sequenceReading(preparedString, indexOfLastItem);
	cout << *indexOfLastItem << "\n";
	sequenceExcessSignsProcessing(preparedString);
	sequenceSignsTruePositionsProcessing(preparedString, indexOfLastItem);
	sequenceExcessSpaceProcessing(preparedString, indexOfLastItem);
	sequenceRegisterProcessing(preparedString);
	cout << preparedString << "\n";
	cout << *indexOfLastItem << "\n";
	sequenceTask(preparedString, indexOfLastItem);
	system("pause");

	delete[] preparedString;
	delete indexOfLastItem;
	return 0;
}