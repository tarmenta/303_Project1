#pragma once
#include<iostream>
#include"BinaryTree.h"
#include<string>
#include<vector>


using namespace std;


//void displayString(vector<string> codes)
//{
//	int size = codes.size();
//	for (int i = 0; i < size; i++)
//	{
//		cout << codes[i] << endl;
//	}
//}
void selection_sort(vector<int>& vec, vector<string>& codes)
{

	for (int fill = 0; fill < vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next < vec.size(); ++next) {
			if (vec[next] < vec[pos_min])
				pos_min = next;
		}

		if (vec[fill] != vec[pos_min]) { //make an exchange
			int temp = vec[pos_min];
			string temp1 = codes[pos_min];

			vec[pos_min] = vec[fill];
			codes[pos_min] = codes[fill];//having the code sort just follow along

			vec[fill] = temp;
			codes[fill] = temp1;
		}
	}
}

void deleteString(string& str)
{
	int size = str.size();
	for (int i = 0; i < (size - 1); i++)
	{
		str[i] = str[i + 1];//save over the the character
	}
	str.resize(size - 1);//resize the string so no duplicate
}
//
//void displayBinaryTree(node* root)
//{
//	
//
//	
//	cout << endl << root->data << endl;
//	if (!(root->left == NULL))
//	{
//		displayBinaryTree(root->left);
//	}
//	if (!(root->right == NULL))
//	{
//		displayBinaryTree(root->right);
//	}
//}
void makingBT(node* root, string code, char codeChar,int num)
{
	//Check the root left and right for null 
	if ((root->left == NULL) && (code[num] == '.'))
	{
		root->left = newNode(codeChar, code); //If null then put new node here
	}
	else if ((root->right == NULL) && (code[num] == '_'))
	{
		root->right = newNode(codeChar, code); //Same for right if null the save node here
	}
	else if ((root->left != NULL) && (code[num] == '.'))//checking for null and the recersive iteration of what side the tree is on
	{
		num++;//increase num 
		makingBT(root->left, code, codeChar, num);//recursive
	}
	else if ((root->right != NULL) && (code[num] == '_'))
	{
		num++;
		makingBT(root->right, code, codeChar, num);//recursive
	}
}


string searchTreeE(node* root, char letter)
{
	if (letter == root->data)
	{
		
		return root->code;
	}
	if(!(root->left == NULL))
	{
		
		if (searchTreeE(root->left, letter) == "")
		{
			
		}
		else
		{
			return searchTreeE(root->left, letter);
		}
	}
	if (!(root->right == NULL))
	{
		
		if (searchTreeE(root->right, letter) == "")
		{

		}
		else
		{
			return searchTreeE(root->right, letter);
		}
		
	}
	if (((root->left == NULL) && (root->right == NULL)) || (root->data != letter))
	{
		
		return "";
	}
}
void encodeString(string Message, vector<string>& endcodedMessage, node* root)
{
	int size = Message.size();

	for (int i = 0; i < size; i++)
	{
		endcodedMessage.push_back(searchTreeE(root,Message[i]));
	}
}

void displayMessage(vector<string> Message)
{
	int size = Message.size();
	for (int i = 0; i < size; i++)
	{
		cout << Message[i];
		if (i != size-1)
		{
			cout << " ";
		}
	}
}
void displayUnMessage(vector<char> Message)
{
	int size = Message.size();
	for (int i = 0; i < size; i++)
	{
		cout << Message[i];
		if (i != size - 1)
		{
			cout << " ";
		}
	}
}
char searchTreeD(node* root, string morse)
{

	if (morse == root->code)
	{

		return root->data;
	}
	if (!(root->left == NULL))
	{

		if (searchTreeD(root->left, morse) == '1')
		{

		}
		else
		{
			return searchTreeD(root->left, morse);
		}
	}
	if (!(root->right == NULL))
	{

		if (searchTreeD(root->right, morse) == '1')
		{

		}
		else
		{
			return searchTreeD(root->right, morse);
		}

	}
	if (((root->left == NULL) && (root->right == NULL)) || (root->code != morse))
	{

		return '1';
	}
}

void decodeString(vector<string> encodedMessage, vector<char>& decodedMessage, node* root)
{
	int size = encodedMessage.size();
	for (int i = 0; i < size; i++)
	{
		decodedMessage.push_back(searchTreeD(root,encodedMessage[i]));
	}
}