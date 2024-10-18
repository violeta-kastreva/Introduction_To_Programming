#include <iostream>


const int MIN_DAY = 1;

const int MIN_MONTH = 1;
const int MAX_MONTH = 12;

const int MIN_YEAR = 0;

// Months
const int JANUARY = 1;
const int FEBRUARY = 2;
const int MARCH = 3;
const int APRIL = 4;
const int MAY = 5;
const int JUNE = 6;
const int JULY = 7;
const int AUGUST = 8;
const int SEPTEMBER = 9;
const int OCTOBER = 10;
const int NOVEMBER = 11;
const int DECEMBER = 12;

int main() {
    // Check if a given day, month, year is a valid date
    int day, month, year;
    std::cin >> day >> month >> year;

    if (year < MIN_YEAR) {
        std::cout << "Invalid year!";
        return 1;
    }

    if (month < MIN_MONTH || month > MAX_MONTH) {
        std::cout << "Invalid month!";
        return 1;
    }

    // This switch statement is an example of how hard it is
    // to read a switch without breaks on every case
    int maxDaysInMonth = 28;
    switch (month) {
    default:
        maxDaysInMonth += 1;
        // Notice here we don't have a break !!!!!!!!!!
        // That is called "fallthrough"
    case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
        maxDaysInMonth += 2;
        break;
    case FEBRUARY:
        // Implicit conversion from bool to int
        maxDaysInMonth += (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }

    if (day < MIN_DAY || day > maxDaysInMonth) {
        std::cout << "Invalid day!";
        return 1;
    }

    // Pretty printing
    std::cout << day << ' ';
    switch (month) {
    case JANUARY:
        std::cout << "January";
        break;
    case FEBRUARY:
        std::cout << "February";
        break;
    case MARCH:
        std::cout << "March";
        break;
    case APRIL:
        std::cout << "April";
        break;
    case MAY:
        std::cout << "May";
        break;
    case JUNE:
        std::cout << "June";
        break;
    case JULY:
        std::cout << "July";
        break;
    case AUGUST:
        std::cout << "August";
        break;
    case SEPTEMBER:
        std::cout << "September";
        break;
    case OCTOBER:
        std::cout << "October";
        break;
    case NOVEMBER:
        std::cout << "November";
        break;
    case DECEMBER:
        std::cout << "December";
        break;
    default:
        std::cout << "Error. Should be unreachable!";
        return 1;
    }
    std::cout << ", " << year << " is a valid date\n";

    return 0;
}