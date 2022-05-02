#include "posstack.h"

int maze[HEIGHT][WIDTH] = {\
	{1, 1, 1, 1}, \
	{0, 0, 0, 1}, \
	{1, 1, 0, 1}, \
	{1, 0, 0, 0}};

void	printMaze(int maze[HEIGHT][WIDTH])
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
			printf("%d ", maze[i][j]);
		printf("\n");
	}
}

int	findPath(int maze[HEIGHT][WIDTH], MapPosition start, MapPosition end, LinkedStack *LS)
{
	MapPosition next;

	if (start.x < 0 || start.y < 0 || start.x >= HEIGHT || start.y >= WIDTH)
		return 0;
	else if (maze[start.x][start.y] != NOT_VISIT)
		return 0;
	else if (start.x == end.x && start.y == end.y)
	{
		maze[start.x][start.y] = VISIT;
		printf("This Way\n");
		return 1;
	}
	else 
	{
		maze[start.x][start.y] = VISIT;
		for (int i =  0; i < NUM_DIRECTIONS; i++)
		{
			int next_x = start.x + DIRECTION_OFFSETS[i][0];
			int next_y = start.y + DIRECTION_OFFSETS[i][1];

			next.x = next_x;
			next.y = next_y;
			pushLS(LS, next);
			if (findPath(maze, next, end, LS))
				return 1;
			free(popLS(LS));
		}
	}
	maze[start.x][start.y] = BLOCKED;
	return 0;
}

void showPath(LinkedStack *pStack)
{
	int max;
	LinkedStack *cpR = createLinkedStack();

	while (pStack->currentElementCount != 0)
		pushLS(cpR, *popLS(pStack));
	max = cpR->currentElementCount;
	for (int i = 0; i < max; i++)
	{
		printf("(%d, %d) -> ", cpR->pTopElement->x, cpR->pTopElement->y);
		free(popLS(cpR));
		// printf("(%d, %d) -> ", curr->x, curr->y);
		// curr = curr->pLink;
	}
	printf("exit\n");
	deleteLinkedStack(cpR);
}

int	main(void)
{
	LinkedStack *LS;
	MapPosition start;
	MapPosition end;

	LS = createLinkedStack();
	start.x = 1;
	start.y = 0;
	pushLS(LS, start);

	end.x = 3;
	end.y = 3;
	findPath(maze, start, end, LS);
	printMaze(maze);
	showPath(LS);
	deleteLinkedStack(LS);
	return 0;
}
