#include "turtle.h"

class turtle_node {
	turtle turtle_ptr;
	turtle_node* next;
	
public:
	
	turtle_node* getnext();
	turtle getturtle();
	void setnext(turtle_node*);
	void setturtle(turtle*);
	turtle_node();

};
class turtle_LList {
	
	turtle_node* head;
public:
	turtle_LList();
	turtle_node* gethead(void);
	void sethead(turtle_node*);
	void insert(turtle*);
	turtle traverse();
};