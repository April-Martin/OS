#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void ExitWithMessage (const char* message)
{
  printf("%s", message);
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
  FILE* file;
  void* ret;
  file = fopen("/dev/sleepy0", "r+");
  if (file == NULL)
    {
      ExitWithMessage("Couldn't open file.\n");
    } 
  
  fread(ret, 1, 4, file);
  
  int* sleepTime = malloc(sizeof(int));
  *sleepTime = 4;
  int retval = fwrite(sleepTime, sizeof(int), 1,  file);
  printf("Trying to write %d\n", *sleepTime);
  printf("Wrote %d bytes\n", retval);

  fclose(file);

  return 0;
}
