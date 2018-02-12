#include <iostream>
#include <stdlib.h>
#include <stdio.h>

typedef struct student Student;
typedef struct lesson Lesson;
typedef struct cell Cell;
typedef struct charCell CharCell;

using namespace std;

struct charCell {
	char x;
	CharCell * nextCharCell;
};

struct student {
	char stuNum[7];
	CharCell* firstName;
	CharCell* lastName;
	float avg;
	int unitsSum;
	CharCell* passedLessons;
};

struct lesson {
	char lessonCode[8];
	char lessonName[19];
	int lessonUnit;
	char lessonTeacher[21];
	int lessonScore;
};

struct cell {
	Student stuData;
	Cell * nextPtr;
};

void createStudentFile()
{
	FILE* fileName = fopen("students.txt","w");
	fclose(fileName);
}

void printInStudentsFile(char stuNum[7], char* firstName, char* lastName)
{
	FILE* fileName = fopen("students.txt", "r+");
	fseek(fileName, 0, SEEK_END);
	fprintf(fileName, "%s %s %s %.2f %d %s\n", stuNum, firstName, lastName, 0.0, 0, "/");
	fclose(fileName);
}

/* This function create a linkList of students from the 'students.txt' file and returns the 'Cell* head' of the link list */
Cell* createLinkListOfStudentsFile()
{
	Cell * head, *current, *newCell;
	Student tempStudent;
	char stuNum[7], tempCharForFscanf;
	CharCell* firstName;
	CharCell* lastName;
	float avg;
	int unitsSum;
	CharCell* passedLessons;
	FILE* fileName = fopen("students.txt", "r+");
	if(!feof(fileName))
	{
		fscanf(fileName, "%s", stuNum);

		{ /* These line in this block gets the firsname and make a linkkest of it and assign the head of the 
		   link list to the firstName CharCell pointer */
			CharCell * headCharCell, *currentCharCell, *newCharCell;
			headCharCell = (CharCell *)malloc(sizeof(CharCell));
			headCharCell->nextCharCell = NULL;
			fscanf(fileName, "%c", &tempCharForFscanf);
			fscanf(fileName, "%c", &tempCharForFscanf);
			headCharCell->x = tempCharForFscanf;
			currentCharCell = headCharCell;
			fscanf(fileName, "%c", &tempCharForFscanf);
			while (tempCharForFscanf != ' ' && tempCharForFscanf != '\n')
			{
				newCharCell = (CharCell *)malloc(sizeof(CharCell));
				newCharCell->nextCharCell = NULL;
				newCharCell->x = tempCharForFscanf;
				currentCharCell->nextCharCell = newCharCell;
				currentCharCell = newCharCell;
				fscanf(fileName, "%c", &tempCharForFscanf);
			}
			firstName = headCharCell;
		}

		{ /* These line in this block gets the lastname and make a linkkest of it and assign the head of the
		  link list to the lastname CharCell pointer */
			CharCell * headCharCell, *currentCharCell, *newCharCell;
			headCharCell = (CharCell *)malloc(sizeof(CharCell));
			headCharCell->nextCharCell = NULL;
			fscanf(fileName, "%c", &tempCharForFscanf);
			headCharCell->x = tempCharForFscanf;
			currentCharCell = headCharCell;
			fscanf(fileName, "%c", &tempCharForFscanf);
			while (tempCharForFscanf != ' ' && tempCharForFscanf != '\n')
			{
				newCharCell = (CharCell *)malloc(sizeof(CharCell));
				newCharCell->nextCharCell = NULL;
				newCharCell->x = tempCharForFscanf;
				currentCharCell->nextCharCell = newCharCell;
				currentCharCell = newCharCell;
				fscanf(fileName, "%c", &tempCharForFscanf);
			}
			lastName = headCharCell;
		}

		fscanf(fileName, "%f", &avg);
		fscanf(fileName, "%f", &unitsSum);

		{ /* These line in this block gets the pasedLessons and make a linkkest of it and assign the head of the
		  link list to the pasedLessons CharCell pointer */
			CharCell * headCharCell, *currentCharCell, *newCharCell;
			headCharCell = (CharCell *)malloc(sizeof(CharCell));
			headCharCell->nextCharCell = NULL;
			fscanf(fileName, "%c", &tempCharForFscanf);
			fscanf(fileName, "%c", &tempCharForFscanf);
			headCharCell->x = tempCharForFscanf;
			currentCharCell = headCharCell;
			fscanf(fileName, "%c", &tempCharForFscanf);
			while (tempCharForFscanf != ' ' && tempCharForFscanf != '\n')
			{
				newCharCell = (CharCell *)malloc(sizeof(CharCell));
				newCharCell->nextCharCell = NULL;
				newCharCell->x = tempCharForFscanf;
				currentCharCell->nextCharCell = newCharCell;
				currentCharCell = newCharCell;
				fscanf(fileName, "%c", &tempCharForFscanf);
			}
			passedLessons = headCharCell;
		}

		strcpy(tempStudent.stuNum, stuNum);
		tempStudent.firstName = firstName;
		tempStudent.lastName = lastName;
		tempStudent.avg = avg;
		tempStudent.unitsSum = unitsSum;
		tempStudent.passedLessons = passedLessons;

	}
	head = (Cell*)malloc(sizeof(Cell));
	head->nextPtr = NULL;
	head->stuData = tempStudent;
	current = head;
	while (!feof(fileName))
	{
		newCell = (Cell*)malloc(sizeof(Cell));
		newCell->nextPtr = NULL;
		if (!feof(fileName))
		{
			fscanf(fileName, "%s", stuNum);

			{ /* These line in this block gets the firsname and make a linkkest of it and assign the head of the
			  link list to the firstName CharCell pointer */
				CharCell * headCharCell, *currentCharCell, *newCharCell;
				headCharCell = (CharCell *)malloc(sizeof(CharCell));
				headCharCell->nextCharCell = NULL;
				fscanf(fileName, "%c", &tempCharForFscanf);
				if (tempCharForFscanf == '\n')
					break;
				fscanf(fileName, "%c", &tempCharForFscanf);
				headCharCell->x = tempCharForFscanf;
				currentCharCell = headCharCell;
				fscanf(fileName, "%c", &tempCharForFscanf);
				while (tempCharForFscanf != ' ' && tempCharForFscanf != '\n')
				{
					newCharCell = (CharCell *)malloc(sizeof(CharCell));
					newCharCell->nextCharCell = NULL;
					newCharCell->x = tempCharForFscanf;
					currentCharCell->nextCharCell = newCharCell;
					currentCharCell = newCharCell;
					fscanf(fileName, "%c", &tempCharForFscanf);
				}
				firstName = headCharCell;
			}

		{ /* These line in this block gets the lastname and make a linkkest of it and assign the head of the
		  link list to the lastname CharCell pointer */
			CharCell * headCharCell, *currentCharCell, *newCharCell;
			headCharCell = (CharCell *)malloc(sizeof(CharCell));
			headCharCell->nextCharCell = NULL;
			fscanf(fileName, "%c", &tempCharForFscanf);
			headCharCell->x = tempCharForFscanf;
			currentCharCell = headCharCell;
			fscanf(fileName, "%c", &tempCharForFscanf);
			while (tempCharForFscanf != ' ' && tempCharForFscanf != '\n')
			{
				newCharCell = (CharCell *)malloc(sizeof(CharCell));
				newCharCell->nextCharCell = NULL;
				newCharCell->x = tempCharForFscanf;
				currentCharCell->nextCharCell = newCharCell;
				currentCharCell = newCharCell;
				fscanf(fileName, "%c", &tempCharForFscanf);
			}
			lastName = headCharCell;
		}

		fscanf(fileName, "%f", &avg);
		fscanf(fileName, "%f", &unitsSum);

		{ /* These line in this block gets the pasedLessons and make a linkkest of it and assign the head of the
		  link list to the pasedLessons CharCell pointer */
			CharCell * headCharCell, *currentCharCell, *newCharCell;
			headCharCell = (CharCell *)malloc(sizeof(CharCell));
			headCharCell->nextCharCell = NULL;
			fscanf(fileName, "%c", &tempCharForFscanf);
			fscanf(fileName, "%c", &tempCharForFscanf);
			headCharCell->x = tempCharForFscanf;
			currentCharCell = headCharCell;
			fscanf(fileName, "%c", &tempCharForFscanf);
			while (tempCharForFscanf != ' ' && tempCharForFscanf != '\n')
			{
				newCharCell = (CharCell *)malloc(sizeof(CharCell));
				newCharCell->nextCharCell = NULL;
				newCharCell->x = tempCharForFscanf;
				currentCharCell->nextCharCell = newCharCell;
				currentCharCell = newCharCell;
				fscanf(fileName, "%c", &tempCharForFscanf);
			}
			passedLessons = headCharCell;
		}

		strcpy(tempStudent.stuNum, stuNum);
		tempStudent.firstName = firstName;
		tempStudent.lastName = lastName;
		tempStudent.avg = avg;
		tempStudent.unitsSum = unitsSum;
		tempStudent.passedLessons = passedLessons;

		}

		newCell->stuData = tempStudent;
		current->nextPtr = newCell;
		current = newCell;
	}
	fclose(fileName);
	return head;
}

/* This function gets a 'CharCell*' and follow it's link list to print the string in the 'FILE* fileName' that has passed to it. */
void printThisStringLinkList(CharCell* headChar, FILE* fileName)
{
	for (CharCell* i = headChar; i != NULL; i = i->nextCharCell)
	{
		fprintf(fileName, "%c", i->x);
	}
}

/* This function gets the 'Cell*' link list head and prints it row by row in the 'students.txt' file. */
void printStudentLinkListInStudentsFile(Cell* head)
{
	FILE* fileName = fopen("students.txt", "w");
	for (Cell* i = head; i != NULL; i = i->nextPtr)
	{
		fprintf(fileName, "%s ", i->stuData.stuNum);
		printThisStringLinkList(i->stuData.firstName, fileName);
		fprintf(fileName, "%c", ' ');
		printThisStringLinkList(i->stuData.lastName, fileName);
		fprintf(fileName, "%c", ' ');
		fprintf(fileName, "%f", i->stuData.avg);
		fprintf(fileName, "%c", ' ');
		fprintf(fileName, "%d", i->stuData.unitsSum);
		fprintf(fileName, "%c", ' ');
		printThisStringLinkList(i->stuData.passedLessons, fileName);
		fprintf(fileName, "%c", '\n');
	}
	fclose(fileName);
}

/* This function add a new student data to the end of the link list of the students */
/*void addToTheEndOfStudentsLinkList(Cell* head, char stuNum[7], char* firstName, char* lastName)
{
	Cell* lastCell, * newCell;
	for (Cell* i = head; i != NULL; i = i->nextPtr)
		lastCell = i;
	newCell = (Cell*)malloc(sizeof(Cell));
	newCell->nextPtr = NULL;
	newCell->stuData = cellDataToAdd;
	lastCell->nextPtr = newCell;
}*/

void clearThisStudentsLinkListFromStack(Cell* head)
{
	Cell* nextCellPtr;
	for (Cell* i = head; i != NULL; i = nextCellPtr)
	{
		nextCellPtr = i->nextPtr;
		free(i);
	}
}

int main()
{
	createStudentFile();
	printInStudentsFile("123456", "hadi", "hajhosseini");
	printInStudentsFile("234567", "reza", "hajhosseini");
	printInStudentsFile("345678", "peyman", "hosseini");
	Cell* head = createLinkListOfStudentsFile();
	clearThisStudentsLinkListFromStack(head);
	printInStudentsFile("456789", "mehdi", "dehghan");
	head = createLinkListOfStudentsFile();
	//printStudentLinkListInStudentsFile(head);
}
