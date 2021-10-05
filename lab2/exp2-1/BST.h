#pragma once
// Include the node implementation
#include "BSTNode.h"

// Include the dictionary ADT
#include "dictionary.h"

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key, E> {
private:
	BSTNode<Key, E>* root;   // Root of the BST
	int nodecount;         // Number of nodes in the BST
	int leafcount=0;

						   // Private "helper" functions
	void clearhelp(BSTNode<Key, E>*);
	BSTNode<Key, E>* inserthelp(BSTNode<Key, E>*,
		const Key&, const E&);
	BSTNode<Key, E>* deletemin(BSTNode<Key, E>*);
	BSTNode<Key, E>* getmin(BSTNode<Key, E>*);
	BSTNode<Key, E>* removehelp(BSTNode<Key, E>*, const Key&);
	void Seqprint(BSTNode<Key, E>* root) const;
	E findhelp(BSTNode<Key, E>*, const Key&) const;
	void printhelp(BSTNode<Key, E>*, int) const;

public:
	BST() { root = NULL; nodecount = 0; }  // Constructor
	~BST() { clearhelp(root); }            // Destructor

	void preorder(BSTNode<Key, E>* root) const;
	void inorder(BSTNode<Key, E>* root) const;
	void postorder(BSTNode<Key, E>* root) const;
	void leafnumber(BSTNode<Key, E>* root);

	void clear()   // Reinitialize tree
	{
		clearhelp(root); root = NULL; nodecount = 0;
	}

	// Insert a record into the tree.
	// k Key value of the record.
	// e The record to insert.
	void insert(const Key& k, const E& e) {
		root = inserthelp(root, k, e);
		nodecount++;
	}

	// Remove a record from the tree.
	// k Key value of record to remove.
	// Return: The record removed, or NULL if there is none.
	E remove(const Key& k) {
		E temp = findhelp(root, k);   // First find it
		if (temp != NULL) {
			root = removehelp(root, k);
			nodecount--;
		}
		return temp;
	}
	// Remove and return the root node from the dictionary.
	// Return: The record removed, null if tree is empty.
	E removeAny() {  // Delete min value
		if (root != NULL) {
			E temp = root->element();
			root = removehelp(root, root->key());
			nodecount--;
			return temp;
		}
		else return NULL;
	}

	E find(const Key& k) const { return findhelp(root, k); }

	// Return the number of records in the dictionary.
	int size() { return nodecount; }

	void print() const { // Print the contents of the BST
		if (root == NULL) cout << "The BST is empty.\n";
		else {
			printhelp(root, 0);
			cout << "二叉检索树的顺序表示：";
			Seqprint(root);
			cout <<'\n'<< "前序遍历：" << endl;
			preorder(root);
			cout << '\n' << "中序遍历：" << endl;
			inorder(root);
			cout << '\n' << "后序遍历：" << endl;
			postorder(root);
			cout << "*中序遍历将结点按从小到大排列*"<<endl;
		}
	}
	void leaf() {
		leafnumber(root);
	}
	void leafnumber() {
		cout << "叶子结点的数目是：" << leafcount << endl;
	}
};

// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearhelp(BSTNode<Key, E>* root) {
	if (root == NULL) return;
	clearhelp(root->left());
	clearhelp(root->right());
	delete root;
}

// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
inserthelp(
	BSTNode<Key, E>* root, const Key& k, const E& it) {
	if (root == NULL)  // Empty tree: create node
		return new BSTNode<Key, E>(k, it, NULL, NULL);
	if (k < root->key())
		root->setLeft(inserthelp(root->left(), k, it));
	else root->setRight(inserthelp(root->right(), k, it));
	return root;       // Return tree with node inserted
}

// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getmin(BSTNode<Key, E>* rt) {
	if (rt->left() == NULL)
		return rt;
	else return getmin(rt->left());
}
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deletemin(BSTNode<Key, E>* rt) {
	if (rt->left() == NULL) // Found min
		return rt->right();
	else {                      // Continue left
		rt->setLeft(deletemin(rt->left()));
		return rt;
	}
}

// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
removehelp(BSTNode<Key, E>* rt, const Key& k) {
	if (rt == NULL) return NULL;    // k is not in tree
	else if (k < rt->key())
		rt->setLeft(removehelp(rt->left(), k));
	else if (k > rt->key())
		rt->setRight(removehelp(rt->right(), k));
	else {                            // Found: remove it
		BSTNode<Key, E>* temp = rt;
		if (rt->left() == NULL) {     // Only a right child
			rt = rt->right();         //  so point to right
			delete temp;
		}
		else if (rt->right() == NULL) { // Only a left child
			rt = rt->left();          //  so point to left
			delete temp;
		}
		else {                    // Both children are non-empty
			BSTNode<Key, E>* temp = getmin(rt->right());
			rt->setElement(temp->element());
			rt->setKey(temp->key());
			rt->setRight(deletemin(rt->right()));
			delete temp;
		}
	}
	return rt;
}

// Find a node with the given key value
template <typename Key, typename E>
E BST<Key, E>::findhelp(BSTNode<Key, E>* root,
	const Key& k) const {
	if (root == NULL) return NULL;          // Empty tree
	if (k < root->key())
		return findhelp(root->left(), k);   // Check left
	else if (k > root->key())
		return findhelp(root->right(), k);  // Check right
	else return root->element();  // Found it
}

//input the sequential representation of BST
template <typename Key, typename E>
void BST<Key, E>::
Seqprint(BSTNode<Key, E>* root) const {
	if (root == NULL) {
		cout << "/"; // Empty tree
		return;
	}
	else cout << root->key()<<" ";
	Seqprint(root->left()); // Do left subtree
	Seqprint(root->right());  // Do right subtree
}
//The preorder traversal of the tree
template<typename Key,typename E>
void BST<Key,E>::
preorder(BSTNode<Key,E>* root)const {
	if (root == NULL) return;
	cout << root->key() << " ";
	preorder(root->left());
	preorder(root->right());
}
//The inorder traversal of the tree
template<typename Key, typename E>
void BST<Key, E>::
inorder(BSTNode<Key, E>* root)const {
	if (root == NULL) return;
	inorder(root->left());
	cout << root->key() << " ";
	inorder(root->right());
}
//The inorder traversal of the tree
template<typename Key, typename E>
void BST<Key, E>::
postorder(BSTNode<Key, E>* root)const {
	if (root == NULL) return;
	postorder(root->left());
	postorder(root->right());
	cout << root->key() << " ";
}
//Print the leaf node's value and the number of the leave node
template <typename Key, typename E>
void BST<Key, E>::
leafnumber(BSTNode<Key, E>* root){
	if (root->left() == NULL && root->right()==NULL) {
		cout << root->key() << " ";
		leafcount++;
		return;
	}
	leafnumber(root->left()); // Do left subtree
	leafnumber(root->right());  // Do right subtree
}
// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::
printhelp(BSTNode<Key, E>* root, int level) const {
	if (root == NULL) return;           // Empty tree
	printhelp(root->left(), level + 1);   // Do left subtree
	for (int i = 0; i<level; i++)         // Indent to level
		cout << "  ";
	cout << root->key() << "\n";        // Print node value
	printhelp(root->right(), level + 1);  // Do right subtree
}