#ifndef TRANSPORT_H
#define TRANSPORT_H

#define MAX 50
#define NAME_LEN 30
#define PLATE_LEN 15
#define MONTH

typedef struct {
    char plateNumber[PLATE_LEN];
    char routeName[NAME_LEN];
    char driverName[NAME_LEN];
    int  capacity;
    float fare;
} Bus;

/* Shared data — defined once in main.c, used everywhere else */
extern Bus fleet[MAX];
extern int busCount;
extern float revenue[MAX][MONTHS];

/* ---- Part A: array_ops.c ---- */
void addBuses(void);
void displayFleet(void);
void traverseFleet(void);
void fareStatistics(void);
void insertBus(int pos, Bus newBus);
void deleteBus(int pos);
int  linearSearchByPlate(const char *target);
int  binarySearchByFare(float target);
void updateBus(int pos);
void findDuplicateFares(void);
void reverseFleet(void);

/* ---- Part B: matrix_ops.c ---- */
void inputRevenueMatrix(void);
void displayRevenueMatrix(void);
void busRevenueStats(void);
void addRevenueMatrices(float a[MAX][MONTHS], float b[MAX][MONTHS], float result[MAX][MONTHS]);
void transposeMatrix(void);

/* ---- Part C: string_ops.c ---- */
void analyseRouteString(const char *route);
void compareStrings(const char *s1, const char *s2);
void concatenateNames(const char *first, const char *last, char *result);
void extractSubstring(const char *str, int start, int len, char *result);
void patternMatch(const char *text, const char *pattern);
int  isPalindrome(const char *str);
void reverseString(char *str);
void wordFrequency(const char *text);

#endif