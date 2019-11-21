#include <iostream>
#include"BinaryTree.h"
#include"Header.h"
#include<string>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
	//Read in file	
	ifstream fin("morse.txt");
	//Some variables to save the read in file
	string code;
	vector<string> codes;
	vector<int> sizes; //Used to sort by size
	char codeChar;
	
	while (fin.good())
	{
		fin >> code;
		sizes.push_back(code.size());//Saving sizes to variable
		codes.push_back(code);		//Saves codes to vector
	}
	selection_sort(sizes, codes); //Sorts the sizes and codes just sort with it


	//Build root and Tree
	struct  node* root = newNode(' ', " ");
	for (int i = 0; i < codes.size(); i++)
	{
		
		code = codes[i];	//Takes first code from vector
		codeChar = code[0]; //Saves the character 
		deleteString(code); //delete the character, just need the code
		makingBT(root, code, codeChar, 0); //place the code in tree
	}

	
	
	
	//Display the tree
	/*cout << "This is the Binary Tree\n\n";
	displayBinaryTree(root);
*/



	//Coding the message
	vector<string> encodedMessage;
	vector<char> decodedMessage;

	//encode dog
	encodeString("dog", encodedMessage, root);
	displayMessage(encodedMessage);
	cout << endl << endl;

	//decode the morse code
	decodeString(encodedMessage, decodedMessage, root);
	displayUnMessage(decodedMessage);
	cout << endl << endl;

	//encode sos
	encodeString("sos", encodedMessage, root);
	displayMessage(encodedMessage);
	cout << endl << endl;

	//decode the message
	decodeString(encodedMessage, decodedMessage, root);
	displayUnMessage(decodedMessage);
	cout << endl << endl;

	return 0;
}