#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_lines.h"

char *GetLine(FILE *fp) {
  /*
  GetLine takes a file and gets the line next in the file and returns it as a
  char* array.
  @fp: the file to get the line from
  @returns a char* array that holds the string of the line
*/
  char c;
  int i = 0;
  int size = 0;
  char *thisLine = (char *)malloc(sizeof(char));
  int check;
  do {
    check = fscanf(fp, "%c", &c);
    if ((c == '\n') & (size == 0)) {
      return NULL;
    }
    if (c == '\n')
      break;
    size += 1;
    thisLine = realloc(thisLine, size);
    thisLine[i] = c;

    i++;

  } while (check > 0);
  thisLine = realloc(thisLine, size + 2);
  thisLine[size] = '\n';
  thisLine[size + 1] = '\0';

  return thisLine;
}

void read_lines(FILE *fp, char ***lines, int *num_lines) {
  /*
                                                                  read all of
     the lines in fp into lines and set num_lines to be the total number of
     lines in the file.
                                                                  @fp: a file
     pointer opened in read mode
                                                                  @lines: a
     pointer indicating where the lines should be placed. If there are no lines
     in a fill, lines will be set to NULL
                                                                  @num_lines: a
     pointer to the number of lines. set to the number of lines contained within
     lines
                                                                  @modifies:
     lines, num_lines
  */
  fseek(fp, 0L, SEEK_END);
  int sz = ftell(fp);
  rewind(fp);

  if (sz == 0) {
    lines = NULL;
    *num_lines = 0;
    return;
  }

  char *singleLine = (char *)malloc(sizeof(char));
  (*lines) = (char **)malloc(sizeof(char *));
  int inc = 0;
  *num_lines = 0;
  do {
    if (!feof(fp)) {
      singleLine = GetLine(fp);
      if (singleLine != NULL) {
        (*num_lines)++;
        (*lines) = realloc((*lines), sizeof(char *) * (*num_lines));
        (*lines)[inc] = strdup(singleLine);
        inc++;
      } else {
        break;
      }
    } else {
      break;
    }
  } while (true);
  if (*num_lines > 1) {
    (*num_lines)--;
  }
}