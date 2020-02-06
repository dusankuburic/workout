#include<iostream>


struct Node
{
	int data;
	Node* left;
	Node* right;
};



inline void
push_node(Node* leaf, int inf)
{

	if (leaf->data > inf)
	{
		if (leaf->left != nullptr)
		{
			push_node(leaf->left, inf);
		}
		else
		{
			leaf->left = new Node;
			leaf->left->data = inf;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (inf >= leaf->data)
	{
		if (leaf->right != nullptr)
		{
			push_node(leaf->right, inf);
		}
		else
		{
			leaf->right = new Node;
			leaf->right->data = inf;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}


inline void
print_preorder(Node* leaf)
{
	if (leaf != nullptr)
	{
		std::cout << leaf->data << ' ';
		print_preorder(leaf->left);
		print_preorder(leaf->right);
	}
}

inline void
print_inorder(Node* leaf)
{
	if (leaf != nullptr)
	{
		print_inorder(leaf->left);
		std::cout << leaf->data << ' ';
		print_inorder(leaf->right);
	}
}


inline void
print_postorder(Node* leaf)
{
	if (leaf != nullptr)
	{
		print_postorder(leaf->left);
		print_postorder(leaf->right);
		std::cout << leaf->data << ' ';
	}
}



int main()
{

	Node* root = new Node();
	root->data = 99;

	push_node(root, 12);
	push_node(root, 33);
	push_node(root, 31);
	push_node(root, 8);


	std::cout << "PREORDER\n";
	print_preorder(root);
	std::cout << '\n';


	std::cout << "INORDER\n";
	print_inorder(root);
	std::cout << '\n';


	std::cout << "POSTORDER\n";
	print_postorder(root);
	std::cout << '\n';
	
	return 0;
}