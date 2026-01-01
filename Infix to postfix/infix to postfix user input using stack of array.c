
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct Stack {
  int size;
  int top;
  char *arr;
};

// Function declaration.
void setStackSize(struct Stack *s, int n);
int isEmpty(struct Stack *s);
void push(struct Stack *s, char value);
int pop(struct Stack *s);
char *infixToPostfix(char *infix);
int checkOperator(char ch);
int precedence(char ch);
int stackTop(struct Stack *s);

int main() {

  char infix[30];
  printf("Enter the infix expression: ");
  scanf("%s",infix);

  printf("The postfix expression is : %s", infixToPostfix(infix));
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

// Function for infix to postfix conversion which returns postfix expression.
char *infixToPostfix(char *infix) {

  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

  setStackSize(s, (strlen(infix) + 1));

  char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

  int i = 0; // Track of infix.
  int j = 0; // Track of postfix.

  while (infix[i] != '\0') {

    if (!checkOperator(infix[i])) {
      postfix[j] = infix[i];
      i++;
      j++;
    } else {
      if (precedence(infix[i]) > precedence(stackTop(s))) {
        push(s, infix[i]);
        i++;
      } else {
        postfix[j] = pop(stackTop(s));
        j++;
      }
    }
  }
  while (!isEmpty(s)) {
    postfix[j] = pop(s);
    j++;
  }
  postfix[j] = '\0';
  return postfix;
}

// Function for stack top.
int stackTop(struct Stack *s) {
  if (isEmpty(s)) {
    return -1;
  } else {
    return s->arr[s->top];
    ;
  }
}

// Function for check operator or not.
int checkOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
    return 1;
  } else {
    return 0;
  }
}

// Function for check precedence.
int precedence(char ch) {
  if (ch == '*' || ch == '/') {
    return 3;
  } else if (ch == '+' || ch == '-') {
    return 2;
  }
  return 0;
}
