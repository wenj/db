#include <cstring>
#define MAXCHAR		5000

// ¸´ÖÆ´®
static char *copy_string(char *s, int len)
{
   char *copy = new char[len + 1];
   strncpy(copy, s, len);
   copy[len] = '\0';
   return copy;
}
