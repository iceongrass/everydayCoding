#include <string.h>

#define TRUE        0
#define FALSE       1
#define OK          0
#define ERROR       1
#define INFEASIBLE  -1
#define OVERFLOW    -2

// Status: Function type
typedef int Status;

#ifdef ELEM_INT
typedef int TElemType;
#endif 

#ifdef ELEM_CHAR
typedef char TElemType;
#endif 

#ifdef ELEM_STR
typedef string TElemType;
#endif 