#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Funciones de la pila */
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Error: pila llena\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Error: pila vacía\n");
        return 0;
    }
}

int main() {
    char operador;
    int a, b, valor;

    printf("Calculadora RPN\n");
    printf("Ingrese numeros y operadores (+ - * /)\n");
    printf("Presione q para salir\n\n");

    while (1) {
        printf("> ");
        if (scanf(" %c", &operador) != 1) {
            break;
        }

        if (operador == 'q') {
            break;
        }

        if (operador >= '0' && operador <= '9') {
            valor = operador - '0';
            push(valor);
        } else {
            b = pop();
            a = pop();

            switch (operador) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    if (b != 0)
                        push(a / b);
                    else
                        printf("Error: division por cero\n");
                    break;
                default:
                    printf("Operador no valido\n");
            }
        }

        if (top >= 0) {
            printf("Resultado actual: %d\n", stack[top]);
        }
    }

    return 0;
}
