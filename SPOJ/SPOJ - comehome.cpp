/* This program blinks the red LED on the
* TI Tiva LaunchPad. The connections are:
* PF1 - red LED
* PF2 - blue LED
* PF3 - green LED
* They are high active (a '1' turns on the LED).
*/

#include "TM4C123GH6PM.h"
void delayMs(int n);
#define zero 0x3f
#define one 0x06
#define two 0x5b
#define three 0x2f
#define four 0x66
#define five 0x6d
#define six 0x7c
#define seven 0x47
#define eight 0x7f
#define nine 0x67

int myNumbers[10] = { zero,one,two,three,four,five,six,seven,eight,nine };
int paused = 0;
int second_counter = 0;
unsigned long segment1, segment2, segment3, segment4;

void splitNumber(int keyPadInput)
{
	segment4 = keyPadInput % 10;
	keyPadInput /= 10;

	segment3 = keyPadInput % 10;
	keyPadInput /= 10;

	segment2 = keyPadInput % 10;
	keyPadInput /= 10;

	segment1 = keyPadInput % 10;  // leftmost on the display
	keyPadInput /= 10;
}

// Port A is for the selector
void confPortA(void)
{
	GPIOA->DIR = 0xff;
	GPIOA->CR = 0xff;
	GPIOA->DEN = 0xff;
}
// Port B is for the seven segment
void confPortB(void)
{
	GPIOB->DIR = 0xff;
	GPIOB->CR = 0xff;
	GPIOB->DEN = 0xff;
}
// Port D is for the keypad
void confPortE(void)
{
	GPIOE->DIR = 0x00;
	GPIOE->CR = 0xff;
	GPIOE->DEN = 0xff;
}

void delayMs(int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3180; j++)
		{
		} // do nothing for 1 ms
		if (!paused)
			++second_counter;
	}
}

// Display the segment
void display7Segment(int segmentSelector, int num)
{
	GPIOB->DATA = 0x00;
	GPIOA->DATA = segmentSelector << 2;
	GPIOB->DATA = myNumbers[num];
	delayMs(5);
}
int initKeypad()
{
	GPIOA->DATA = 0x3c;
	return (GPIOE->DATA & 0x0F) != 0x0);
}
int readKeyPad(int *row, int *col)
{
	int mask = 0xf;
	//row 4
	GPIOA->DATA = 0x20;
	//check which fucking col
	if (((GPIOE->DATA & 0x0F) == 0x04))
	{
		*col = (GPIOE->DATA & 0x0F);
		return 0;
	}
	else if (((GPIOE->DATA & 0x0F) == 0x01))
	{
		*col = (GPIOE->DATA & 0x0F);
		return 0;
	}
	return -1;
}

int main()
{
	SYSCTL->RCGCGPIO |= 0xff;
	while ((SYSCTL->PRGPIO & 0xff) == 0);
	confPortA();
	confPortB();
	confPortE();
	int flag = 1;
	int counter = 0;
	while (1)
	{
		int row, col;
		int ret = readKeyPad(&row, &col);
		if (ret != -1)
		{
			if (col == 1) //star
				paused = (paused) ? 0:1; //should flip paused
			if (col == 4) //hashtag
			{
				paused = 1;
				counter = 0;
			}
		}
		if (second_counter >= 1000)
		{
			++counter;
			second_counter = 0;
		}
		splitNumber(counter);
		display7Segment(1, segment4);
		display7Segment(2, segment3);
		display7Segment(4, segment2);
		display7Segment(8, segment1);
		delayMs(1);
	}
	while (1)
	{
		int status = initKeypad();
		if (status) // key pressed
		{
			display7Segment(1, 2);
			display7Segment(2, 0);
			display7Segment(4, 1);
			display7Segment(8, 9);
		}
		else
		{
			GPIOA->DATA = 0x3c;
			GPIOB->DATA = zero;

			//			display7Segment(1, 0);
			//			display7Segment(2, 0);
			//			display7Segment(4, 0);
			//			display7Segment(8, 0);
		}
		delayMs(1);
	}
}
