#include <stdio.h>
#include <string.h>
#include "record.h"

void set_sunspots(FILE *f, const char *name, unsigned short sunspots){
  if (f==NULL || fseek(f,0,SEEK_SET) != 0) return;
  record r;
  while (fread(&r, sizeof(record), 1, f) == 1){
    if (strlen(name) == r.name_len && strncmp(name, r.name, strlen(name)) == 0){
      r.sunspots = sunspots;
      fseek(f, -(sizeof(record)), SEEK_CUR);
      fwrite(&r, sizeof(record), 1, f);
      return;
    }
  }
  if (fseek(f, 0, SEEK_END) != 0) return;
  size_t size = strlen(name);
  if (size > NAME_LEN_MAX) size = NAME_LEN_MAX;
  memcpy(r.name, name, size); 
  r.name_len = size;
  r.sunspots = sunspots;
  fwrite(&r, sizeof(record), 1, f);
  return;
}

int get_sunspots(FILE *f, const char *name, unsigned short *psunspots)
{
  if (f == NULL || fseek(f, 0, SEEK_SET) != 0) return 0;
  record r;

  while (fread(&r, sizeof(record), 1, f) == 1){
    if (strlen(name) == r.name_len && strncmp(name, r.name, strlen(name)) == 0 ){
      *psunspots = r.sunspots;
      return 1;
    }
  }
  return 0;
}
