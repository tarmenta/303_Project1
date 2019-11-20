#pragma once
#include<iostream>
#include"BinaryTree.h"
#include<string>
#include<vector>


using namespace std;

void displayBinaryTree(node* root)
{
	//cout << "\nThis is the Binary Tree\n";

	
	cout << endl << root->data << endl;
	if (!(root->left == NULL))
	{
		displayBinaryTree(root->left);
	}
	if (!(root->right == NULL))
	{
		displayBinaryTree(root->right);
	}
}

void makeBinaryTree(node* root)
{
	root->left = newNode('e',"*");
	root->right = newNode('t',"-");
	root->left->left = newNode('i',"**");
	root->left->left->left = newNode('s',"***");
	root->left->left->left->left = newNode('h',"****");
	root->left->right = newNode('a',"*-");
	root->left->right->left = newNode('r',"*-*");
	root->left->right->right = newNode('w',"*--");
	root->left->right->right->left = newNode('p',"*--*");
	root->left->right->right->right = newNode('j',"*---");
	root->left->right->left->left = newNode('l',"*-**");
	root->left->left->right = newNode('u',"**-");
	root->left->left->right->left = newNode('f',"**-*");
	root->left->left->left->right = newNode('v',"***-");
	root->right->right = newNode('m',"--");
	root->right->right->right = newNode('o',"---");
	root->right->right->left = newNode('g',"--*");
	root->right->right->left->right = newNode('q',"--*-");
	root->right->right->left->left = newNode('z',"--**");
	root->right->left = newNode('n',"-*");
	root->right->left->right = newNode('k',"-*-");
	root->right->left->right->right = newNode('y',"-*--");
	root->right->left->right->left = newNode('c',"-*-*");
	root->right->left->left = newNode('d',"-**");
	root->right->left->left->right = newNode('x',"-**-");
	root->right->left->left->left = newNode('b',"-***");
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
			cout << "/";
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
			cout << "/";
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