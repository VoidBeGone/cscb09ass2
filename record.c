#include <stdio.h>
#include <string.h>
#include "record.h"

void set_sunspots(FILE *f, const char *name, unsigned short sunspots)
{  if (f==NULL) return;
   record *r;
   int x = fseek(f, 0, SEEK_SET);
   if (x != 0) return ;

   while (fread(r, sizeof(record), 1, f) == 1){
     int size = (int) r->name_len;
     char names[size];
     strcpy(names, r->name);
     if (strcmp(names,name) == 0){
       r->sunspots = sunspots;
       return;
     }
   }
   x = fseek(f,0,SEEK_END)
   if (x != 0) return;
   strcpy(r->name,name);
   r->sunspots = sunspots;
   r->name_len = strlen(name);
   fread(r, sizeof(record), 1, f);
   return;
}

int get_sunspots(FILE *f, const char *name, unsigned short *psunspots)
{
  if (f == NULL) return 0;
  record *r;
  if (fseek(f, 0, SEEK_SET) != 0) return 0;

  while (fread(r, sizeof(record), 1, f) == 1){
    int size = (int) -> r->name_len;
    char names[size];
    strcpy(names, r->name);
    if (strcmp(names, name) == 0 ){
      *psunspots = r->sunspots;
      return 1;
    }
  }
  return 0;
}
