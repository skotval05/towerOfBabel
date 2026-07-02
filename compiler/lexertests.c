#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "lexer.h"

int main() {

  // Lexer Tests

  printf("nerd ur pretty and stupid but ur cute\n");
  printf("Testing word constructor...\n");

  word w;
  w.chars = NULL;
  w.length = 0;

  assert(w.chars == NULL);
  assert(w.length == 0);

  printf("Testing append character to word\n");

  appendCharToWord(&w, '!');

  assert(w.chars != NULL);
  assert(w.length == 1);
  assert(w.chars[0] = '!');

  appendCharToWord(&w, '?');

  assert(w.chars != NULL);
  assert(w.length == 2);
  assert(w.chars[0] == '!');
  assert(w.chars[1] == '?');

  printf("pretty girl thigh pillow :)\n");
  printf("Word tests good.\n");

  //////////////////////////////////////////////////////

  printf("Testing line constructor\n");

  line l;
  l.words = NULL;
  l.length = 0;

  assert(l.words == NULL);
  assert(l.length == 0);

  printf("Testing append words to line\n");

  appendWordToLine(&l, w);

  assert(l.words != NULL);
  assert(l.length == 1);
  assert(l.words[0].chars[0] == '!');
  assert(l.words[0].chars[1] == '?');
  assert(l.words[0].length == 2);

  word w2;
  w2.chars = NULL;
  w2.length = 0;
  appendCharToWord(&w2, ':');
  appendCharToWord(&w2, '>');

  appendWordToLine(&l, w2);

  assert(l.words != NULL);
  assert(l.length == 2);
  assert(l.words[0].length == 2);
  assert(l.words[1].length == 2);
  assert(l.words[0].chars[0] == '!');
  assert(l.words[0].chars[1] == '?');
  assert(l.words[1].chars[0] == ':');
  assert(l.words[1].chars[1] == '>');

  //////////////////////////////////////////////////////

  printf("Testing program constructor\n");

  program p;

  p.lines = NULL;
  p.length = 0;

  assert(p.lines == NULL);
  assert(p.length == 0);

  printf("Testing append lines to program\n");

  appendLineToProg(&p, l);

  // printf("can append a line to program");

  assert(p.lines != NULL);
  assert(p.length == 1);

  word w3;
  word w4;
  word w5;

  w3.chars = NULL;
  w3.length = 0;

  w4.chars = NULL;
  w4.length = 0;

  w5.chars = NULL;
  w5.length = 0;

  appendCharToWord(&w3, 's');
  appendCharToWord(&w3, 'u');
  appendCharToWord(&w3, 'c');
  appendCharToWord(&w3, 'k');

  appendCharToWord(&w4, 'm');
  appendCharToWord(&w4, 'y');

  appendCharToWord(&w5, 'n');
  appendCharToWord(&w5, 'u');
  appendCharToWord(&w5, 't');
  appendCharToWord(&w5, 's');

  line l2;
  l2.words = NULL;
  l2.length = 0;

  appendWordToLine(&l2, w3);
  appendWordToLine(&l2, w4);
  appendWordToLine(&l2, w5);

  appendLineToProg(&p, l2);
  printf("lines appended to program\n");
  /* Current Program:
   *
   * !? :>
   * suck my nuts
   *
   */

  assert(p.lines != NULL);
  assert(p.length == 2);

  assert(p.lines[0].length == 2);
  assert(p.lines[0].words[0].length == 2);
  assert(p.lines[0].words[0].chars[0] == '!');
  assert(p.lines[0].words[0].chars[1] == '?');

  assert(p.lines[0].words[1].length == 2);
  assert(p.lines[0].words[1].chars[0] == ':');
  assert(p.lines[0].words[1].chars[1] == '>');

  assert(p.lines[1].length == 3);
  assert(p.lines[1].words[0].length == 4);
  assert(p.lines[1].words[0].chars[0] == 's');
  assert(p.lines[1].words[0].chars[1] == 'u');
  assert(p.lines[1].words[0].chars[2] == 'c');
  assert(p.lines[1].words[0].chars[3] == 'k');

  assert(p.lines[1].words[1].length == 2);
  assert(p.lines[1].words[1].chars[0] == 'm');
  assert(p.lines[1].words[1].chars[1] == 'y');

  assert(p.lines[1].words[2].length == 4);
  assert(p.lines[1].words[2].chars[0] == 'n');
  assert(p.lines[1].words[2].chars[1] == 'u');
  assert(p.lines[1].words[2].chars[2] == 't');
  assert(p.lines[1].words[2].chars[3] == 's');

  /////////////////////////////////////////////////////////////////

  // Test file is built as follows:
  // LINE COUNT: 4
  // LINE 1 WORD COUNT: 5
  // LINE 2 WORD COUNT: 4
  // LINE 3 WORD COUNT: 2
  // LINE 4 WORD COUNT: 6
  //
  //
  // there are words here;
  // semicolons break lines;
  // sometimes; they may look like this;

  printf("Testing file text extraction to program structure\n");

  char *filename = "testFile.txt";
  program outProgram;

  outProgram.lines = NULL;
  outProgram.length = 0;

  assert(outProgram.lines == NULL);
  assert(outProgram.length == 0);

  printf("can init program.\n");

  outProgram = readFile(filename);

  printf("readfile completed\n");

  assert(outProgram.lines != NULL);
  assert(outProgram.length == 4);

  assert(outProgram.lines[0].words != NULL);

  assert(outProgram.lines[0].length == 5);
  assert(outProgram.lines[1].length == 4);
  assert(outProgram.lines[2].length == 2);
  assert(outProgram.lines[3].length == 6);

  /////////////////////////////////////////////////////////////////

  // second test file testFileTwo.txt
  //
  // lets try    lots of spaces;
  // or perhaps a line
  // split with a whitespace;
  // and now a few semicolons in a row;;;
  //
  // LINE COUNT: 5
  // LINE 1 WORD COUNT: 6
  // LINE 2 WORD COUNT: 9
  // LINE 3 WORD COUNT: 9
  // LINE 4 WORD COUNT: 1
  // LINE 5 WORD COUNT: 1

  printf("second file tests\n");

  char *secondFileName = "testFileTwo.txt";

  program secondTestProgram;

  secondTestProgram.lines = NULL;
  secondTestProgram.length = 0;

  secondTestProgram = readFile(secondFileName);

  assert(secondTestProgram.lines != NULL);
  assert(secondTestProgram.length == 5);

  assert(secondTestProgram.lines[0].length == 6);
  assert(secondTestProgram.lines[1].length == 9);
  assert(secondTestProgram.lines[2].length == 9);
  assert(secondTestProgram.lines[3].length == 1);
  assert(secondTestProgram.lines[4].length == 1);

  printf("All program construction tests complete.\n");

  /////////////////////////////////////////////////////////////////

  printf("Testing token creation\n");

  token t;
  t.name = "TEST";
  t.type = NONE;
  t.value = NULL;

  assert(strcmp(t.name, "TEST") == 0);
  assert(t.type == NONE);
  assert(t.value == NULL);

  /////////////////////////////////////////////////////////////////
  printf("All tests passed.\n");
  return 0;
}
