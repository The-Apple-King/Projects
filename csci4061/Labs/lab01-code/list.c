#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void list_init(list_t *list) {
    list->head = NULL;
    list->size = 0;
}

void list_add(list_t *list, const char* data) {
    if (list->size == 0)
    {
        node_t *new = malloc(sizeof(node_t));
        strncpy(new->data, data, 128);
        new->next = NULL;
        list->head = new;
        
    }
    else{
   node_t *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node_t *new = malloc(sizeof(node_t));
    strncpy(new->data, data, 128);
    new->next = NULL;
    temp->next = new;
    }

    list->size++;
}

int list_size(const list_t *list) {
    return list->size;
}

char *list_get(const list_t *list, int index) {
    node_t *tempnode = list->head;
    for (size_t i = 0; i < index && tempnode != NULL; i++)
    {
        tempnode = tempnode->next;
    }
    
    return tempnode->data;
}

void list_clear(list_t* list) {
    node_t *tempnode = list->head;
    if (list->head != NULL)
    {
        tempnode = list->head;
        list->head = list->head->next;
        free(tempnode);
        list_clear(list);
        list->size--;
    }
    
}

int list_contains(const list_t *list, const char *query) {

    
    node_t *tempnode = list->head;
    for (size_t i = 0; i < list->size && tempnode != NULL; i++)
    {
        if(strcmp(tempnode->data, query) == 0){
            return 1;
        }
        tempnode = tempnode->next;
    }
    return 0;
    
}

void list_print(const list_t *list) {
    int i = 0;
    node_t *current = list->head;
    while (current != NULL) {
        printf("%d: %s\n", i, current->data);
        current = current->next;
        i++;
    }
}
