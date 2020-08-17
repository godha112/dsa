#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int key;
    node* next_node;
};

void push_front(node **head_ref, int Key){
    node* newNode = new node();
    newNode->next_node = *head_ref;
    newNode->key = Key;
    *head_ref = newNode;
}

void top_front(node **head_ref){
    cout<<"the key of head node of linked list = "<<(*head_ref)->key<<endl;
}

void pop_front(node **head_ref){
    if(*head_ref == NULL){
        cout<<"this action cannot be performed as the linked list is empty!!"<<endl;
    }
    else{
        *head_ref = (*head_ref)->next_node;
    }
    cout<<"the head element is removed and updated!"<<endl;
}

void push_back(node **head_ref, int data){
    node* new_node = new node();
    node* backnode = new node();
    backnode->key = data;
    backnode->next_node = NULL;
    if(*head_ref == NULL){
        *head_ref = backnode;
        return;
    }
    new_node = *head_ref;
    while(new_node->next_node != NULL){
        new_node = new_node->next_node;
    }
    new_node->next_node = backnode;
}

void top_back(node **head_ref){
    if(*head_ref == NULL){
        cout<<"this action cannot be performed as linked list is empty!!"<<endl;
        return;
    }
    node* newnode = *head_ref;
    while(newnode->next_node != NULL){
        newnode = newnode->next_node;
    }
    cout<<"the key of the tail element is - "<<newnode->key<<endl;
}

void pop_back(node **head_ref){
    node* newnode = *head_ref;
    while(newnode->next_node->next_node != NULL){
        newnode = newnode->next_node;
    }
    newnode->next_node = NULL;
    cout<<"the tail element deleted!"<<endl;
}

bool empty(node **head_ref){
    if(*head_ref == NULL){
        cout<<"the linked list is empty!"<<endl;
        return true;
    }
    
    cout<<"the linked list is not empty!!"<<endl;
    return false;
    
}

void display_list(node **head_ref){
    if(*head_ref == NULL){
        cout<<"the list is empty!!"<<endl;
        return;
    }
    node* new_node = *head_ref;
    while(new_node->next_node != NULL){
        cout<<new_node->key<<endl;
        new_node = new_node->next_node;
    }
    cout<<new_node->key<<endl;
}

void search_element_index(node **head_ref, int index){
    int i = 1;

    node* new_node = new node();
    new_node = *head_ref;
    while(index != i){
        new_node = new_node->next_node;
        i++;
    }
    cout<<"the element at the index - "<<index<<"is"<<new_node->key<<endl;
}

int count_elements(node **head_ref){
    int count = 0;
    node* new_node = *head_ref;
    while(new_node->next_node != NULL){
        count++;
        new_node = new_node->next_node;
    }
    return count;
}

void add_before(node **head_ref, int Key, int pos){
    node* new_node = *head_ref;
    int count_num = count_elements(&new_node);
    if(pos > count_num+1){
        cout<<"the postion exceeds the length of the list!!"<<endl;
        cout<<"make sure you enter any positive value less than or equal to "<<count_num + 1<<endl;
        return;
    }
    node* new_node2 = new node();
    new_node2->key = Key;
    int index = 1;
    while((index) != (pos-1)){
        new_node = new_node->next_node;
        index++;
    }

    new_node2->next_node = new_node->next_node;
    new_node->next_node = new_node2;

    cout<<"the element "<<Key<<" is successfully placed before the "<<pos<<" node"<<endl;

}

void add_after(node **head_ref, int Key, int pos){
    node* new_node = *head_ref;
    int count_ele = count_elements(&new_node);
    if(count_ele+1 < pos){
        cout<<"the postion exceeds the length of the list!!"<<endl;
        cout<<"make sure you enter any positive value less than or equal to "<<count_ele + 1<<endl;
        return;
    }

    node* new_node2 = new node();
    new_node2->key = Key;

    int index = 1;

    while(index != pos){
        new_node = new_node->next_node;
        index++;
    }

    new_node2->next_node = new_node->next_node;
    new_node->next_node = new_node2;

     cout<<"the element "<<Key<<" is successfully placed after the "<<pos<<" node"<<endl;
}


int main(){
    node *head = NULL;
    string next_operation = "yes";
    while(next_operation == "yes"){
        int api;
        cout<<"enter the operation you want to perform - "<<endl;
        cout<<"0 - display the list"<<endl;
        cout<<"1 - enter few elements in the list at a certain position - "<<endl;
        cout<<"2 - view the element at a position"<<endl;
        cout<<"3 - number of elements int the group"<<endl;
        cout<<"4 - delete an element"<<endl;
        cin>>api;
        switch (api)
        {
        case 0:{
            display_list(&head);
            break;
        }
        case 1:{
            cout<<"do you want to enter the element at the top of the list or the end of the list or at a particular position?"<<endl;
            cout<<"1 - top of the list"<<endl;
            cout<<"2 - end of the list"<<endl;
            cout<<"3 - at the particular position of the list"<<endl;
            int temp;
            cin>>temp;
            switch (temp)
            {
            case 1:{
                cout<<"enter the number of elements you want to enter into the list - ";
                int n;
                cin>>n;
                cout<<"enter "<<n<<" "<<"number of elements - "<<endl;
                for(int i=0; i<n; i++){
                    int temp;
                    cin>>temp;
                    push_front(&head, temp);
                }
                cout<<"all the elements are sucessfully stored in the list!!!"<<endl;
                break;
            }
            case 2:{
                cout<<"enter the number of elements you want to enter into the list - ";
                int n;
                cin>>n;
                cout<<"enter "<<n<<" "<<"number of elements - "<<endl;
                for(int i=0; i<n; i++){
                    int temp;
                    cin>>temp;
                    push_back(&head, temp);
                }
                cout<<"all the elements are sucessfully stored in the list!!!"<<endl;
                break;
            }
            case 3:
            {
                cout<<"enter the value of the position you want to add - "<<endl;
                cout<<"0 - before a node"<<endl;
                cout<<"1 - after a node"<<endl;
                int select_pos;
                cin>>select_pos;
                switch (select_pos)
                {
                case 0:{
                    int node_pos;
                    cout<<"enter the position of the node before which you want to add an element - ";
                    cin>>node_pos;
                    int value;
                    cout<<"enter the value to be stored - ";
                    cin>>value;
                    add_before(&head, value, node_pos);
                    break;
                }
                case 1:{
                    int node_pos;
                    cout<<"enter the position of the node after which you want to add an element - ";
                    cin>>node_pos;
                    int value;
                    cout<<"enter the value to be stored - ";
                    cin>>value;
                    add_after(&head, value, node_pos);
                    break;
                }
                default:
                    break;
                } 
            }
            default:
                break;
            }
            break;
        }
        case 2:
            cout<<"do you want to check the head or the tail or at certain position?"<<endl;
            cout<<"1 - head of the element"<<endl;
            cout<<"2 - tail of the element"<<endl;
            cout<<"3 - at a position"<<endl;
            int temp;
            cin>>temp;
            switch (temp)
            {
            case 1:
                top_front(&head);
                break;
            case 2:
                top_back(&head);
                break;
            case 3:
                int pos;
                cout<<"enter the position - "<<endl;
                cin>>pos;
                search_element_index(&head, pos);
                break;
            default:
                break;
            }
        case 3:{
            int count_ele = count_elements(&head);
            cout<<"the number of elements in the list = "<<count_ele+1<<endl;
            break;
        }
        case 4:
            cout<<"do you want to delete from the top or the bottom?"<<endl;
            cout<<"1 - top"<<endl;
            cout<<"2 - bottom"<<endl;
            temp;
            cin>>temp;
            switch (temp)
            {
            case 1:
                pop_front(&head);
                break;
            case 2:
                pop_back(&head);
                break;
            default:
                break;
            }
        default:
            break;
        }

        cout<<"do you want to continue?"<<endl;
        cout<<"'yes' - to continue"<<endl;
        cout<<"'no' - to end"<<endl;
        cin>>next_operation;
    }

    cout<<"thank you!!";


}