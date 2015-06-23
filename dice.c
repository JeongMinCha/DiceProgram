/**************************************************************
 * Dice program                                               *
 * Problem: print all cases that the sum of 'n' dices is 'm'. *
 * Input: n(# of dices), m(goal of sum)                       *
 * Output: prints all answer cases.                           *
 *                                                            *
 * Author: JeongMin Cha, an student in Hanyang University.    *
 * contact: cjm9236@me.com                                    *
 * Last update date: June 23, 2015.                           *
 **************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MIN_SUM	0

/** function prototypes **/
void roll_dice(int, int);
void print_dice(int);

/** global variables **/
int num_dice = 0;	// # of dices
int goal = 0;		// goal of sum of dices
int count = 0;		// count # of printing results
int data = 0;		// used for printing results

/** main function **/
int main(int argc, char *argv[])
{
	num_dice = atoi(argv[1]);
	goal = atoi(argv[2]);

	/* checking input arguments... */
	if (num_dice <= 0)
	{
		printf("The arguments should be integers.\n");
		exit(-1);
	}
	else if(goal > 6*num_dice || goal < num_dice)
	{
		printf("The arguments are inappropriate integers.\n");
		exit(-1);
	}

	/* roll the dices! */
	roll_dice(num_dice, MIN_SUM);
	return 0;
}

/* roll the dices. */
void roll_dice(int n, int m)
{
	int i;
	int _m;
	int _n;

	for (int i=1; i<=6; ++i)
	{
		_n = n;
		_n--;
		_m = m;
		_m += i;
		data += i* (int)pow(10,_n);

		if (_n == 0)
		{
			if (_m > goal)
				return;
			else if(_m == goal)
			{
				printf("(");
				print_dice(data);
				printf(")\n");

				data /= (int)pow(10,n);
				data *= (int)pow(10,n);

				return;
			}
		}
		else
		{
			if (_m > goal)
			{
				data /= (int)pow(10,n);
				data *= (int)pow(10,n);
				return;
			}
			else
			{
				roll_dice(_n, _m);
			}
		}
		data /= (int)pow(10,n);
		data *= (int)pow(10,n);
	}
	return;
}

/* prints values of each dice. 
 * e.g) data=135 => prints ( 1 3 5 ) 
 *  It means the values of dices are 1, 3, and 5. */
void print_dice(int data)
{
	int i = 0;
	int digit = 0;
	int temp = 0;
	int _data = data;

	while (_data)
	{
		digit++;
		_data/=10;
	}
	_data = data;
	for(i=1; i<=digit; ++i)
	{
		temp = _data/10;
		temp *= 10;
		printf(" %d ", _data - temp);
		_data /= 10;
	}
}
