// no need to modify this file, keep it in the same folder
// as your source files

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
unsigned int pows(unsigned int num, unsigned int powss);
int strlens(const char *str);

bool isPrime(unsigned int n);
int convert(const char c);
void sort_three(int a, int b, int c, int *list);
long int unique_sums(const int *A, unsigned int n, unsigned int k);
bool circular_prime(unsigned int n);
unsigned long int any2dec(const char *num, unsigned int b);
void hex2rgb(const char *hex, char *rgb);
unsigned int str_search(const char *pattern, const char *text);
bool same_gmail(const char *g1, const char *g2);
void to_hostname(char *address);
#endif
