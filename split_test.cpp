#include "split.cpp"
#include <vector>
#include <iostream>

using namespace std;

const vector<vector<int>> tests = {
	{1,3,5,7,9},
	{4,5,6,7,8},
	{1,1,1,1,1},
	{2,2,2,2,2},
	{-5,-4,-3,-2,-1},
	{1},
	{}
};

vector<Node*> testNodes = {};

Node* testToNodes(vector<int> test, int index = 0) {
	if ( index == (int)(test.size()) ) {
		return NULL;
	} else {
		return new Node(test[index], testToNodes(test, index + 1));
	}
}

void printNodes(Node* at) {
	if (at != NULL) {
		cout << at->value << ' ';
		if (at->next != NULL) {
			printNodes(at->next);
		}
	}
}

int main() {
	for (vector<int> test : tests) {
		testNodes.push_back(testToNodes(test));
	}
	
	for (vector<Node*>::iterator head = testNodes.begin(); head != testNodes.end(); ++head) {
		printNodes(*head);
		cout << endl;
		Node* odds = NULL;
		Node* evens = NULL;
		split(*head, odds, evens);
		printNodes(odds);
		cout << endl;
		printNodes(evens);
		cout << endl << endl;
	}

	return 0;
}