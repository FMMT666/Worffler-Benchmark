#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char **argv )
{
  FILE *fin1;
  FILE *fin2;
  
  char line1[1024];
  char line2[1024];

  if( argc < 3 )
    return -1;

  fin1 = fopen( argv[1], "r+t" );
  fin2 = fopen( argv[2], "r+t" );

  if( ( fin1 == NULL ) || (fin2 == NULL) )
    return -1;

  while( !feof(fin1) )
  {
    if( !fgets( line1, sizeof(line1), fin1 ) )
      break;
      
    strtok( line1, "\n");

    while( !feof(fin2) )
    {
      if( !fgets( line2, sizeof(line2), fin2 ) )
        break;
      strtok( line2, "\n");
    
      fprintf( stdout, "%s%s\n", line1, line2 );
    }
    
    rewind( fin2 );
  }
  
  
  fclose( fin1 );
  fclose( fin2 );

  exit(0);  
}
