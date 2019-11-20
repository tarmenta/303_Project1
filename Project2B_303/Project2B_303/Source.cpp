#include <iostream>
#include"BinaryTree.h"
#include"Header.h"
#include<string>
#include<vector>

using namespace std;

int main()
{
	
	struct  node * root = newNode(' '," ");
	makeBinaryTree(root);

	//cout << "This is the Binary Tree";
	//displayBinaryTree(root);

	vector<string> encodedMessage;
	vector<char> decodedMessage;

	cout << endl << endl;
	encodeString("dog", encodedMessage, root);

	displayMessage(encodedMessage);
	cout << endl << endl;

	decodeString(encodedMessage, decodedMessage, root);

	displayUnMessage(decodedMessage);
	cout << endl << endl;


	return 0;
}