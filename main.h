#ifndef _MAIN_H_
#define _MAIN_H_

#ifndef _ENVIRON_
#define _ENVIRON_
extern char **environ;
#endif /* _ENVIRON_ */

#ifndef _STRLEN_
#define _STRLEN_
int _strlen(char *s);
#endif /* _STRLEN_ */

#ifndef __STRCMP_
#define  __STRCMP_
int _strcmp(char *s1, char *s2);
#endif /*  __STRCMP_ */

#ifndef _PUTCHAR_
#define _PUTCHAR_
int _putchar(char c);
#endif /* _PUTCHAR_ */

#ifndef __PRINTF_
#define __PRINTF_
int _printf(const char *format, ...);
#endif /* __PRINTF_ */

#ifndef _PRINT_S_
#define _PRINT_S_
int print_s(const char *, char *, int *);
#endif /* _PRINT_S_ */

#ifndef _PRINT_INT_
#define _PRINT_INT_
int print_int(int, char *, int *);
#endif /* _PRINT_INT_ */

#ifndef _PRINT_INTI_
#define _PRINT_INTI_
int print_inti(int, char *, int *);
#endif /* _PRINT_INTI_ */

#ifndef _INT_BIN_
#define _INT_BIN_
int int_bin(int, char *, int *);
#endif /* _INT_BIN_ */

#ifndef _PRINT_U_
#define _PRINT_U_
int print_u(unsigned int, char *, int *);
#endif /* _PRINT_U_ */

#ifndef _POW_
#define _POW_
int _pow(int, int);
#endif /* _POW_ */

#ifndef _PRINT_O_
#define _PRINT_O_
int print_o(unsigned int, char *, int *);
#endif /* _PRINT_O_ */

#ifndef _PRINT_X_
#define _PRINT_X_
int print_x(unsigned int, char *, int *);
#endif /* _PRINT_X_ */

#ifndef _PRINT_XX_
#define _PRINT_XX_
int print_xx(unsigned int, char *, int *);
#endif /* _PRINT_XX_ */

#ifndef _POST_
#define _POST_
int post(char *);
#endif /* _POST_ */

#ifndef _STRLEN_
#define _STRLEN_
int _strlen(char *s);
#endif /* _STRLEN */

#ifndef _STORE_CHAR_
#define _STORE_CHAR_
int store_char(char, char *, int *);
#endif /* _STORE_CHAR_ */

#ifndef __STRTOK_
#define __STRTOK_
char **_strtok(char *, char);
#endif /* __STRTOK_ */

#endif /* _MAIN_H_ */
