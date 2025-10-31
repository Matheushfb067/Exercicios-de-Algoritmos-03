#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

void insert(node * & curr, int data){
    if(curr == NULL){
        curr = new node();
        curr -> data = data;
        curr -> left = NULL;
        curr -> right = NULL;
    }else if(data < curr -> data){
        insert(curr -> left, data);
    }else{
        insert(curr -> right, data);
    }
}

node *search(node *curr, int data){
    if(curr == NULL){
        return NULL;
    }else if(data < curr -> data){
        return curr;
    }else if(data < curr -> data){
        return search(curr -> left, data);
    }else{
        return search(curr -> right, data);
    }
}

int main(){
    //Representação da arvore
    //Arvore iniciando da raiz
    node *root = NULL; //referencia para arvore = mesmo tipo do nó

    insert(root, 37);
    insert(root, 42);
    insert(root, 23);
    insert(root, 33);

    node * result = search(root, 33);
    if(result != NULL){
        cout << result -> data;
    }else{
        cout << "So such element found " << endl;
    }

    return 0;
}