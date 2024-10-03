#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void insertFirst(DoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void insertLast(DoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->tail == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void insertAfter(DoublyLinkedList* list, int pos, int value) {
    if (list->head == NULL) return;
    Node* current = list->head;
    for (int i = 1; i < pos && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        Node* newNode = createNode(value);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        if (current == list->tail) {
            list->tail = newNode;
        }
    }
}

void deleteFirst(DoublyLinkedList* list) {
    if (list->head == NULL) return;
    Node* temp = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(temp);
}

void deleteLast(DoublyLinkedList* list) {
    if (list->tail == NULL) return;
    Node* temp = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(temp);
}

void deleteAt(DoublyLinkedList* list, int pos) {
    if (list->head == NULL) return;
    Node* current = list->head;
    for (int i = 1; i < pos && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            list->head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        } else {
            list->tail = current->prev;
        }
        free(current);
    }
}

void printList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void printReverseList(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->prev;
    }
}

void searchValue(DoublyLinkedList* list, int value) {
    Node* current = list->head;
    int position = 1;
    while (current != NULL) {
        if (current->value == value) {
            printf("%d", position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("-1");
}

int main() {
    DoublyLinkedList list;
    char commands[31];
    scanf("%30s", commands);
    initList(&list);

    int len = strlen(commands);
    for (int i = 0; i < len; i++) {
        char command = commands[i];
        int value = commands[i + 1] - '0';
        switch (command) {
            case 'N':
                initList(&list);
                insertFirst(&list, value);
                i++;
                break;
            case 'I':
                if (commands[i + 1] == 'F') {
                    insertFirst(&list, commands[i + 2] - '0');
                    i += 2;
                } else if (commands[i + 1] == 'A') {
                    insertAfter(&list, commands[i + 2] - '0', commands[i + 3] - '0');
                    i += 3;
                } else if (commands[i + 1] == 'L') {
                    insertLast(&list, commands[i + 2] - '0');
                    i += 2;
                }
                break;
            case 'D':
                if (commands[i + 1] == 'F') {
                    deleteFirst(&list);
                    i++;
                } else if (commands[i + 1] == 'A') {
                    deleteAt(&list, commands[i + 2] - '0');
                    i += 2;
                } else if (commands[i + 1] == 'L') {
                    deleteLast(&list);
                    i++;
                }
                break;
            case 'P':
                printList(&list);
                break;
            case 'R':
                printReverseList(&list);
                break;
            case 'S':
                searchValue(&list, value);
                i++;
                break;
            default:
                break;
        }
    }

    return 0;
}
