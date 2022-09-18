#include <bits/stdc++.h>
using namespace std;


class No_de{
    public:
    string m_name;
    int age;
    No_de*next;
    No_de*prev;
    No_de(string m_name,int age){
        this->m_name=m_name;
        this->age=age;
        next=NULL;
        prev=NULL;
    }
};


void append(No_de* &head,string m_name,int age){
    No_de*temp=head;
    No_de*new_node=new No_de(m_name,age);
    if(temp==NULL){
        head=new_node;
    }
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}


void insert_at_head(No_de*&head,string m_name,int age){
     No_de*new_node=new No_de(m_name,age);
     new_node->next=head;
     head->prev=new_node;
     head=new_node;
}


void display_start(No_de*head){
    No_de*temp=head;
    while(temp!=NULL){cout<<"[Name:"<<temp->m_name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;}
    cout<<endl;
}


void display_end(No_de*head){
    No_de*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->m_name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;}
    cout<<endl;
}

void delete_ind(No_de*&head,int i){
    if(i==0){
        No_de*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        No_de*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

void pop(No_de*&head){
    No_de*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    No_de*head=NULL;
    append(head,"MEMBER A",80);
    append(head,"MEMBER B",50);
    append(head,"MEMBER C",47);
    append(head,"MEMBER D",22);
    append(head,"MEMBER E",19);
    cout<<endl;

    cout<<"Doubly Linked list with family members:"<<endl;
    cout<<endl;
    display_start(head);
}
