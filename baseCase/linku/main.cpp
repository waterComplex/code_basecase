#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

class Linked_list{
	Node* head;
	public:
	Linked_list(){
		head = NULL;
	}
	int size(){
		// cout<<"1666"<<endl;
		if(head == NULL){
			return 0;
		}else{
		// cout<<"1"<<endl;
			int s{};
			Node* c = head;
			while(c != NULL){
				c = c->next;
				s++;
			}
			return s;
		}
	}
	void push_head(int val) {
		Node * c = new Node;
		c->data = val;
		c->next = head;
		head = c;
		// cout<<head->data<<endl;
	}
	void push_end(int val) {
		Node * c = new Node;
		c->data = val;
		if(size() == 0){
			head = c;
			c->next = NULL;
		}else{
			Node *t = head;
			while(t->next != NULL) {
				t = t->next;
			}
			t->next = c;
			c->next = NULL;
		}
	}

	void push_at(int i,int val) {
		Node * c = new Node;
		c->data = val;
		if( i < 0 || i > size()){
			cout << "can't add to this index" << endl;
		}else if(i == 0){
			push_head(val);
		}else if (i == size()) {
			push_end(val);
		}else{
			Node * t = head;
			for(int a{}; a < i-1; a++) {
				t = t->next;
			}
			c->next = t->next;
			t->next = c;
		}
	}
	int remove_head(){
				cout<<"size: "<<size()<<endl;

		if(head == NULL){
			cout<<"Linked list is empty "<<endl;
			return -1;
		} else{
			Node * t = head;
			head = head->next;
			int a = t->data;
			delete t;
			return a;
		}
	}
	int remove_end(){
		cout<<"size: "<<size()<<endl;
		if(head == NULL){
			cout<<"Linked list is empty can't remove end"<<endl;
			return -1;
		}else{
			Node * t = head;
			Node *p = NULL;
			while(t->next != NULL) {
				p = t;
				t = t->next;
			}
			if(t == head) {
				head = NULL;
			}else{
				p->next = NULL;
			}
			
		// cout<<(head->next)->data<<endl;
			int a = t->data;
			delete t;
			return a;
		}
	}
	int remove_at(int i){
		if(size() == 0){
			cout<<"Linked list is empty can't remove anything"<<endl;
			return -1;
		}else if(i < 0 || i > size() - 1){
			cout<<"invalid index can't remove "<<endl;
			return -1;
		}else{
			Node * t = head;
			Node *p = NULL;
			for(int a{}; a < i; a++) {
				p = t;
				t = t->next;
			}
			if(t == head) {
				head = head->next;
			}else{
				p->next = t->next;
			}
			// cout<<"head"<<head->data<<endl;
			int a = t->data;
			delete t;
			return a;;
		}
		
		
	}
	void display(){
		if(size() == 0) {
			cout<<"Linked is empty nothing to display"<<endl;
		}else{
			Node * t = head;
			cout<<"List - ";
			while(t != NULL){
				cout << t->data <<" " ;
				t = t->next;
			}
			cout<<endl;
		}
	}

};
int main() {
	Linked_list a{};
	// a.push_head(5);
	// // a.remove_head();
	// a.push_head(6);
	// a.push_head(53);
	// a.push_head(888888888);
	// a.display();
	// a.push_head(4);
	// a.push_head(8);
	// a.push_head(6);
	// a.display();
	// a.push_end(1);
	// a.display();
	// a.push_end(2);
	// a.push_end(3);
	// a.display();
	// a.push_end(4);
	// a.push_end(5);
	// a.display();
	// a.push_end(6);
	// a.push_end(7);
	a.push_at(0,7);
	a.push_at(1,5);
	a.display();
	cout<<a.remove_at(0)<<endl;
	a.push_at(1,6);
	a.display();
	a.push_at(2,5);
	cout<<a.remove_at(1)<<endl;
	a.push_at(2,45);
	cout<<a.remove_at(2)<<endl;
	a.display();
	a.push_at(1,6);
	a.push_at(1,6);
	a.push_at(4,0);
	a.display();
	a.push_at(1,67);
	cout<<a.remove_at(4)<<endl;
	a.display();
	a.push_at(1,647);
	a.push_at(1,9890890);
	a.display();

	cout<<"---------------------------------------------"<<endl;
	// cout<<a.remove_end()<<endl;
	// cout<<a.remove_end()<<endl;
	// cout<<a.remove_end()<<endl;
	// cout<<a.remove_end()<<endl;
	// cout<<a.remove_end()<<endl;
	// a.display();
	// cout<<a.remove_at(1)<<endl;
	// // a.display();
	// cout<<a.remove_at(6)<<endl;
	// cout<<a.remove_at(3)<<endl;
	// // a.display();
	// cout<<a.remove_at(3)<<endl;
	// cout<<a.remove_head()<<endl;
	// cout<<a.remove_head()<<endl;
	// cout<<a.remove_head()<<endl;
	// cout<<a.remove_head()<<endl;
	// cout<<a.remove_head()<<endl;
}