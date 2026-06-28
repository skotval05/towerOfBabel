#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>

// open the file
// parse by lines
// parse by words

// @param filename the full relative path of the file to parse.
// @return the structured program, tokenized by whitespace.
program readFile(char *filename) {

  program p;
  p.lines = NULL;
  p.length = 0;

  // create file and check validity
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Requested file opened unsuccessfully. Check the path provided, the "
           "permissions required, and if you have the file open otherwise.");
    return p;
  }

  // do things here

  char ch;

  line currentLine;
  currentLine.words = NULL;
  currentLine.length = 0;

  word currentWord;
  currentWord.chars = NULL;
  currentWord.length = 0;

  while ((ch = fgetc(f)) != EOF) {
    // check if we receive a semicolon
    if (ch == ';') {
      //    to break into lines
      //    make semicolon its own word, though

      // append current word to line
      appendWordToLine(&currentLine, currentWord);

      // add semicolon as its own word for ease of lexer
      word stop;
      stop.chars = NULL;
      stop.length = 0;
      appendCharToWord(&stop, ch);
      appendWordToLine(&currentLine, stop);

      // append current line to program
      appendLineToProg(&p, currentLine);

      // clean up current word and line.
      free(currentLine.words);
      currentLine.length = 0;
      currentLine.words = NULL;
      free(currentWord.chars);
      currentWord.length = 0;
      currentWord.chars = NULL;
    }

    // then check if we receive a space
    if (ch == ' ' || ch == '\t' || ch == '\n') {
      //    to break into words

      // do not add space character to word.
      appendWordToLine(&currentLine, currentWord);

      // clean up current word.
      free(currentWord.chars);
      currentWord.chars = NULL;
      currentWord.length = 0;
    }

    // if neither, append to the current word
    appendCharToWord(&currentWord, ch);
  }

  return p;
}

tokenList lex(program p);

void appendCharToWord(word *w, char c) {
  char *temp = realloc(w->chars, w->length + 1);
  if (temp == NULL)
    return;
  w->chars = temp;
  w->chars[w->length] = c;
  w->length += 1;
  return;
}

void appendWordToLine(line *l, word w) {
  word *temp = realloc(l->words, l->length + 1);
  if (temp == NULL)
    return;
  l->words = temp;
  l->words[l->length] = w;
  l->length += 1;
  return;
}

void appendLineToProg(program *p, line l) {
  line *temp = realloc(p->lines, p->length + 1);
  if (temp == NULL)
    return;
  p->lines = temp;
  p->lines[p->length] = l;
  p->length += 1;
  return;
}
