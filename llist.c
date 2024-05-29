#include "llist.h"

#ifdef __cplusplus
extern "C"
{
#endif

    node_t* create_node(void *new_data)
    {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = new_data;
        new_node->next = NULL;
        return new_node;
    }
    void insertBeginning(node_t **headref, node_t *new_data)
    {
        if (headref == NULL)
            return;
        new_data->next = (*headref);
        *(headref) = new_data;
    }
    void insertAfter(node_t **headref, uint16_t pos, node_t *new_data)
    {
        if (headref == NULL)
            return;
        if (pos == 0)
        {
            insertBeginning(headref, new_data);
            return;
        }
        if (getNodeCount(headref) < pos)
        {
            insertEnd(headref, new_data);
            return;
        }
        node_t *temp = *(headref);
        uint16_t tempPosition = 1;
        while (temp != NULL && tempPosition < pos)
        {
            temp = temp->next;
            tempPosition++;
        }
        new_data->next = temp->next;
        temp->next = new_data;
    }
    void insertEnd(node_t **headref, node_t *new_data)
    {
        if (*headref == NULL)
        {
            new_data->next = (*headref);
            *headref = new_data;
        }
        else
        {
            node_t *last = *headref;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = new_data;
        }
    }
    void removeAfter(node_t **headref, uint16_t pos)
    {
        if (getNodeCount(headref) <= pos)
            return;
        if (headref == NULL)
            return;
        node_t *temp = *headref;
        for (uint16_t i = 0; temp != NULL && i < pos - 1; ++i)
            temp = temp->next;
        node_t *next = temp->next->next;
        free(temp->next);
        temp->next = next;
    }
    void removeBeginning(node_t **headref)
    {
        if (headref != NULL)
        {
            node_t *temp = *headref;
            *headref = (*headref)->next;
            free(temp);
            temp = NULL;
        }
    }
    void removePos(node_t **headref, uint16_t pos)
    {
        if (headref == NULL || pos == 0 || getNodeCount(headref) < pos)
            return;
        if (pos == 1)
        {
            removeBeginning(headref);
            return;
        }
        node_t *temp = *headref;
        for (uint16_t i = 0; temp != NULL && i < pos - 2; ++i)
        {
            temp = temp->next;
        }
        node_t *next = temp->next->next;
        free(temp->next);
        temp->next = next;
    }
    uint16_t getNodeCount(node_t **headref)
    {
        if (headref == NULL)
            return 0;
        uint16_t count = 0;
        node_t *temp = *headref;
        while (temp != NULL)
        {
            temp = temp->next;
            if (count <= UINT16_MAX)
                count++;
            else
                break;
        }
        return count;
    }
    void reverseList(node_t **headref)
    {
        if (headref == NULL)
            return;
        node_t *prev = NULL;
        node_t *current = *headref;
        node_t *following;
        while (current != NULL)
        {
            following = current->next;
            current->next = prev;
            prev = current;
            current = following;
        }
        *headref = prev;
    }
    void cleanup(node_t **headref)
    {
        if (headref == NULL)
            return;
        node_t *temp = *headref;
        while ((*headref) != NULL)
        {
            temp = *headref;
            *headref = (*headref)->next;
            free(temp);
        }
        *headref = NULL;
    }
#ifdef __cplusplus
}
#endif
