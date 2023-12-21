#include <stdio.h>
 
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
};


//Lista enlazada con 3 nodos
struct node* BuildOneTwoThree() {

struct node* head = malloc(sizeof(struct node));
struct node* second = malloc(sizeof(struct node));
struct node* third = malloc(sizeof(struct node));

head->data = 1;
head->next = second;

second->data = 2;
second->next = third;

third->data = 3;
third->next = NULL;

return head;
}

//lista enlazasa con 2 nodos
struct node* BuildTwoThree() {

struct node* head = malloc(sizeof(struct node));
struct node* second = malloc(sizeof(struct node));

head->data = 2;
head->next = second;

second->data = 3;
second->next = NULL;

return head;
}





//WrongPush->Manera Erronea para insertar al inicio
void WrongPush(struct node* head, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode; // NO esta linia no funciona!
}

struct node* WrongPushTest() {
    struct node* head = BuildTwoThree();
    WrongPush(head, 1);// intenta poner 1 al frente - no funciona
    return head;
}


//Push->Correcta manera de insertar datos al inicio
void Push(struct node** headRef, int data){
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

struct node* PushTest(){
    struct node* head = BuildTwoThree();
    Push(&head,1);

    return head;
}




//lenght->tamano de la lista
int length(struct node* head){
    struct node* current = head;
    int count = 0;

    while (current !=NULL){
        count++;
        current = current->next;
    }

    return count;
}
//print->imprimir la lista
void print(struct node* head){
	while (head){
		int data = head -> data;
		printf("%d", data);
		head = head->next;
	}

	printf("\n");
}
//freeMemory->Liberar la memoria
void freeMemory(struct node* head){
	while (head){
		struct node* next = head -> next;
		free(head);
		head->next;
	}
}

//casos especiales insertar a la cola
struct node* BuildWithSpecialCase() {
    struct node* head = NULL;
    struct node* tail;
    int i;

    Push(&head, 1);
    tail = head;
    
    for (i=2; i<6; i++) {
    Push(&(tail->next), i);
    tail = tail->next;
    }
    return(head);
}
//main
int main(){

	//struct node* lista = BuildOneTwoThree();
	//print(lista);
    printf("INCORRECTO\n");
    print(WrongPushTest());
    printf("\n");
    printf("CORRECTO\n");
    print(PushTest());
    print(BuildWithSpecialCase());
    //int len = length(lista);
	//freeMemory(lista);
	return 0;
}
