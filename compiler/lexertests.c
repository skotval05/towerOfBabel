#include <assert.h>
#include <stdio.h>

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

  printf("All tests passed.\n");
  return 0;
}
