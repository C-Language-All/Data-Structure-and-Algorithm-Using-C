//Ye program bas batayega ki expression mai parenthesis match ho rahi hai ya nahi.Expression ki validity ko nahi batayega.Keet it in mind.



#include "stdio.h"
#include "stdlib.h"

// Global
struct Node *top = NULL;


struct Node {
  char data;
  struct Node *next;
};

// Function declarations.
int isEmpty(struct Node *top);
int isFull(struct Node *top);
struct Node *push(struct Node *top, char x);
int pop(struct Node *top);
int parenthesisMatch(char *exp);



int main(void) {
  char exp[100] = "2*(3(+4))";
  if(parenthesisMatch(exp)){
    printf("\nParenthesis is matching\n");
  }
  else{
    printf("\nParenthesis is not matching\n");
  }
  
  return 0;
}

// Function for check empty.
int isEmpty(struct Node *top) {
  if (top == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// Function for check full.
int isFull(struct Node *top) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (n == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// Function for push.
struct Node *push(struct Node *top, char x) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (isFull(top)) {
    printf("STACK OVERFLOW\n");
  } else {
    n->data = x;
    n->next = top;
    top = n;
    return top;
  }
}

// Function for pop.
int pop(struct Node *tp) {

  if (isEmpty(tp)) {
    printf("STACK UNDERFLOW\n");
    
  } else {
    struct Node *n = tp;
    top = tp->next;
    char x = n->data;
    free(n);
    return x;
  }
}


// Parenthesis match function.
int parenthesisMatch(char *exp) {
  
  for (int i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(') {
      top = push(top, '(');
    } else if (exp[i] == ')') {
      if (isEmpty(top)) {
        return 0;
      }
      pop(top);
    }
  }
  if (isEmpty(top)) {
    return 1;
  } else {
    return 0;
  }
}
