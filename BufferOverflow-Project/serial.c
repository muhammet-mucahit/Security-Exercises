#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valid_serial( char *psz )
{
   size_t len = strlen( psz );
   unsigned total = 0;
   size_t i;

   if( len < 10 )
      return 0;

   for( i = 0; i < len; i++ )
   {
      if(( psz[i] < '0' ) || ( psz[i] > 'z' ))
         return 0;

      total += psz[i];
   }

   if( total % 853 == 83 )
      return 1;

   return 0;
}

int validate_serial()
{
   char serial[ 24 ];

   fscanf( stdin, "%s", serial );

   if( valid_serial( serial ))
      return 1;
   else
      return 0;
}

int do_valid_stuff()
{
   printf("The serial number is valid!\n");
   // do serial-restricted, valid stuff here.
   exit( 0 );
}

int do_invalid_stuff()
{
   printf("Invalid serial number!\nExiting\n");
   exit( 1 );
}

int main( int argc, char *argv[] )
{
   // 0x00000000004007a7
   if( validate_serial() )
      // 0x00000000004007b5
      do_valid_stuff();
   else
      do_invalid_stuff();

   return 0;
}