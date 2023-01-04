#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define handle_error(msg) \
   do { perror(msg); exit(EXIT_FAILURE); } while (0)

int
main(int argc, char *argv[])
{
   FILE *out, *in;
   int v, s;
   size_t size;
   char *ptr, ptr_in[15];

   if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    exit(EXIT_FAILURE);
   }

   in = fmemopen(ptr_in, strlen(argv[1]), "w+");
   if (in == NULL)
       handle_error("fmemopen");

   fputs("1 2 3 4",in);
   out = open_memstream(&ptr, &size);
   if (out == NULL)
       handle_error("open_memstream");

   for (;;) {
       s = fscanf(in, "%d", &v);
       if (s <= 0)
           break;

       s = fprintf(out, "%d ", v);
       if (s == -1)
           handle_error("fprintf");
   }
   fclose(in);
   fclose(out);
   printf("size=%ld; ptr=%s\n", (long) size, ptr);
   free(ptr);
   exit(EXIT_SUCCESS);
}

