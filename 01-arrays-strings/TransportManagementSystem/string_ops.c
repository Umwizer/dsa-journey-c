#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "transport.h"

// 15. Count the types of characters
void analyseRouteString(const char *route) {
    int letters = 0, digits = 0, spaces = 0;
    int vowels = 0, consonants = 0, special = 0;

    for (int i = 0; route[i] != '\0'; i++) {
        char c = tolower(route[i]);

        if (isalpha(c)) {
            letters++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(c)) {
            digits++;
        } else if (c == ' ') {
            spaces++;
        } else {
            special++;
        }
    }

    printf("\nAnalysis of \"%s\"\n", route);
    printf("Length      : %d\n", (int)strlen(route));
    printf("Letters     : %d\n", letters);
    printf("Vowels      : %d\n", vowels);
    printf("Consonants  : %d\n", consonants);
    printf("Digits      : %d\n", digits);
    printf("Spaces      : %d\n", spaces);
    printf("Special     : %d\n", special);
}

// 16. Compare two strings
void compareStrings(const char *s1, const char *s2) {
    int result = strcmp(s1, s2);

    printf("\nComparing \"%s\" and \"%s\"\n", s1, s2);

    if (result == 0) {
        printf("They are identical.\n");
    } else if (result < 0) {
        printf("\"%s\" comes before \"%s\".\n", s1, s2);
    } else {
        printf("\"%s\" comes before \"%s\".\n", s2, s1);
    }

    if (strlen(s1) != strlen(s2)) {
        printf("They have different lengths (%d and %d).\n",
               (int)strlen(s1), (int)strlen(s2));
    }
}

// 17. Join first name and last name
void concatenateNames(const char *first, const char *last, char *result) {
    strcpy(result, first);
    strcat(result, " ");
    strcat(result, last);

    printf("\nBefore: \"%s\" and \"%s\"\n", first, last);
    printf("After : \"%s\"\n", result);
}

// 18. Take part of a string
void extractSubstring(const char *str, int start, int len, char *result) {
    int total = strlen(str);

    if (start < 0 || start >= total) {
        printf("Invalid start position.\n");
        result[0] = '\0';
        return;
    }

    // do not go past the end of the string
    if (start + len > total) {
        len = total - start;
    }

    for (int i = 0; i < len; i++) {
        result[i] = str[start + i];
    }
    result[len] = '\0';

    printf("\nText     : \"%s\"\n", str);
    printf("Start    : %d, length: %d\n", start, len);
    printf("Substring: \"%s\"\n", result);
}

// 19. Find a word inside a sentence
void patternMatch(const char *text, const char *pattern) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);
    int count = 0;

    printf("\nSearching \"%s\" in \"%s\"\n", pattern, text);

    for (int i = 0; i <= textLen - patLen; i++) {
        int same = 1;
        for (int j = 0; j < patLen; j++) {
            if (text[i + j] != pattern[j]) {
                same = 0;
                break;
            }
        }
        if (same == 1) {
            printf("Found at position %d\n", i);
            count++;
        }
    }

    if (count == 0) {
        printf("Pattern not found.\n");
    } else {
        printf("Total: %d\n", count);
    }
}

// 20. Palindrome check (ignores spaces, punctuation and capital letters)
int isPalindrome(const char *str) {
    char clean[100];
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            clean[n] = tolower(str[i]);
            n++;
        }
    }
    clean[n] = '\0';

    int left = 0;
    int right = n - 1;
    while (left < right) {
        if (clean[left] != clean[right]) {
            printf("\"%s\" is NOT a palindrome.\n", str);
            return 0;
        }
        left++;
        right--;
    }

    printf("\"%s\" is a palindrome.\n", str);
    return 1;
}

// 21. Reverse a string
void reverseString(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    printf("\nOriginal: \"%s\"\n", str);

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    printf("Reversed: \"%s\"\n", str);
}

// 22. Count how many times each word appears
void wordFrequency(const char *text) {
    char words[50][30];
    int wordCount = 0;

    char word[30];
    int len = 0;   // length of the word we are building

    // split the text into words, letter by letter
    for (int i = 0; ; i++) {
        char c = text[i];

        if (isalnum(c)) {
            if (len < 29) {
                word[len] = tolower(c);
                len++;
            }
        } else {
            // a space, symbol or the end: the word is finished
            if (len > 0 && wordCount < 50) {
                word[len] = '\0';
                strcpy(words[wordCount], word);
                wordCount++;
            }
            len = 0;
            if (c == '\0') break;
        }
    }

    printf("\nWord frequency for \"%s\"\n", text);

    int counted[50] = {0};   // 1 means this word was already counted
    int maxCount = 0;
    char topWord[30] = "";

    for (int i = 0; i < wordCount; i++) {
        if (counted[i] == 1) continue;

        int count = 1;
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
                counted[j] = 1;
            }
        }

        printf("%-15s %d\n", words[i], count);

        if (count > maxCount) {
            maxCount = count;
            strcpy(topWord, words[i]);
        }
    }

    printf("Most frequent word: %s (%d times)\n", topWord, maxCount);
}