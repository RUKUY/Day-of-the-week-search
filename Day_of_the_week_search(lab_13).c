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
dates setDate(dates date)
{   
    printf("%s   ", "Enter day:");
    scanf("%i", &date.day);
    printf("%s ", "Enter month:");
    scanf("%i", &date.month);
    printf("%s  ", "Enter year:");
    scanf("%i", &date.year);
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
    count = count - startDateDayCount + endDateDayCount + 1;        // count def between two days including first day
    return count;
}

// end of this place

void main()
{    
    char dayInWeek[][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };    // array of days in week
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };     //array of month days

    dates date_in;                                                              // source date
    dates* p_date_in = &date_in;                                                // pointer date_in
    
    date_in.day = 1;                                                            // 1 january 2020 it's Wednesday
    date_in.month = 1;  
    date_in.year = 2020;
    date_in.numOfDayInWeek = 3;

    dates date_out = setDate(date_out);                                         // initialising input date
    dates* p_date_out = &date_out;

    int daysCount_in = getDayCount(date_in, daysInMonth);                       // count days from 1 1 january for each date
    int daysCount_out = getDayCount(date_out, daysInMonth); 

    int def_days;                                                               // var for days defenition

    if (date_out.year >= date_in.year)                                          // search future date
    {
        def_days = getDefDays(date_in, daysCount_in, date_out, daysCount_out);
        date_out.numOfDayInWeek = (def_days + date_in.numOfDayInWeek - 1) % 7;  // + num of day of the week to find day shift 
    } 
    else                                                                        // search past date
    {
        def_days = getDefDays(date_out, daysCount_out, date_in, daysCount_in);  // count days 
        date_out.numOfDayInWeek = (def_days - date_in.numOfDayInWeek - 1) % 7; // search defenition
        date_out.numOfDayInWeek = 6 - date_out.numOfDayInWeek;                  // invert day of the week
    }

    printDate(p_date_out, dayInWeek);
    return;
}
