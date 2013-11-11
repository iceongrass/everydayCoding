/***************************************************************
*
* fishDay.c
*
****************************************************************
*
* Description:
*
* There is a fishman who stated fishing job from 2010.01.01. 
* He fishes every three days will have a two days reset to clear
* the net.
*
* This program can tell you if the man is fishing on the day 
* you give.
*
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_YEAR 2010

#ifndef END_YEAR
#define END_YEAR 9999
#endif

/* Count day number from the beginning of the start year to the 
	giving day */
int countDays(int nYear, int nMonth, int nDay) {
	int monthDays [12] = {
		0, 31, 59, 90,
		120, 151, 181, 212,
		243, 273, 304, 334
		};		/* Count how many days past in this year befor 
					the giving month */

	return (
		365*(nYear-START_YEAR) 
		+ monthDays[nMonth-1] 
		+ nDay
		+ (runDays(nYear) - runDays(START_YEAR)) 
		- 1		/* Remove the Jan 1st ,2010 */
		);
}

/* Count how many run year past from year 0 */
int runDays(int nYear) {
	return ( nYear/4 - nYear/100 + nYear/400) ; 
}

unsigned int fishDay(int nYear, int nMonth, int nDay) {

	int days;	/* Count how many days are there from the beginning
					of the start year to the giving day */
	int daysInMonth[12] = {
		29, 31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30, 31
		};		/* Day number in every month */
	
	/* Check the input nYear, nMonth and nDay */
	assert((START_YEAR <= nYear) && (END_YEAR >= nYear));
	assert((1 <= nMonth) && (12 >= nMonth));

	if (2 == nMonth) {
		if ((0 == nYear%400) 
			|| ((0 == nYear%4) && (0 != nYear%100))) {
			assert((1 <= nDay) && (daysInMonth[0] >= nDay));
		}
	} else 
		assert((1 <= nDay) && (daysInMonth[nMonth] >= nDay));

	/* Check if the day is a fishing day */
	days = countDays(nYear, nMonth, nDay);

	if((days % 5) <= 2)
		return 1;	/* It's a fishing day */
	else
		return 0;	/* It's a break day */
}

int main() {

	if (fishDay(2010,1,5))
		printf("2010,1,5 is a fishing day.\n");
	else
		printf("2012,1,5 is not a fishing day.\n");
	
	if (fishDay(2012,1,6))
		printf("2012,1,6 is a fishing day.\n");
	else
		printf("2012,1,6 is not a fishing day.\n");
	
	if (fishDay(2013,1,5))
		printf("2013,1,5 is a fishing day.\n");
	else
		printf("2013,1,5 is not a fishing day.\n");

	return 0;
}
