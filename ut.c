#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Users.h"
#include "Posts.h"
#define TRUE 1

node *newnode(char *username, char *password)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->username = username;
    newnode->password = password;
    newnode->next = NULL;
    return newnode;
}

void Adduser(node *head, node *newnode)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newnode;
}

int listlength(node *head)
{
    int length = 0;
    node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

void printlist(node *head)
{
    int index = 0;
    do
    {
        head = head->next;
        index++;
        printf("username %d: %s\n", index, head->username);
    } while (head != NULL);
}

int searching_the_list(node *head, char *user)
{
    node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (strcmp((temp->username), user) == 0)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return 0;
}

int main()
{
    printf("\t\tWelcome to the UT_TWEET\n");
    printf("Please Enter the username and password for a new user :\n");
    node *head;
    node *temp = head;
    temp = (node *)malloc(sizeof(node));
    if (temp->next == NULL)
    {
        return 0;
    }
    head->next = NULL;
    char *command = (char *)malloc(sizeof(char));
    while (TRUE)
    {
        char *username = (char *)malloc(sizeof(char));
        char *password = (char *)malloc(sizeof(char));
        scanf("%s %s %s", command, username, password);
        if (strcmp(command, "signup") == 0)
        {
            Adduser(head, newnode(username, password));
            printf("YOU HAVE SIGNUPED TO YOUR ACCOUNT\n");
            printlist(head);
            printf("NUMBER OF THE USERS = %d", listlength(head));
            continue;
        }
        else if (strcmp(command, "login") == 0)
        {
            searching_the_list(head, username);
            printf("YOU HAVE LOGGED INTO YOUR ACCOUNT\n");
            continue;
        }
        else
        {
            printf("YOU HAVE ENTERED A WRONG COMMAND\n");
            continue;
            ;
        }
    }
    return 0;
}
