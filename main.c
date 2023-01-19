#include <stdio.h>
#include <stdlib.h>

struct Node{
	int x;
	int y;
	struct Node* next;
};
typedef struct Node node;
const int rows = 20;
const int cols = 20;

node* insert_at_head(node* head, node* newhead);
node *create_node(int x, int y);
void print_list(node *head);
void free_list(node* head);
void fill_array(int array[rows][cols],node* head);
void print_array(int array[rows][cols]);

int main(void){
	node *head = NULL;
	node *temp;

	
	int arr[rows][cols];


	for (int i = 0; i < 10; i++){
		temp = create_node(i,i);
		head = insert_at_head(head,temp);
	}
	
	
	fill_array(arr,head);
	
	print_array(arr);
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
node* insert_at_head(node* head, node* newhead){
	newhead->next = head;
	return newhead;
}
void print_list(node *head){
	node *current = head;
	while(current != NULL){
		printf("x: %d - y: %d\n",current->x,current->y);

		current = current->next;
		}
}
void free_list(node* head){
   node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

void fill_array(int array[rows][cols],node* head){
	node *current = head;
	while(current != NULL){
		array[head->x][head->y] = 1;

		current = current->next;
	}
	for (int x = 0; x < rows; x++){
		for (int y = 0; y < cols; y++){
			if(array[x][y] != 1){
				array[x][y] = 0;
			}
		}	
	}
}
void print_array(int array[rows][cols]){
	for (int x = 0; x < rows; x++){
		for (int y = 0; y < cols; y++){
			if(array[x][y] != 1){
				printf("\033[1;31m");
				printf("X");
				printf("\033[0m");
			}else{
				printf("\033[0;32m");
				printf("O");
				printf("\033[0m");
			}
		}
		printf("\n");
	}
	
}