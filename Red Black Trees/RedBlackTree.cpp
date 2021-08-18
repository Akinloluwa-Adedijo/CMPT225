#include "RedBlackTree.h"

// RedBlackTree method implementations

template <class T>
RedBlackTree<T>::RedBlackTree()
{
	root = nullptr;
}


//destructor
 template <class T>
//Post: deletes dynamic memory allocated by the tree
RedBlackTree<T>::~RedBlackTree()
{
	clear(root);
	root = nullptr;
}


//Pre:
//Param: RedBlackTree reference parameter
//Post: deep copies its reference parameter
template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree& rbt)
{
	root = nullptr;
	copyRBT(rbt.root, root);
}

//Pre: 
//Post: deep copies its reference parameter into the calling object, returns a rference to 
//		calling object after deallocating any dynamic memory associated
//		with the original contents of the calling object
template <class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree& rbt)
{
	if (this != &rbt)
	{
		clear(root);
		copyRBT(rbt.root, root);
	}
	return *this;
}

//Pre:
//Param: single template parameter
//Post: return true if parameter is not present in the tree and is inserted and false otherwise
template <class T>
bool RedBlackTree<T>::insert(T value)
{
	if (find(value) == true)
	{
		return false;
	}
	else
	{
		NodeT<T>* temp = new NodeT<T>(value);
		root = insertBST(root, temp);
		rbtFixInsert(temp);
		return true;
	}
}

//Pre:
//Param: single template parameter
//Post: return true if paramater removed successfully from the tree and false if parameter is not present in the tree
template <class T>
bool RedBlackTree<T>::remove(T value)
{
	if (find(value) != true)
	{
		return false;
	}
	else
	{
		NodeT<T>* nd = findNode(value);
		deleteBST(nd);
		return true;
	}
}

//Pre:
//Param: single template parameter
//Post: return true if parameter is found in the tree, false otherwise
template <class T>
bool RedBlackTree<T>::search(T value) const
{
	return find(value);
}


//Pre:
//Param: first and second template parameters
//Post: returns a vector that contains all values between the two template parameters, both inclusive if they are in the tree
//		returns an empty vector if no such values exist in the tree.
//		order between the two template perameters is irrelevant
template <class T>
vector<T> RedBlackTree<T>::search(T start, T end)
{
	vector<T> result;
	if (end <= start)
	{
		T temp = start;
		start = end;
		end = temp;
	}

	NodeT<T>* nd = root;
	searchHelper(result, nd, start, end);
	return result;
}

//if the tree contains the values 3, 5, 9, 12, 17 then closestLess(10) returns 9, closestLess(17)
//returns 12 and closestLess(3) returns 3
//Pre: 
//Param: single template parameter
//Post: returns largest value less than the template parameter, returns template parameter if no such value exists
template <class T>
T RedBlackTree<T>::closestLess(T value) const
{
	vector<T> result = values();
	for (int i = (int)result.size() - 1; i >= 0 ; i--)
	{
		if (result[i] < value)
		{
			return result[i];
		}
	}
	return value;
}

//if the tree contains the values 3, 5, 9, 12, 17 then closestGreater(10) returns 12, closestGreater(17)
//returns 17 and closestGreater(3) returns 5
//Pre: 
//Param: single template parameter
//Post: returns smallest value greater than the template parameter, returns template parameter if no such value exists
template <class T>
T RedBlackTree<T>::closestGreater(T value) const
{
	vector<T> result = values();
	for (int i = 0; i < (int)result.size(); i++)
	{
		if (result[i] > value)
		{
			return result[i];
		}
	}
	return value;
}

//Pre:
//Post: returns a vector that contains all values in the tree in ascending order, if tree is empty vector should also be empty
template <class T>
vector<T> RedBlackTree<T>::values() const
{	
	NodeT<T>* nd = root;
	vector<T> result;
	if (nd != nullptr)
	{
		valuesHelper(result, nd);
	}
	return result;
}

//Pre:
//Post: returns the number of values stored in the tree 
template <class T>
int RedBlackTree<T>::size() const
{
	return sizeHelper(root);
}




//HELPER METHODS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void RedBlackTree<T>::copyRBT(NodeT<T>* original, NodeT<T>*& copy)
{
	if (original == NULL) {
		copy = NULL;
	}
	else
	{
		copy = new NodeT<T>(original->data);
		copy->isBlack = original->isBlack;
		copy->parent = original->parent;
		copyRBT(original->left, copy->left);
		copyRBT(original->right, copy->right);
	}
}

template <class T>
bool RedBlackTree<T>::empty() const
{
	return root == nullptr;
}

template <class T>
void RedBlackTree<T>::clear(NodeT<T>* nd)
{
	if (nd != nullptr)
	{
		clear(nd->left);
		clear(nd->right);
		delete nd;
	}
}

template <class T>
bool RedBlackTree<T>::find(T value) const
{
	NodeT<T>* p = root;
	while (p != nullptr)
	{
		if (value == p->data)
		{
			return true;
		}
		else if (value < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return false;
}

template <class T>
int RedBlackTree<T>::sizeHelper(NodeT<T>* nd) const
{
	if (nd == NULL)
	{
		return 0;
	}
	else
	{
		return sizeHelper(nd->left) + 1 + sizeHelper(nd->right);
	}
}


template <class T>
void RedBlackTree<T>::valuesHelper(vector<T>& res, NodeT<T>* nd) const
{
	if(nd != nullptr)
	{
		valuesHelper(res, nd->left);
		res.push_back(nd->data);
		valuesHelper(res, nd->right);
	}
}

template <class T>
void RedBlackTree<T>::searchHelper(vector<T>& res, NodeT<T>* nd, T start, T end)
{
	if (nd != nullptr)
	{
		searchHelper(res, nd->left, start, end);
		if (nd->data >= start && nd->data <= end)
		{
			res.push_back(nd->data);
		}
		searchHelper(res, nd->right, start, end);
	}
}

template <class T>
void RedBlackTree<T>::leftRotate( NodeT<T>* &nd)
{
	NodeT<T>* y = nd->right;
	nd->right = y->left;

	//setting the nodes parent references
	if (nd->right != nullptr)
	{
		nd->right->parent = nd;
	}
	y->parent = nd->parent;

	//setting the child refernces of nd's parent
	if (nd->parent == nullptr) //nd was root
	{
		root = y;
	}
	else if (nd == nd->parent->left)
	{
		nd->parent->left = y;
	}
	else
	{
		nd->parent->right = y;
	}

	//making nd y's left child
	y->left = nd;
	nd->parent = y;
}

template <class T>
void RedBlackTree<T>::rightRotate(NodeT<T>*& nd)
{
	NodeT<T>* y = nd->left;
	
	nd->left = y->right;

	//setting the nodes parent references
	if (nd->left != nullptr)
	{
		nd->left->parent = nd;
	}
	
	y->parent = nd->parent;

	//setting the child refernces of nd's parent
	if (nd->parent == nullptr) //nd was root
	{
		root = y;
	}
	else if (nd == nd->parent->left)
	{
		nd->parent->left = y;
	}
	else
	{
		nd->parent->right = y;
	}

	//making nd y's right child
	y->right = nd;
	nd->parent = y;
}

template <class T>
NodeT<T>* RedBlackTree<T>::insertBST(NodeT<T>*& root, NodeT<T>*& nd)
{
	//if the root is empty
	//set it to nd
	if(root == nullptr)
	{
		return nd;
	}

	//find the appropriate place to put the new node 
	//and assigning its parent pointer
	if (nd->data < root->data)
	{
		root->left = insertBST(root->left, nd);
		root->left->parent = root;
	}
	else
	{
		root->right = insertBST(root->right, nd);
		root->right->parent = root;
	}
	return root;
}

//helper function to fix red black tree violations
template <class T>
void RedBlackTree<T>::rbtFixInsert(NodeT<T>*& nd)
{
	NodeT<T>* parent_1 = nullptr;
	NodeT<T>* grandparent = nullptr;

	//iterate until the root or a black parent is reached
	while ( nd != root && nd->isBlack == false && nd->parent->isBlack == false)
	{
		parent_1 = nd->parent;
		grandparent = parent_1->parent;

		if (parent_1 == grandparent->left)
		{
			NodeT<T>* uncle = grandparent->right;	//uncle of nd

			//if the uncle is not null and the same colour as nd's parent 
			if (uncle != nullptr && uncle->isBlack == false)
			{
				uncle->isBlack = true;
				parent_1->isBlack = true;
				grandparent->isBlack = false;
				nd = grandparent;
			}
			else  //uncle.isBlack == black(true)
			{
				if (nd == parent_1->right)
				{
					leftRotate(parent_1);
					nd = parent_1;
					parent_1 = nd->parent;
				}
				rightRotate(grandparent);
				bool temp = parent_1->isBlack;
				parent_1->isBlack = grandparent->isBlack;
				grandparent->isBlack = temp;
				nd = parent_1;
			}
		}
		else
		{
			NodeT<T>* uncle = grandparent->left;  //uncle of nd

			//if the uncle is not null and the same colour as nd's parent 
			if (uncle != nullptr && uncle->isBlack == false)
			{
				uncle->isBlack = true;
				parent_1->isBlack = true;
				grandparent->isBlack = false;
				nd = grandparent;
			}
			else    //uncle.isBlack == black(true)
			{
				if (nd == parent_1->left)
				{
					rightRotate(parent_1);
					nd = parent_1;
					parent_1 = nd->parent;
				}
				leftRotate(grandparent);
				bool temp = parent_1->isBlack;
				parent_1->isBlack = grandparent->isBlack;
				grandparent->isBlack = temp;
				nd = parent_1;
			}
		}
	}
	root->isBlack = true;
}

template <class T>
void RedBlackTree<T>::fixDelete(NodeT<T>*& x)
{
	if (x == nullptr)
	{
		return;
	}

	if (x == root)
	{
		root = nullptr;
		return;
	}

	while (x != root && x->isBlack == true)
	{
		if (x == x->parent->left)  //x is left child
		{
			NodeT<T>* w = x->parent->right;  //x's sibling
			if (w->isBlack == false)
			{
				w->isBlack = true;
				x->parent->isBlack = false; //x's parent must have been black since w is red
				leftRotate(x->parent);
				w = x->parent->right;
			}

			if (w->left->isBlack == true && w->right->isBlack == true)
			{
				w->isBlack = false;
				x = x->parent;
			}
			else if (w->right->isBlack == true) //makes x's siblings right child red
			{
				w->left->isBlack = true;
				w->isBlack = false;
				rightRotate(w);
				w = x->parent->right;
			}
			else
			{
				w->isBlack = x->parent->isBlack;
				x->parent->isBlack = true;
				w->right->isBlack = true;
				leftRotate(x->parent);
				x = root;
			}
		}
		else
		{
			NodeT<T>* w = x->parent->left;
			if (w->isBlack == false)
			{
				w->isBlack = true;
				x->parent->isBlack = false;
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->isBlack == true && w->left->isBlack == true)
			{
				w->isBlack = false;
				x = x->parent;
			}
			else if (w->left->isBlack == true)
			{
				w->right->isBlack = true;
				w->isBlack = false;
				leftRotate(w);
				w = x->parent->left;
			}
			else
			{
				w->isBlack = x->parent->isBlack;
				x->parent->isBlack = true;
				w->left->isBlack = true;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->isBlack = true;
}

template <class T>
void RedBlackTree<T>::deleteBST(NodeT<T>*& nd)
{
	NodeT<T>* y = nd;
	bool y_colour = y->isBlack;

	NodeT<T>* x;

	//delete nd using binary search removal
	if (nd->left == nullptr)
	{
		x = nd->right;
		swap(nd, nd->right);
	}
	else if (nd->right == nullptr)
	{
		x = nd->left;
		swap(nd, nd->left);
	}
	else
	{
		y = successor(nd->right);
		y_colour = y->isBlack;
		x = y->right;

		if (x != nullptr && y->parent == nd)
		{
			x->parent = y;
		}
		else
		{
			swap(y, y->right);
			y->right = nd->right;
			if (y->right != nullptr)
			{
				y->right->parent = y;
			}
		}
		swap(nd, y);
		y->left = nd->left;
		y->left->parent = y;
		y->isBlack = nd->isBlack;
	}

	delete nd;
	if (y_colour == true)
	{
		fixDelete(x);
	}
}

template <class T>
void RedBlackTree<T>::swap(NodeT<T>*& x, NodeT<T>*& y)
{
	if (x->parent == nullptr)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	if (y && x) {
		y->parent = x->parent;
	}
}

template <class T>
NodeT<T>* RedBlackTree<T>::successor(NodeT<T>* nd)
{
	while (nd->left != nullptr)
	{
		nd = nd->left;
	}
	return nd;
}

template <class T>
NodeT<T>* RedBlackTree<T>::findNode(T value)
{
	NodeT<T>* p = root;
	while (p != nullptr)
	{
		if (value == p->data)
		{
			return p;
		}
		else if (value < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return p;
}