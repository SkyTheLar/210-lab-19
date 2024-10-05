/***********************************************

  COMSC 210 | Lab 19 | Skylar Robinson | IDE Used: Eclipse

***********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Review {
	float rating;
	string comment;
};

struct Node {
	Review value;
	Node * next;
};

struct Movie {
	string name;
	Node * reviews;
};

void addToHead(Node *&, Review); //Add a node to the head of a list
bool getReview(Node *&); //Gets a review, returns true if the user wants to enter another review
void dispList(Node *); //displays all reviews
float calcAvg(Node *); //calculates the average rating of a list

int main(){
	vector<Movie> movies;

	//populate four movie items
	for (int i; i < 4; i++){
		Node * head = nullptr;




	while (getReview(head));
	}

	cout << "Outputting all reviews:\n";
	dispList(head);

	cout << "\tAverage: " << calcAvg(head);

	return 0;
}

void addToHead(Node *&hd, Review v) {
	Node *newVal = new Node;
	newVal->value = v;
		if (!hd) { // if this is the first node, it's the new head
		    newVal->next = nullptr;
		}
		else { // its a second or subsequent node; place at the head
		    newVal->next = hd;
		}
	hd = newVal;
}

bool getReview(Node *&hd) {
	//get the review
	Review temp;
	cout << "Enter review rating 0-5: ";
	cin >> temp.rating;
	cin.ignore();
	cout << "Enter review comments: ";
	getline(cin, temp.comment);
	//add the review to the list
	addToHead(hd, temp);
	//new review or not
	char inp;
	cout << "Enter another review? y/n: ";
	cin >> inp;
	if (inp=='y')
		return true;
	else
		return false;
}

void dispList(Node * hd) {
	Node * current = hd;
	int count = 1;
	while (current) {
		cout << "\t[" << count++ << "] " << current->value.rating << ": "
			 << current->value.comment << endl;
		current = current->next;
	}
}

float calcAvg(Node * hd) {
	Node * current = hd;
	int count = 0;
	float sum = 0;
	while (current) {
		count++;
		sum = sum + current->value.rating;
		current = current->next;
	}
	return sum / count;
}
