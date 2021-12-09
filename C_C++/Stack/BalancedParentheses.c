#include <stdio.h>
#include <string.h>

struct Node {
    char* data;
    struct Node* next;
};

struct Node* top = NULL;

void Push(char x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

char Pop() {
    struct Node* temp;
    if (top == NULL) return NULL;
    temp = top;
    top = top->next;
    int res = temp->data;
    free(temp);
    return res;
}

char Peek() {
    if(top == NULL) return NULL;
    return top->data;
}

int checkBalance(char* exp) {
    int len = strlen(exp);
    int i;
    for(i = 0; i < len; i++) {
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            Push(exp[i]);
        }
        else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
            char peek = Peek();
            if(peek == NULL) return 0;
            // printf("%c\n", pop);
            if(!((peek == '{' && exp[i] == '}') || (peek == '(' && exp[i] == ')') || (peek == '[' && exp[i] == ']')))
                return 0;
            else Pop();
        }
    }
    if(top == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    int res = checkBalance("{HHK[(){{[]}{}/}][]([]{})}OI");
    if(res == 0){
        printf("Parenthesis are not balanced\n");
    } else if(res == 1) {
        printf("Parenthesis are balanced\n");
    }
}