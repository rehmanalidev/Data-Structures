// DSA Lab 2.cpp : This program is about linked list.
//This is a node class

#include <iostream>

using namespace std;

//Declaring a node class
class node {

	//Declaring private data members
	int value;
	node *nextNode;
	node *previousNode;
public:

	void setPreviousNode(node *pNode) {
		previousNode = pNode;
	}
	node * getPreviousNode() {
		return previousNode;
	}

	//declaring a function which sets the value in the node
	void setValue(int v) {
		value = v;
	}

	//Function used to move to next Node
	void setNextNode(node *nn) {
		nextNode = nn;
	}

	//Declared a function which returns the value stored in a node
	int getValue() {
		return value;
	}

	//Getting nextNode
	node *getNextNode() {
		return nextNode;
	}
};


//Declared class list in which we defined methods we want to implement on Link List
class list {

	//Pointer which has the address of top 
	node *headNode;

	//pointer which points to the current Node
	node *currentNode;
	

	//To keep record of size of Link List
	int size;

public:

	//Default Constructor which Sets all pointers to NULL and size to zero
	list() {
		headNode = NULL;
		currentNode = NULL;
		size = 0;
	}

	//Function to insert a new node in the link list
	void insert(int number) {
		if (currentNode != NULL)
		{
			if (currentNode->getNextNode() == 0) {
				node *temp = new node();
				currentNode->setNextNode(temp);
				temp->setPreviousNode(currentNode);
				currentNode = temp;
				currentNode->setValue(number);
				currentNode->setNextNode(0);
				size++;
			}
			else {
				node *temp = new node();
				temp->setNextNode(currentNode->getNextNode());
				temp->setPreviousNode(currentNode);
				(currentNode->getNextNode())->setPreviousNode(temp);
				currentNode->setNextNode(temp);currentNode = temp;
				currentNode->setValue(number);
				size++;
			}
		}
		else {
			node *temp = new node();
			headNode = temp;
			currentNode = headNode;
			temp->setPreviousNode(0);
			currentNode->setValue(number);
			currentNode->setNextNode(0);
			size++;
		}
	}

	//function to insert a value at certain index
	void insertByPosition(int value, int position) {
		start();
		if (position <= size) {
			for (int i = 0; i < position - 2; i++) {
				moveForward();
			}
			insert(value);
		}
		else {
			cout << "The position " << position << " is not available in Link list. Node is inserted at the end" << endl;
			insertAtEnd(value);
		}
	}

	
	void insertAfterValue(int value, int valueOfNodeAfter) {
		start();
		for(int i=0;i<size;i++) {
			if (currentNode->getValue() == valueOfNodeAfter) {
				insert(value);
				break;
			}
			moveForward();
		}
	}

	//Function to insert a new node at the start of Link List
	void insertAtBegin(int number) {

		start();
		if (headNode == NULL) {
			insertAtEnd(number);
		}
		else {
			node *temp = new node();
			temp->setNextNode(currentNode);
			headNode->setPreviousNode(temp);
			currentNode = temp;
			headNode = temp;
			currentNode->setValue(number);
			size++;
		}
	}
	
	/* Given a reference (pointer to pointer) to the head  
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node* new_node = new Node(); 
  
    Node *last = *head_ref; /* used in step 5*/
  
    /* 2. put in the data */
    new_node->data = new_data;  
  
    /* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/
    new_node->next = NULL;  
  
    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)  
        last = last->next;  
  
    /* 6. Change the next of last node */
    last->next = new_node;  
    return;  
}  

	//Function to insert a new node at the end of Link List
	void insertAtEnd(int number) {
		start();
		for (int i = 0; i < size; i++) {
			moveForward();
		}
		node *temp = new node();
		currentNode->setNextNode(temp);
		temp->setPreviousNode(currentNode);
		currentNode = temp;
		currentNode->setValue(number);
		currentNode->setNextNode(0);
		size++;
	}

	//Function to update value of a node by using index of that node
	void updateValueByIndex(int newValue, int index) {
		start();
		for (int i = 0; i < index - 1; i++) {
			moveForward();
		}
		currentNode->setValue(newValue);
	}

	//Function to update value of a node by using previous value of that node
	void updateValue(int newValue, int previousValue) {
		start();
		for (int i = 0; i < size; i++) {
			if (currentNode->getValue() == previousValue) {
				currentNode->setValue(newValue);
				break;
			}
			moveForward();
		}
	}

	//Function to get size of Link List
	int getSize() {
		return size;
	}

	//Function to get value of a specific node
	int get() {
		return currentNode->getValue();
	}

	

	//Function to move at the start of the Link List
	void start() {
		currentNode = headNode;
	}

	void end() {
		start();
		for (int i = 0; i < size; i++) {
			if (i < (size - 1)) {
				moveForward();
			}
		}
	}

	//Function to move to next Node
	void moveForward() {
		if (currentNode->getNextNode() != 0) {
			currentNode = currentNode->getNextNode();
		}
	}

	void moveBackward() {
		if (currentNode->getPreviousNode() != 0) {
			currentNode = currentNode->getPreviousNode();
		}
	}

	//Function to print all the Nodes in the Link List
	void print() {
		if (headNode == NULL) {
			cout << "/nLink List is empty/n";
		}
		else {
			start();
			for (int i = 0; i < size; i++) {
				cout << get() << " ";
				if (i < (size - 1)) {
					moveForward();
				}
			}
		}
	}

	void printBackward() {
		if (headNode == NULL) {
			cout << "/nLink List is empty/n";
		}else{
			start();
			end();
			for (int i = size; i > 0; i--) {
				cout << get() << " ";
				if (i >1) {
					moveBackward();
				}
			}
		}
	}

	//Function to delete a node from list

	void deleteNode(int valueOfNode) {

		start();

		for(int i=0; i<size; i++) {

			if (currentNode->getValue() == valueOfNode) {

				if (currentNode->getNextNode() != NULL) {

					if (currentNode == headNode) {

						if (size == 1) {
							headNode = NULL;
							delete currentNode;
							currentNode = headNode;
							headNode->setNextNode(0);
							headNode->setPreviousNode(0);
							break;
						}
						else {
							cout << "\nheadNode\n";
							headNode = currentNode->getNextNode();
							headNode->setPreviousNode(0);
							delete currentNode;
							currentNode = headNode;
							break;
						}
					}
					else {
						cout << "\n In the middle\n";
						node *ptr;
						ptr = currentNode;
						(currentNode->getPreviousNode())->setNextNode(currentNode->getNextNode());
						currentNode = currentNode->getPreviousNode();
						(currentNode->getNextNode())->setPreviousNode(currentNode);
						delete ptr;
						break;
					}
				}
				else {
					cout << "\nlastNode\n";
					node *ptr;
					ptr = currentNode;
					currentNode = currentNode->getPreviousNode();
					currentNode->setNextNode(0);
					delete ptr;
					break;
				}
			}
			
			moveForward();
		}
		size--;	
	}
	
	void deleteNodeByPosition(int index) {

		start();

		for (int i = 0; i < index - 1; i++) {
			moveForward();
		}
				if (currentNode->getNextNode() != NULL) {

					if (currentNode == headNode) {

						if (size == 1) {
							headNode = NULL;
							delete currentNode;
							currentNode = headNode;
							headNode->setNextNode(0);
							headNode->setPreviousNode(0);
						}
						else {
							cout << "\nheadNode\n";
							headNode = currentNode->getNextNode();
							headNode->setPreviousNode(0);
							delete currentNode;
							currentNode = headNode;
						}
					}
					else {
						cout << "\n In the middle\n";
						node *ptr;
						ptr = currentNode;
						(currentNode->getPreviousNode())->setNextNode(currentNode->getNextNode());
						currentNode = currentNode->getPreviousNode();
						(currentNode->getNextNode())->setPreviousNode(currentNode);
						delete ptr;
					}
				}
				else {
					cout << "\nlastNode\n";
					node *ptr;
					ptr = currentNode;
					currentNode = currentNode->getPreviousNode();
					currentNode->setNextNode(0);
					delete ptr;
				}
		
		size--;
	}
	//Printing the sum of all the values in linklist

	int sumValue() {
		int sum = 0;
		start();
		for (int i = 0; i < size; i++) {
			sum += currentNode->getValue();
			moveForward();
		}
		return sum;
	}

	//Searching a value if it is present in the list
	void searchValue(int value) {
		start();
		bool flag = false;
		int index=0;
		for (int i = 0; i < size; i++) {
			if (currentNode->getValue() == value) {
				flag = true;
				index = i;
			}
			moveForward();
		}
		if (flag == true) {
			cout << "The value is present in the link list at index " << index << endl;
		}
		else {
			cout << "The value is not present in the link list" << endl;
		}
	}

	void sorting() {
		start();
		if (size != 1) {
			for (int i = 0; i < size - 1; i++) {
				if (currentNode->getValue > (currentNode->getNextNode())->getValue()) {


				}
			}
		}
}

};



int main()
{
	//Declared an object of list type
	list linkList;

	//inserting nodes in the link list
	linkList.insert(60);
	linkList.insert(70);
	linkList.insert(80);
	linkList.insert(90);
	cout << "\nNow my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	cout << "\nPrinting the linkList Backword\n";
	linkList.printBackward();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 50 at the start of the Link List
	linkList.insertAtBegin(50);

	cout << "\nNow after adding 50 at the beginning my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 40 at the start of the Link List
	linkList.insertAtBegin(40);
	cout << "\nNow after adding 40 at the beginning my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 30 at the start of the Link List
	linkList.insertAtBegin(30);
	cout << "\nNow after adding 30 at the beginning my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 100 at the end of the Link List
	linkList.insertAtEnd(100);
	cout << "\nNow after adding 100 at the end my Link List is" << endl;
	linkList.print();
	linkList.insert(110);
	linkList.insert(120);
	linkList.insert(130);
	linkList.insert(140);
	linkList.insert(150);
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	cout << "\nPrinting the linkList Backword\n";
	linkList.printBackward();
	
	//Updated a node having value of 70 at the 5th index in the list by new value 71/*

	linkList.updateValueByIndex(71, 5);
	cout << "\nNow after Updating a node having value of 70 at the 5th index in the list by new value 71 my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	
	//Updating a node having previous value of 80 in the list by new value 81
	linkList.updateValue(81, 80);
	cout << "Now after Updating a node having previous value of 150 in the list by new value 151 my Link List is" << endl;
	linkList.print();

	//Deleting a node from link list
	cout << "\nList after deleting a node" << endl;
	linkList.deleteNode(100);

	linkList.print();
	
	//Deleting first node from list
	cout << "\n";
	linkList.deleteNode(30);
	linkList.print();
	
	//Calculating sum of all the Values present in link list
	cout << "\nSum of values present in the list is: " << linkList.sumValue() << endl;

	//Inserting a node at given position
	cout << "After inserting a node at given position" << endl;
	linkList.insertByPosition(41, 2);
	linkList.print();
//After inserting a node after given value  
	cout << "After inserting a node after given value" << endl;
	linkList.insertAfterValue(160, 150); 
	linkList.print();

	//Deleting a node from link list
	cout << "\nList after deleting a node" << endl;
	linkList.deleteNodeByPosition(1);

	linkList.print();

	system("pause");
}
