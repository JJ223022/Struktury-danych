#ifndef lista_dwukierunkowa
#define lista_dwukierunkowa
#include<iostream>
template <typename T>
class listaDwukierunkowa{
	private:
		struct Node{
			T dane;
			Node* prev;
			Node* next;
		};
		int counter = 0;
	public:
		Node* head = nullptr;
		Node* tail = nullptr;
		void addToStart(T value){
			Node* node = new Node();
			node->dane=value;
			node->prev=nullptr;
			node->next=head;
			if(head!=nullptr){
				head->prev = node;
			}
			head = node;
			if(counter == 0){
				tail = head;
			}
			counter++;
		}
		void addToEnd(T value){
			if(counter == 0){
				addToStart(value);
				return;
			}
			Node* node = new Node();
			tail->next = node;
			node->dane = value;
			node->prev = tail;
			node->next = nullptr;
			tail = node;
			counter++;
		}
		void addToSelect(T value, int index){
			if(index<0 || index>counter){
				std::cout<<"Index spoza zakresu"<<std::endl;
				return;
			}
			if(index==0){
				addToStart(value);
				return;
			}
			else if(index==counter){
				addToEnd(value);
				return;
			}
			Node* prevNode = head;
			for(int i = 0;i < index - 1;i++){
				prevNode = prevNode->next;
			}
			Node* nextNode = prevNode->next;
			Node* node =  new Node();
			node->dane = value;
			node->next = nextNode;
			node->prev = prevNode;
			prevNode->next = node;
			nextNode->prev = node;
			counter++;
		}
		void removeStart() {
			if (counter == 0) {
				std::cout << "Lista jest pusta" << std::endl;
				return;
			}
		

			Node* temp = head;
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			} else {
				tail = nullptr;
			}
			delete temp;
			counter--;
		}
		void removeEnd(){
			if(counter == 0){
				std::cout<<"Lista jest pusta"<<std::endl;
				return;
			}
			if(counter == 1){
				removeStart();
				return;
			}
			Node* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
			counter--;
		};
		void removeSelect(int index){
			if(index<0 || index>=counter){
				std::cout<<"Index spoza zakresu"<<std::endl;
				return;
			}
			if(counter == 0){
				std::cout<<"Lista jest pusta"<<std::endl;
				return;
			}
			if(counter == 1){
				removeStart();
				return;
			}
			else if(index == counter - 1){
				removeEnd();
				return;
			}
			Node* prevNode = head;
			for(int i = 0;i < index - 1;i++){
				prevNode = prevNode->next;
			}
			//ten usuwamy
			Node* node = prevNode->next;
			Node* nextNode = node->next;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			delete node;
			counter--;
		};
		int getSize(){
			return counter;
		}
		T getStart(){
			if(counter == 0){
				std::cout<<"Lista jest pusta"<<std::endl;
				return T();
			}
			return head->dane;
		}
		T getEnd(){
			if(counter == 0){
				std::cout<<"Lista jest pusta"<<std::endl;
				return T();
			}
			return tail->dane;
		}
		T getSelect(int index) {
			if (index < 0 || index >= counter) {
				std::cout << "Index spoza zakresu" << std::endl;
				return T();
			}
			if (index == 0) return getStart();
			if (index == counter - 1) return getEnd();
			Node* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			return temp->dane;
		}		
		T findVal(T Val){
			if(counter == 0){
				std::cout<<"Lista jest pusta"<<std::endl;
				return T();
			}
			Node* temp = head;
			int position = 0;
			while(temp->dane != Val){
				temp = temp->next;
				position++;
				if(!temp){
					std::cout<<"Nie ma tej wartości w liscie"<<std::endl;
					return T();
				}
			}
			return position;
		}
};

#endif