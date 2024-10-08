/***********************************************

  COMSC 210 | Lab 19 | Skylar Robinson | IDE Used: Eclipse

***********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

struct Review {
	double rating;
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
void getReview(Node *&, string); //Gets a review, returns true if the user wants to enter another review
void dispList(Node *); //displays all reviews
double calcAvg(Node *); //calculates the average rating of a list
void dispMovie(Movie); //displays a movie item

int main(){
	srand(time(0));
	vector<Movie> movies;

	//open input file
	ifstream in;
	in.open("reviews.txt");
	if (!in){
		cout << "File open error.\n";
		return -1;
	}

	//populate movie items
	while (!in.eof()) {
		Movie temp;
		getline(in, temp.name);
		temp.reviews = nullptr;
		string comment;
		getline(in, comment);
		while (comment != ""){
			getReview(temp.reviews, comment);
			getline(in, comment);
		}
		movies.push_back(temp);
	}

	//close input file
	in.close();

	//display movies
	for (Movie m : movies){
		dispMovie(m);
	}

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

void getReview(Node *&hd, string r) {
	//get the review
	Review temp;
	temp.rating = (rand() % 51) / 10.0;
	temp.comment = r;
	//add the review to the list
	addToHead(hd, temp);
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

double calcAvg(Node * hd) {
	Node * current = hd;
	int count = 0;
	double sum = 0;
	while (current) {
		count++;
		sum = sum + current->value.rating;
		current = current->next;
	}
	return sum / count;
}

void dispMovie(Movie m) {
	cout << "Title: " << m.name << endl;
	cout << "Reviews:\n";
	dispList(m.reviews);
	cout << "\tAverage: " << calcAvg(m.reviews) << "\n\n";
}
