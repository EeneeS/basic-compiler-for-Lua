#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

// KEEP ORDER, ADD TO END OF LIST !!!
typedef enum {
  TOKEN_IDENTIFIER,
  TOKEN_KEYWORD,
  TOKEN_INVALID,
  TOKEN_EOF,
  TOKEN_NUMBER,
  TOKEN_PLUS,
  TOKEN_MULTIPLY,
  TOKEN_INCREMENT,
  TOKEN_DECREMENT,
  TOKEN_EXPONENTIATION,
  TOKEN_MINUS,
  TOKEN_SLASH,
  TOKEN_EQUALITY,
  TOKEN_ASSIGNMENT,
  TOKEN_LTE,
  TOKEN_GTE,
  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_LBRACE,
  TOKEN_RBRACE,
  TOKEN_SEMICOLON,
} TokenType;

typedef struct {
  TokenType type;
  char *value;
  int line;
  int column;
} Token;

typedef struct {
  char *source_code;
  size_t position;
  size_t read_position;
  char current_char;
} Lexer;

void lexer_init(Lexer *lexer, char *input);
Token lexer_next_token(Lexer *lexer);
void free_token(Token *token);

#endif
