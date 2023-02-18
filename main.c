#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int x;
	int y;
	struct Node *next;
};
typedef struct Node node;

const int rows = 20;
const int cols = 20;

node *insert_at_head(node *head, node *newhead);
node *create_node(int x, int y);
void print_list(node *head);
void free_list(node *head);
void fill_array(int array[rows][cols], node *head);
void print_array(int array[rows][cols]);
node* step_world(char* direction,node* head);
void delete_last_node(node* head);

int main(void){
	node *head = NULL;
	node *temp;

	char input[100] = "d";

	int arr[rows][cols];
	
	for (int i = 0; i < 10; i++){
		temp = create_node(i, i);
		head = insert_at_head(head, temp);
	}

	while(strlen(input) != 0){
		fill_array(arr, head);
		gets(input);
		head = step_world(input,head);
		print_array(arr);
		print_list(head);

	}


	free_list(head);
	return 0;
}

node *create_node(int x, int y){
	node *temp = malloc(sizeof(node));
	temp->next = NULL;
	temp->x = x;
	temp->y = y;
	return temp;
}
node *insert_at_head(node *head, node *newhead){
	newhead->next = head;
	return newhead;
}
void delete_last_node(node *head){
	node *temp = head;
	node *prev;
	if(head == NULL){
		printf("empty list");
		return;
	}
	if(temp->next == NULL){
		printf("%d %d deleted\n",head->x,head->y);
        head = NULL;
        return;
	}
	 while (temp->next != NULL) {
        prev = temp; 
        temp = temp->next; 
    }
    prev->next = NULL;
    printf("%d %d deleted\n", temp->x,temp->y);
    free(temp);
}


void print_list(node *head){
	node *current = head;
	while (current != NULL){
		//printf("x: %d - y: %d\n", current->x, current->y);

		current = current->next;
	}
}
void free_list(node *head){
	node *tmp;

	while (head != NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void fill_array(int array[rows][cols], node *head){
	node *current = head;
	for (int x = 0; x < rows; x++){
		for (int y = 0; y < cols; y++){
			array[x][y] = 0;
		}
	}
	while (current != NULL){
		array[current->x][current->y] = 1;
		current = current->next;
	}
	for (int x = 0; x < rows; x++){
		for (int y = 0; y < cols; y++){
			if (array[x][y] != 1){
				array[x][y] = 0;
			}
		}
	}
}
void print_array(int array[rows][cols]){
	for (int x = 0; x < rows; x++){
		for (int y = 0; y < cols; y++){
			if (array[x][y] == 1){
				printf("\033[1;31m");
				printf("X");
				printf("\033[0;37m");
			}else{
				printf("\033[0;32m");
				printf("O");
				printf("\033[0;37m");
			}
		}
		printf("\n");
	}
}

node* step_world(char* direction,node* head){
	int dir = (int)direction[0];
	node* temp;
	node* tempo;
	switch (dir){
		case 97:
		
			printf("Up\n");
			delete_last_node(head);
			temp = create_node(head->x,head->y-1);
			tempo = insert_at_head(head, temp);
			return tempo;
			break;
		case 119:
	
			printf("Left\n");
			delete_last_node(head);
			temp = create_node(head->x-1,head->y);
			head = insert_at_head(head, temp);
			break;
		case 100:
		//s
			printf("Down\n");
			delete_last_node(head);
			temp = create_node(head->x,head->y+1);
			head = insert_at_head(head, temp);
			break;
		case 115:
		//d
			printf("Right\n");
			delete_last_node(head);
			temp = create_node(head->x+1,head->y);
			head = insert_at_head(head, temp);
			break;
		default:
			printf("dog");
		}
}

