// Ye program bas batayega ki expression mai parenthesis match ho rahi hai ya
// nahi.Expression ki validity ko nahi batayega.Keet it in mind.

#include "stdio.h"
#include "stdlib.h"

struct Stack {
  int size;
  int top;
  char *arr;
};

// Function declaration.
void setStackSize(struct Stack *s, int n);
int isEmpty(struct Stack *s);
int isFull(struct Stack *s);
void push(struct Stack *s, char value);
int pop(struct Stack *s);
int parenthesisMatch(char *exp);
int match(char a, char b);

int main() {

  char *exp = "{a+b()}*c+d}*f";

  if (parenthesisMatch(exp)) {
    printf("\nparenthesis are  matching\n");
  } else {
    printf("\nparenthesis are not matching\n");
  }
  return 0;
}

// Set size function defination.
void setStackSize(struct Stack *s, int n) {
  s->size = n;
  s->top = -1;
  s->arr = (char *)malloc(s->size * sizeof(char));
}

// Function for check stack is empty or not.
int isEmpty(struct Stack *s) {
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

// Function for check stack is full or not.
int isFull(struct Stack *s) {
  if (s->top == s->size - 1) {
    return 1;
  } else {
    return 0;
  }
}

// Function for push a element in stack.
void push(struct Stack *s, char value) {
  if (isFull(s)) {
    printf("STACK OVERFLOW : can't push %c \n ", value);
    return;
  } else {
    s->top++;
    s->arr[s->top] = value;
    return;
  }
}

// Function for pop a element from the stack.
int pop(struct Stack *s) {

  if (isEmpty(s)) {
    printf("STACK UNDERFLOW \n");
    return 1;

  } else {
    char val = s->arr[s->top];

    // free(&s->arr[s->top]); it's optional due to push operation mai vo vaise
    // bhi overrite karega hi to iska koi sens nahi hoga.
    s->top--;
    return val;
  }
}

// Parenthesis match function.
int parenthesisMatch(char *exp) {
  // Creating stack.
  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

  // setting size of stack 100.
  setStackSize(s, 100);

  char popped_ch;

  for (int i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      push(s, exp[i]);
    }

    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if (isEmpty(s)) {
        return 0;
      }
      popped_ch = pop(s);
      if (!match(popped_ch, exp[i])) {
        return 0;
      }
    }
  }
  if (isEmpty(s)) {
    return 1;
  } else {
    return 0;
  }
}

// Function for check match.
int match(char a, char b) {
  if (a == '(' && b == ')') {
    return 1;
  }
  if (a == '{' && b == '}') {
    return 1;
  }
  if (a == '[' && b == ']') {
    return 1;
  }
  return 0;
}
