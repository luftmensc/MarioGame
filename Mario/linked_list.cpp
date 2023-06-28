#include "linked_list.h"


turtle_node::turtle_node() {
	
}
turtle_node* turtle_node::getnext() {
	return this->next;
}

void turtle_node::setnext(turtle_node* ptr) {
	this->next = ptr;
}
void turtle_node::setturtle(turtle* turtle) {
	this->turtle_ptr = *turtle;

}

turtle turtle_node::getturtle() {
	
	return this->turtle_ptr;
}

turtle_node* turtle_LList::gethead(void) {
	return this->head;


}

void turtle_LList::sethead(turtle_node* head) {
	this->head = head;
}

turtle_LList::turtle_LList() {
	this->head = nullptr;

}

void turtle_LList::insert(turtle* turtle) {
	
	turtle_node* ptr = new turtle_node;
	ptr->setturtle(turtle);
	ptr->setnext(head);
	this->head = ptr;
	

	



}

turtle turtle_LList::traverse() {
	turtle_node* temp = this->head;
	return temp->getturtle();

}

