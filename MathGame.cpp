#include <iostream>
#include<string.h>
#include<string>
#include<Windows.h>
#include"Dependences.h"
using namespace std;
int RightAnswers = 0;
int WrongAnswers = 0;
int Levels[3]{ 10,100,1000 };
char Operations[4]{ '+','-','*','/' };
int currentLevel;
char currentOperation;
int tempLevel, tempOperation, numberOfquestion;
enum QuestionLevel {
	Easy = 1,
	Med = 2,
	Hard = 3,
	Mix = 4,
};
enum OperationTypes {
	Add = 1,
	Sub = 2,
	Mul = 3,
	Div = 4,
	mix = 5,
};
int TakeQuestionLevel();
int TakeOperationType();
int GenerateRandomLevel();
int GenerateRandomOperation();
bool CheckQuestion(int, int, int, char);
void ShowQuestion(int, int, char);
void ShowFinalResults(int, int);
int generateNumber(int);
int generateIndex(int);
void setLevel(int);
void setOperation(int);
void welcomeScreen();
int rightAnswer(int, int, char);
bool programIterations();
string finalResultsLevel(int number);
string finalResultsOperation(int number);
void resetProgram();

//--------------------------------------Main starts
int main()
{
	srand(unsigned(time(NULL)));
	do
	{
		welcomeScreen();
		int iterations;
		cout << "How many questions do you want ?" << endl;
		cin >> iterations;
		numberOfquestion = iterations;
		int level = TakeQuestionLevel();
		tempLevel = level;
		int operation = TakeOperationType();
		tempOperation = operation;
		while (iterations--)
		{
			int numberOne = 0;
			int numberTwo = 0;
			if (level == QuestionLevel::Mix)
			{
				setLevel(generateIndex(QuestionLevel::Mix));
				numberOne = generateNumber(currentLevel);
				numberTwo = generateNumber(currentLevel);
				if (operation == OperationTypes::mix)
				{
					setOperation(generateIndex(OperationTypes::Mul));
				}
				else
				{
					setOperation(operation);
				}
			}
			else
			{
				setOperation(operation);
				setLevel(level);
				numberOne = generateNumber(currentLevel);
				numberTwo = generateNumber(currentLevel);
			}

			ShowQuestion(numberOne, numberTwo, currentOperation);
			int userAnser; cin >> userAnser;
			cout << endl;
			if (CheckQuestion(numberOne, numberTwo, userAnser, currentOperation))
			{
				RightAnswers++;
				cout << "\nRightAnswers:-)\n" << endl;
				system("Color 20");
			}
			else
			{
				WrongAnswers++;
				cout << "\nWrongAnswer:-(" << endl;
				system("Color 40");
				cout << "The right answer is : " << rightAnswer(numberOne, numberTwo, currentOperation) << "\n\n";
			}
		}
		cout << endl;
		ShowFinalResults(RightAnswers, WrongAnswers);
	} while (programIterations());
}
//---------------------------------------End main
bool programIterations()
{
	char state = 'n';
	do
	{
		cout << "\nDo you want play again ? [Y:y]or[N:n]" << endl;
		cin >> state;
		if (state == 'N' || state == 'n')
		{
			return false;
		}
	} while ((state != 'Y'));
	resetProgram();
	return true;
}
int TakeQuestionLevel()
{
	int level;
	do
	{
		cout << "Enter question level:" << endl
			<< '[' << '1' << ']' << "Easy " << '[' << '2' << ']' << "Med " << '[' << '3' << ']' << "Hard " << '[' << '4' << ']' << "Mix" << endl;
		cin >> level;
	} while (level < 1 || level > 4);
	return level;
}
int TakeOperationType()
{
	int operation;
	do
	{
		cout << "Enter question Type:" << endl
			<< '[' << '1' << ']' << "Add " << '[' << '2' << ']' << "Sub " << '[' << '3' << ']' << "Mul " << '[' << '4' << ']' << "Div " << '[' << '5' << ']' << "Mix" << endl;
		cin >> operation;
	} while (operation < 1 || operation > 5);
	return operation;
}
int GenerateRandomLevel()
{
	return rand() % 4 + 1;
}
int GenerateRandomOperation()
{
	return rand() % 5 + 1;
}
bool CheckQuestion(int numberOne, int numberTwo, int userAnswer, char operation)
{
	if (operation == '+')
	{
		return(numberOne + numberTwo == userAnswer);
	}
	else if (operation == '-')
	{
		return(numberOne - numberTwo == userAnswer);
	}
	else if (operation == '/')
	{
		return(numberOne / numberTwo == userAnswer);
	}
	else if (operation == '*')
	{
		return(numberOne * numberTwo == userAnswer);
	}
}
int generateNumber(int range)
{
	return rand() % range + 1;
}
int generateIndex(int range)
{
	return rand() % range;
}
void ShowQuestion(int numberOne, int numberTwo, char op)
{
	cout << numberOne << endl << numberTwo << "\t" << op << endl << "_________" << endl;
}
void setLevel(int level)
{
	switch (level)
	{
	case QuestionLevel::Easy:
		currentLevel = Levels[0];
		break;
	case QuestionLevel::Med:
		currentLevel = Levels[1];
		break;
	case QuestionLevel::Hard:
		currentLevel = Levels[2];
		break;
	case QuestionLevel::Mix:
		currentLevel = Levels[generateIndex(2)];
		break;
	default:
		break;
	}
}
void setOperation(int operation)
{
	switch (operation)
	{
	case OperationTypes::Add:
		currentOperation = Operations[0];
		break;
	case OperationTypes::Sub:
		currentOperation = Operations[1];
		break;
	case OperationTypes::Mul:
		currentOperation = Operations[2];
		break;
	case OperationTypes::Div:
		currentOperation = Operations[3];
		break;
	case OperationTypes::mix:
		currentOperation = Operations[generateIndex(4)];
		break;
	default:
		break;
	}
}
void welcomeScreen()
{
	cout << "\t\t>>===============================<<" << endl
		<< "\t\t\tWelcome to MissMath geme" << endl
		<< "\t\t>>===============================<<" << endl;
}
void ShowFinalResults(int rightAnswers, int wrongAnswers)
{
	string Final = " ";
	if (rightAnswers >= wrongAnswers)
	{
		Final = " Pass:-)";
	}
	else
	{
		Final = " Fail:-(";
	}

	cout << "\n\n\n\t\t=============================================="
		<< "\n\t\t\tFinal result" << Final
		<< "\n\t\t==============================================" << endl
		<< "\nNumber of questions " << numberOfquestion
		<< "\nRightAnswers = " << RightAnswers
		<< "\nWrongAnswers = " << WrongAnswers
		<< "\nQuestionLevel : " << finalResultsLevel(tempLevel)
		<< "\nOperationType : " << finalResultsOperation(tempOperation);
}
string finalResultsLevel(int number)
{
	switch (number)
	{
	case 1:
		return"Easy";
	case 2:
		return"Med";
	case 3:
		return"Hard";
	case 4:
		return"Mix";
	default:
		break;
	}
}
string finalResultsOperation(int number)
{
	switch (number)
	{
	case 1:
		return"Add";
	case 2:
		return"Sub";
	case 3:
		return"Mul";
	case 4:
		return"Div";
	case 5:
		return"Mix";
	default:
		break;
	}
}
int rightAnswer(int numberOne, int numberTwo, char op)
{
	switch (op)
	{
	case '+':
		return numberOne + numberTwo;
		break;
	case '/':
		return numberOne / numberTwo;
		break;
	case '*':
		return numberOne * numberTwo;
		break;
	case '-':
		return numberOne - numberTwo;
		break;
	default:
		break;
	}
}
void resetProgram()
{
	system("cls");
	system("Color 04");
	RightAnswers = WrongAnswers = 0;
}
