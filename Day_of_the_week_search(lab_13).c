#include <stdio.h>
#include <math.h>

typedef struct
{
    int day;
    int month;
    int year;
    int numOfDayInWeek;
} dates;

// place for a function
dates setDate(dates date, short flag)
{
    scanf("%i", &date.day);
    scanf("%i", &date.month);
    scanf("%i", &date.year);
    if (flag == 1)
        scanf("%i", &date.numOfDayInWeek); 
    return date;
}


int getDayCount(dates date, int* daysInMonth)   // counting days from 1 january  
{
    int count = date.day;
    if ((date.month > 2) && (((date.year % 4 == 0) && (date.year % 100 != 0)) || date.year % 400 == 0))
            count += 1;
    for (short i = 1; i < date.month; i++)
        count += daysInMonth[i-1];    

    return count;
}

void printDate(dates* date, char daysInWeek[7][10])
{
    printf("%i.%i.%i it is %s\n", date->day, date->month, date->year, daysInWeek[date->numOfDayInWeek % 7]);
}

int getDefDays(dates startDate, int startDateDayCount, dates endDate, int endDateDayCount)
{
    int count = 0;
    if ((startDate.month > 2) && (startDate.year != endDate.year))    // delete problem (without that condition count 366 days from 10.3.2020 to 10.3.2021 instead 365)
        count -= 1;
    for (short i = startDate.year; i < endDate.year; i++)
    {
        if ((((i % 4 == 0) && (i % 100 != 0)) || i % 400 == 0)) 
            count += 1;
        count += 365;
    }
    count = count - startDateDayCount + endDateDayCount + 1;
    printf("%i\n", count);
    return count;
}

// end of this place

void main()
{    
    char dayInWeek[][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    dates date_in;
    dates* p_date_in = &date_in;
    date_in.day = 1;
    date_in.month = 1;
    date_in.year = 2020;
    date_in.numOfDayInWeek = 3;
    printDate(p_date_in, dayInWeek);

    dates date_out = setDate(date_out, 0);
    dates* p_date_out = &date_out;

    int daysCount_in = getDayCount(date_in, daysInMonth);
    int daysCount_out = getDayCount(date_out, daysInMonth);
    printf("din = %i   dout = %i\n", daysCount_in, daysCount_out);

    int def_days;
    
    if (date_out.year >= date_in.year)
    {
        def_days = getDefDays(date_in, daysCount_in, date_out, daysCount_out);
        date_out.numOfDayInWeek = (def_days + date_in.numOfDayInWeek - 1) % 7;
    } 
    else 
    {
        def_days = getDefDays(date_out, daysCount_out, date_in, daysCount_in);
        date_out.numOfDayInWeek =  (def_days - date_in.numOfDayInWeek - 1) % 7;
        date_out.numOfDayInWeek = 6 - date_out.numOfDayInWeek;
    }

    printDate(p_date_out, dayInWeek);

    return;
}
/*
#include <stdio.h>
#include <math.h>

typedef struct
{
    int day;
    int month;
    int year;
    int numOfDayInWeek;
} dates;

// place for a function

int getDayCount(dates date, int* daysInMonth)   // counting days from 1 january  
{
    int count = date.day;
    if (date.month > 2 && (((date.year % 4 == 0) && (date.year % 100 != 0)) || date.year % 400 == 0))
            count += 1;
    for (short i = 1; i < date.month; i++)
    {
        count += daysInMonth[i];    
    }
    return count;
}

void printDate(dates* date, char daysInWeek[7][10])
{
    printf("%i.%i.%i it is %s\n", date->day, date->month, date->year, daysInWeek[date->numOfDayInWeek % 7]);
}

int getDefDays(dates startDate, int startDateDayCount, dates endDates, int endDateDayCount)
{
    int count = 0;
    if ((startDate.month > 2) && (startDate.year != endDates.year))    // delete problem (without that condition count 366 days from 10.3.2020 to 10.3.2021 instead 365)
        count -= 1;
    for (short i = startDate.year; i < endDates.year; i++)
    {
        if ((((i % 4 == 0) && (i % 100 != 0)) || i % 400 == 0)) 
            count += 1;
        count += 365;
    }
    count = count - startDateDayCount + endDateDayCount + 1;
    printf("%i\n", count);
    return count;
}

// end of this place

void main()
{    
    char dayInWeek[][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    dates date_in;
    dates* p_date_in = &date_in;
    scanf("%i", &date_in.day);
    scanf("%i", &date_in.month);
    scanf("%i", &date_in.year);
    scanf("%i", &date_in.numOfDayInWeek);
    printDate(p_date_in, dayInWeek);

    dates date_out;
    dates* p_date_out = &date_out;
    scanf("%i", &date_out.day);
    scanf("%i", &date_out.month);
    scanf("%i", &date_out.year);

    int daysCount_in = getDayCount(date_in, daysInMonth);
    int daysCount_out = getDayCount(date_out, daysInMonth);
    printf("din = %i   dout = %i\n", daysCount_in, daysCount_out);

    int def_days = getDefDays(date_in, daysCount_in, date_out, daysCount_out);
    date_out.numOfDayInWeek = (def_days + date_in.numOfDayInWeek - 1) % 7;
    printDate(p_date_out, dayInWeek);

    return;
}

*/