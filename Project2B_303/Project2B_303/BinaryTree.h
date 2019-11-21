#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct node
{
	char data;
	struct node* left;
	struct node* right;
	string code;
};

struct node* newNode(char Data, string Code)
{
	// Allocate memory for new node  
	
	struct node* node = new struct node;
	// Assign data to this node 
	node->data = Data;
	node->code = Code;
	// Initialize left and right children as NULL 
	node->left = NULL;
	node->right = NULL;
	return(node);
}