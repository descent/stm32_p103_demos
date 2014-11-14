#ifndef K_STDIO_H
#define K_STDIO_H

#include "type.h"
#include "gdeque.h"

#define ENTER '\r'

namespace DS
{

void myprint(const char *str);
void myprint(int num);
void myprint_float(float num);
void send_byte(u8 b);
int ungetch(int c);
int getchar();
int read_char();
char *gets(char *s, int size);
}

//extern MyDeque mydeque;
extern DS::Deque<int> mydeque;

#endif
