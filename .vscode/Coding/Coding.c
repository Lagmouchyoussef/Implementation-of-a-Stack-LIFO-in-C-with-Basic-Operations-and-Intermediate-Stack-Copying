#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} stack;

Bool_is_empty(stack *top) {
    return (top == NULL);
}

stack* Push(stack *top, int val) {
    stack *new_node = (stack *)malloc(sizeof(stack));
    new_node->data = val;
    new_node->next = top;
    top = new_node;
    return top;
}

int Pop(stack **top) {
    if(!Bool_is_empty(*top)) {
        stack *temp = *top;
        int val = temp->data;
        *top = (*top)->next;
        free(temp);
        return val;
    }
    return -1;
}

void Display(stack *top) {
    stack *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

stack* Copy(stack *top) {
    stack *copy = NULL;
    stack *temp = top;
    while (temp != NULL) {
        copy = Push(copy, temp->data);
        temp = temp->next;
    }
    return copy;
}

int main() {
    stack *top = NULL;
    int choice, val;

    do {
        printf("1. Push\n2. Pop\n3. Display\n4. Copy\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                top = Push(top, val);
                break;
            case 2:
                if (!Bool_is_empty(top)) {
                    val = Pop(&top);
                    printf("Popped value: %d\n", val);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 3:
                Display(top);
                break;
            case 4:
                stack *stack_copy = Copy(top);
                printf("Stack copy: ");
                Display(stack_copy);
                while (!Bool_is_empty(stack_copy)) {
                    Pop(&stack_copy);
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    while (!Bool_is_empty(top)) {
        Pop(&top);
    }

    return 0;
}