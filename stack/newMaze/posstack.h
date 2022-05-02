#ifndef _POSITION_STACK_
#define _POSITION_STACK_
# include <stdio.h>
# include <stdlib.h>
#define HEIGHT 4
#define WIDTH 4
#define NUM_DIRECTIONS 4
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1}, //북
	{1, 0}, //동
	{0, 1}, //남
	{-1, 0}	//서
};
enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2, BLOCKED = 3 };

typedef struct MapPositionType
{
	int x;
	int y;
	int direction;
	struct MapPositionType *pLink;
} MapPosition;

typedef struct LinkedStackType
{
	int currentElementCount;
	MapPosition* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, MapPosition element);
MapPosition* popLS(LinkedStack* pStack);
MapPosition* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void showPath(LinkedStack *pStack);
int	findPath(int maze[HEIGHT][WIDTH], MapPosition start, MapPosition end, LinkedStack *LS);


#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
