#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "transport.h"

/* ---------- 15. String Traversal and Analysis ---------- */
void analyseRouteString(const char *route) {
    int length = 0, letters = 0, digits = 0, spaces = 0;
    int vowels = 0, consonants = 0, special = 0;

    for (int i = 0; route[i] != '\0'; i++) {
        length++;
        char c = route[i];

        if (isalpha((unsigned char)c)) {
            letters++;
            char lower = tolower((unsigned char)c);
            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit((unsigned char)c)) {
            digits++;
        } else if (isspace((unsigned char)c)) {
            spaces++;
        } else {
            special++;
        }
    }

    printf("\nAnalysis of \"%s\":\n", route);
    printf("Total characters : %d\n", length);
    printf("Letters          : %d\n", letters);
    printf("Digits           : %d\n", digits);
    printf("Spaces           : %d\n", spaces);
    printf("Vowels           : %d\n", vowels);
    printf("Consonants       : %d\n", consonants);
    printf("Special characters: %d\n", special);
}

/* ---------- 16. String Comparison ---------- */
void compareStrings(const char *s1, const char *s2) {
    int result = strcmp(s1, s2);

    printf("\nComparing \"%s\" and \"%s\":\n", s1, s2);
    if (result == 0) {
        printf("The strings are identical.\n");
    } else if (result < 0) {
        printf("\"%s\" comes before \"%s\" (ascending order).\n", s1, s2);
    } else {
        printf("\"%s\" comes before \"%s\" (ascending order).\n", s2, s1);
    }

    if (strlen(s1) != strlen(s2)) {
        printf("The strings also differ in length (%zu vs %zu).\n", strlen(s1), strlen(s2));
    }
}

/* ---------- 17. String Concatenation ---------- */
void concatenateNames(const char *first, const char *last, char *result) {
    strcpy(result, first);
    strcat(result, " ");
    strcat(result, last);
    printf("\nBefore: \"%s\" + \"%s\"\n", first, last);
    printf("After : \"%s\"\n", result);
}

/* ---------- 18. Substring Extraction ---------- */
void extractSubstring(const char *str, int start, int len, char *result) {
    int strLen = strlen(str);

    if (start < 0 || start >= strLen) {
        printf("Invalid starting position.\n");
        result[0] = '\0';
        return;
    }
    if (start + len > strLen) {
        len = strLen - start;  
    }

    strncpy(result, str + start, len);
    result[len] = '\0';

    printf("\nFrom \"%s\", starting at %d, length %d:\n", str, start, len);
    printf("Substring: \"%s\"\n", result);
}

/* ---------- 19. Pattern Matching ---------- */
void patternMatch(const char *text, const char *pattern) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);
    int found = 0;

    printf("\nSearching for \"%s\" in \"%s\":\n", pattern, text);

    for (int i = 0; i <= textLen - patLen; i++) {
        int match = 1;
        for (int j = 0; j < patLen; j++) {
            if (text[i + j] != pattern[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("Found at position %d\n", i);
            found++;
        }
    }

    if (found == 0) {
        printf("Pattern not found.\n");
    } else {
        printf("Total occurrences: %d\n", found);
    }
}

/* ---------- 20. Palindrome Detection ---------- */
int isPalindrome(const char *str) {
    char cleaned[100];
    int k = 0;

    /* Keep only letters, lowercase them, ignore spaces/punctuation */
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            cleaned[k++] = tolower((unsigned char)str[i]);
        }
    }
    cleaned[k] = '\0';

    int left = 0, right = k - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            printf("\"%s\" is NOT a palindrome.\n", str);
            return 0;
        }
        left++;
        right--;
    }
    printf("\"%s\" IS a palindrome.\n", str);
    return 1;
}

/* ---------- 21. String Reversal ---------- */
void reverseString(char *str) {
    int len = strlen(str);
    int left = 0, right = len - 1;

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

/* ---------- 22. Word Frequency ---------- */
void wordFrequency(const char *text) {
    char copy[200];
    strcpy(copy, text);

    char words[50][30];
    int wordCount = 0;

    char *token = strtok(copy, " \t\n");
    while (token != NULL && wordCount < 50) {
        /* lowercase + strip trailing punctuation */
        int len = strlen(token);
        char clean[30];
        int k = 0;
        for (int i = 0; i < len; i++) {
            if (isalnum((unsigned char)token[i])) {
                clean[k++] = tolower((unsigned char)token[i]);
            }
        }
        clean[k] = '\0';

        if (k > 0) {
            strcpy(words[wordCount], clean);
            wordCount++;
        }
        token = strtok(NULL, " \t\n");
    }

    printf("\nWord frequency for: \"%s\"\n", text);

    int counted[50] = {0};
    char mostFrequentWord[30] = "";
    int maxFreq = 0;

    for (int i = 0; i < wordCount; i++) {
        if (counted[i]) continue;
        int freq = 1;
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq++;
                counted[j] = 1;
            }
        }
        printf("%-15s : %d\n", words[i], freq);
        if (freq > maxFreq) {
            maxFreq = freq;
            strcpy(mostFrequentWord, words[i]);
        }
    }

    printf("Most frequent word: \"%s\" (%d times)\n", mostFrequentWord, maxFreq);
}