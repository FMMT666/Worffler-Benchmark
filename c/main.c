#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <assert.h>



int main( int argc, char **argv )
{
  FILE *fin1;
  FILE *fin2;

  char line[1024] = {0};

  if( argc < 3 )
    return -1;

  fin1 = fopen( argv[1], "r+t" );
  fin2 = fopen( argv[2], "r+t" );

  if( ( fin1 == NULL ) || (fin2 == NULL) )
    return -1;

  struct stat st;
  stat(argv[1], &st);
  size_t finSize1 =  st.st_size;
  stat(argv[2], &st);
  size_t finSize2 =  st.st_size;

  int fileNum1 = fileno(fin1);
  int fileNum2 = fileno(fin2);
  char* mmappedData1 = mmap(NULL, finSize1, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fileNum1, 0);
  assert(mmappedData1 != NULL);
  char* mmappedData2 = mmap(NULL, finSize2, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fileNum2, 0);
  assert(mmappedData2 != NULL);


  char * startOne = mmappedData1;
  char * endOne = strchr(mmappedData1,'\n');
  while (endOne!=NULL)
  {
    int lengthOne = endOne-startOne;
    memcpy(line, startOne, lengthOne);
    char * startTwo = mmappedData2;
    char * endTwo = strchr(mmappedData2,'\n');
    while (endTwo!=NULL)
    {
      int length2 = endTwo-startTwo+1;
      memcpy(line + lengthOne, startTwo, length2);
      line[lengthOne + length2 + 1] = 0;
      fprintf(stdout, "%s", line);
      startTwo = endTwo+1;
      endTwo=strchr(endTwo+1,'\n');
    }
    startOne = endOne+1;
    endOne=strchr(endOne+1,'\n');
  }

  int rc = munmap(mmappedData1, finSize1);
  assert(rc == 0);
  rc = munmap(mmappedData2, finSize2);
  assert(rc == 0);

  fclose( fin1 );
  fclose( fin2 );

  exit(0);
}
