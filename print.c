#include <stdio.h>
#include "record.h"

int main(int argc, char **argv)
{
  if (argc < 2) {
    fprintf(stderr, "Need filename.\n");
    return 1;
  }
  FILE *f = fopen(argv[1], "rb");
  if (f == NULL) {
    perror("fopen");
    return 1;
  }
  // read-print loop
  //Okay so i am supposed to implement from here onwards
  record new_record;
  while (fread(&new_record, sizeof(record), 1, f) == 1){
    int name_len = (int) new_record.name_len;
    printf("%.*s has %d sunspots\n",name_len, new_record.name, new_record.sunspots );
  }
  fclose(f);
  return 0;
}
