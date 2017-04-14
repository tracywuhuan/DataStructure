
#include "LinkList.h"

template<class T>  
LinkList<T>::LinkList()  
{  
    head = current = NULL;  
}

template<class T>  
LinkList<T>::LinkList(const LinkList<T> &aplist)  
{  
    deepCopy(aplist);  
}

template<class T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T> &rlist){
	if(rlist == this){
		return this;
	}
	Empty();
	deepCopy(rlist);
	return this;
}
template<class T>
void LinkList<T>::insert_head(const T &element){
	Node<T> *node = new Node<T>;
	node->data = element;
	node->next = head;
	head = node;
}
template<class T>
void LinkList<T>::insert_end(const T &element){
	Node<T> *node = new Node<T>;
	node->data = element;
	node->next = NULL;
	if(head == NULL){
		head = node;
		return;
	}
	Node<T> *temp;
	temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = node;
}

template<class T>
bool LinkList<T>::first(T &listEl){
	if(head == NULL){
		return false;
	}
	listEl = head->data;
	current = head;
	return true;
}
template<class T>
bool LinkList<T>::getNext(T &listEl){
	if(current ==NULL || current->next ==NULL)
		return false;
	else{
		listEl = current->next->data;
		current = current->next;
		return true;
	}
}
template<class T>
bool LinkList<T>::find(const T &element){
	Node<T> *temp = head;
	T item;
	if(!first(item)){
		return false;
	}
	while(getNext(item)){
		if(item == element){
			return true;
		}
	}
	return false;
}

template<class T>
bool LinkList<T>::retrieve(T &element){
	if(!find(element)){
		return false;
	}
	element = current->data;
	return true;
}

template<class T>  
bool LinkList<T>::replace(const T &newElement)  
{  
    if(current == NULL)  
        return false;  
    current->data = newElement;  
    return true;  
}  

template<class T>  
bool LinkList<T>::remove(T &element)  
{  
    if(head == NULL)  
        return false;
    Node<T> *temp = head;
    if(head->data == element){
    	element = head->data;
    	head = head->next;
    	delete temp;
    	return true;
    }
    while(temp->next!=NULL){
    	if(temp->next->data == element){
    		Node<T> *temp2 = temp->next;
    		element = temp2->data;
    		temp->next = temp2->next;
    		delete temp2;
    		return true;
    	}
    	temp = temp->next;
    }
    return false;  
}  
template<class T>
void LinkList<T>::deepCopy(const LinkList<T> &original)  
{  
    head = current = NULL;  
    if(original.head == NULL)  
        return;  
    Node<T> *copyptr = head = new Node<T>;  
    Node<T> *originalptr = original.head;  
    copyptr->data = originalptr->data;  
    if(originalptr == original.current)  
        current = copyptr;  
    while(originalptr->next  != NULL)  
    {  
        copyptr->next = new Node<T>;
        originalptr = originalptr->next;  
        copyptr = copyptr->next;  
        copyptr->data = originalptr->data;  
        if(originalptr == original.current)  
            current = copyptr;  
    }  
    copyptr->next = NULL;  
}

template<class T>
LinkList<T>::~LinkList(){
	Empty();
}

template<class T>
void LinkList<T>::Empty(){
	while(head!=NULL){
		current = head;
		head = head->next;
		delete current;
	}
	current = NULL;
}

template<class T>
bool LinkList<T>::isEmpty() const{
	return head == NULL;
}
