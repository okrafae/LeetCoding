//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
//User function Template for C++

/* Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    
    int ans=0;
    
    bool func(Node *root){
        if(root->left==NULL && root->right==NULL){
            ans++;
            return true;
        }
        
        // Now we have to see the values
        int ans1=1,ans2=1;
        if(root->left!=NULL){
            ans1&=func(root->left);
            if(root->left->data!=root->data)ans2=0;
        }
        if(root->right!=NULL){
            ans1&=func(root->right);
            if(root->right->data!=root->data)ans2=0;
        }
        
        if(ans1 && ans2)ans++;
        return ans1 && ans2;
    }
    
    int singlevalued(Node *root)
    {
        //code here
        if(root==NULL)return 0;
        func(root);
        return ans;
    }
    
};


//{ Driver Code Starts.

int main()
{

	int t;
	cin >> t;
	getchar();
	while (t--)
	{

		string inp;
		getline(cin, inp);

        Solution ob;
        
		struct Node* root = buildTree(inp);
		cout << ob.singlevalued(root) << "\n";

	}
	return 0;
}

// } Driver Code Ends