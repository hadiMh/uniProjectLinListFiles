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

int main()
{
	createStudentFile();
	printInStudentsFile("123456", "hadi", "hajhosseini");
	printInStudentsFile("234567", "reza", "hajhosseini");
	printInStudentsFile("345678", "peyman", "hosseini");
	Cell* head = createLinkListOfStudentsFile();
	cout << head->stuData.stuNum << endl << head->stuData.avg << endl << head->stuData.unitsSum << endl;
}