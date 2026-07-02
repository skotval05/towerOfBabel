#ifndef LEXER_H
#define LEXER_H

enum _tokenType { NONE, NUMTYPES };
typedef enum _tokenType tokenType;

struct _token {
  tokenType type;
  char *name;
  char *value;
};
typedef struct _token token;

struct _tokenList {
  token *tokens;
  int length;
};
typedef struct _tokenList tokenList;

struct _word {
  char *chars;
  int length;
};
typedef struct _word word;

struct _line {
  word *words;
  int length;
};
typedef struct _line line;

struct _program {
  line *lines;
  int length;
};
typedef struct _program program;

program readFile(char *filename);
tokenList lex(program p);

void appendCharToWord(word *w, char c);
void appendWordToLine(line *l, word w);
void appendLineToProg(program *p, line l);

void appendTokenToList(tokenList *tl, token t);

#endif
