#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // For cat, we have to iterate over all command-line arguments of
  // our proce;
  char buffer[4096];

  if (argc < 2) {
    fprintf(stderr, "%s", argv[0]);
    return 1;
  }

  for (int idx = 1; idx < argc; idx++) {
    FILE *file = fopen(argv[idx], "r");
    if (file == NULL) {
      perror("error");
      continue;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      fputs(buffer, stdout);
    }
    fclose(file);
  }

  return 0;
}
