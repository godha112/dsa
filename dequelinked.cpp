#include<iostream>
using namespace std;


class Node{
    public:
    int item;
    Node* next;
    Node* prev;
    static Node* getnode(int data){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->item = data;
        newNode->next = newNode->prev = NULL;
        return newNode;
    }
};


class dequeue{
    int Size;
    Node* first;
    Node* last;
public:
    dequeue(){
        first = last = NULL;
        Size = 0;
    }
    int Siz();
    bool isempty();
    void insertfirst(int data);
    void insertfinal(int data);
    void deletefirst();
    void deletelast();
    int getfirst();
    int getlast();
    void Erase();

};

bool dequeue::isempty(){
    return (first==NULL);
}

int dequeue::Siz(){
    return Size;
}



void dequeue::insertfirst(int data){
    Node* Newfirst = Node::getnode(data);
    if(Newfirst==NULL){
        cout<<"enter proper data.";
    }
    else if(first == NULL){
        first = Newfirst;
        last = Newfirst;
    }
    else{
        Newfirst->next = first;
        first->prev = Newfirst;
        first = Newfirst;
    }
    Size++;
}


void dequeue::insertfinal(int data){
    Node* newlast = Node::getnode(data);
    if(newlast==NULL){
        cout<<"enter proper data";
    }
    else if(first==NULL){
        last = newlast;
        first = newlast;
    }
    else{
        newlast->prev = last;
        last->next = newlast;
        last = newlast;
    }
    Size++;
}

void dequeue::deletefirst(){
    if(isempty()){
        cout<<"underflow";
    }
    else{
        first = last->next;
        if(first==NULL){
            last=NULL;
        }
        else{
            first->prev=NULL;
        }
    }
    Size--;
}

void dequeue::deletelast(){
    if(isempty()){
        cout<<"overflow";
    }
    else{
        last = last->prev;
        if(last==NULL){
            first=NULL;
        }
        else{
            last->prev=NULL;
        }
    }
    Size--;
}



int dequeue::getfirst(){
    if(isempty()){
        return -1;
    }
    return first->item;
}


int dequeue::getlast(){
    if(isempty()){
        return -1;
    }
    return last->item;
}

void dequeue::Erase(){
    last = NULL;
    while(first!=NULL){
        deletefirst();
    }
    Size = 0;
}

int main(){
    dequeue dq;
    dq.insertfirst(2);
    dq.insertfinal(3);
}
