#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>

#define SIZE 4

void PrintBoard(unsigned int board[4][4])
{
	int i;
	int j;
	system("cls");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d  ", board[i][j]);
		}
		printf("\n");
	}
}

void MoveUp(unsigned int board[4][4])
{
	int i;
	int j;
	int k;
	int tmp;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			tmp = board[i][j];
			if (tmp != 0)
			{
				k = 1;
				while (i + k <4)
				{
					if (board[i + k][j] != tmp && board[i + k][j] != 0)
					{
						break;
					}
					if (board[i + k][j] == tmp)
					{
						board[i][j] += board[i][j];
						board[i + k][j] = 0;
						break;
					}
					k++;
				}
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				k = 1;
				while (i + k < 4)
				{
					if (board[i + k][j] != 0)
					{
						board[i][j] = board[i + k][j];
						board[i + k][j] = 0;
						break;
					}
					k++;
				}
			}
		}
	}
}

void MoveDown(unsigned int board[4][4])
{
	int i;
	int j;
	int k;
	int tmp;

	for (i = 3; i >= 0; i--)
	{
		for (j = 3; j >= 0; j--)
		{
			tmp = board[i][j];
			if (tmp != 0)
			{
				k = 1;
				while (i - k >= 0)
				{
					if (board[i - k][j] != tmp && board[i - k][j] != 0)
					{
						break;
					}
					if (board[i - k][j] == tmp)
					{
						board[i][j] += board[i][j];
						board[i - k][j] = 0;
						break;
					}
					k++;
				}
			}
		}
	}

	for (i = 3; i >= 0; i--)
	{
		for (j = 3; j >= 0; j--)
		{
			if (board[i][j] == 0)
			{
				k = 1;
				while (i - k >= 0)
				{
					if (board[i - k][j] != 0)
					{
						board[i][j] = board[i - k][j];
						board[i - k][j] = 0;
						break;
					}
					k++;
				}
			}
		}
	}

}

void MoveLeft(unsigned int board[4][4])
{
	int i;
	int j;
	int k;
	int tmp;

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{
			if (board[i][j] != 0)
			{
				k = 1;
				while (j + k < 4)
				{
					tmp = board[i][j + k];
					if (tmp != board[i][j] && tmp != 0)
					{
						break;
					}
					if (tmp == board[i][j])
					{
						board[i][j] += tmp;
						board[i][j + k] = 0;
						break;
					}
					k++;
				}
			}
		}
	}

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{
			if (board[i][j] == 0)
			{
				k = 1;
				while (j + k < 4)
				{
					tmp = board[i][j + k];
					if (tmp != 0)
					{
						board[i][j] = tmp;
						board[i][j + k] = 0;
						break;
					}
					k++;
				}
			}
		}
	}
}

void MoveRight(unsigned int board[4][4])
{
	int i;
	int j;
	int k;
	int tmp;

	for (j = 3; j >= 0; j--)
	{
		for (i = 3; i >= 0; i--)
		{
			if (board[i][j] != 0)
			{
				k = 1;
				while (j - k >= 0)
				{
					tmp = board[i][j - k];
					if (tmp != board[i][j] && tmp != 0)
					{
						break;
					}
					if (tmp == board[i][j])
					{
						board[i][j] += tmp;
						board[i][j - k] = 0;
						break;
					}
					k++;
				}
			}
		}
	}

	for (j = 3; j >= 0; j--)
	{
		for (i = 3; i >= 0; i--)
		{
			if (board[i][j] == 0)
			{
				k = 1;
				while (j - k >= 0)
				{
					tmp = board[i][j - k];
					if (tmp != 0)
					{
						board[i][j] = tmp;
						board[i][j - k] = 0;
						break;
					}
					k++;
				}
			}
		}
	}
}

void ProductNumber(unsigned int board[4][4])
{
	int i;
	int j;
	int x;
	int y;
	int tmp;
	int flag;

	flag = 0;
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0)
	{
		return;
	}

	tmp = rand() % 2;

	while (true)
	{
		x = rand() % 4;
		y = rand() % 4;

		if (board[x][y] == 0)
		{
			if (tmp == 0)
			{
				board[x][y] = 2;
			}
			else
			{
				board[x][y] = 4;
			}
			break;
		}
	}
}

bool IsAlive(unsigned int board[4][4])
{
	int i;
	int j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				return true;
			}
			if (i - 1 > 0 && board[i - 1][j] == board[i][j])
			{
				return true;
			}
			if (i + 1 < 4 && board[i + 1][j] == board[i][j])
			{
				return true;
			}
			if (j - 1 > 0 && board[i][j - 1] == board[i][j])
			{
				return true;
			}
			if (j + 1 < 4 && board[i][j + 1] == board[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{

	unsigned int board[4][4] = { 0 };
	char ch;
	srand(time(NULL));

	ProductNumber(board);
	PrintBoard(board);

	while (IsAlive(board))
	{
		while (ch = getch())
		{
			if (ch == 'w')
			{
				MoveUp(board);
				break;
			}
			if (ch == 's')
			{
				MoveDown(board);
				break;
			}
			if (ch == 'a')
			{
				MoveLeft(board);
				break;
			}
			if (ch == 'd')
			{
				MoveRight(board);
				break;
			}
		}
		ProductNumber(board);
		PrintBoard(board);
	}


	return 0;
}