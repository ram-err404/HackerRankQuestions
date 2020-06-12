/*Quest: [Not much clear. :( ]
 * https://www.hackerrank.com/challenges/swap-nodes-algo/problem
 *
 * Ans: Working and passed all the test cases. */

#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    int depth;
    Node *left;
    Node *right;

    Node(int a, int b) {
      data=a;
      depth=b;
      left=nullptr;
      right=nullptr;
    }
};

void SwapNodesInOrder(Node *root, int k) {
  if(!root)
    return ;
  if (root->depth>=k && root->depth%k==0 ){
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
  }

  SwapNodesInOrder(root->left,k);
  SwapNodesInOrder(root->right,k);
}

void inOrderTraverseAndFormResultantVector(Node *root, vector<vector<int>> &res, int i) {
  if(!root)
    return;
  inOrderTraverseAndFormResultantVector(root->left, res, i);
  res[i].push_back(root->data);
  inOrderTraverseAndFormResultantVector(root->right, res, i);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
  /*
   * Write your code here.
   */
  Node *root = new Node(1,1);
  Node *cur = root;
  queue<Node*> q;
  q.push(cur);
  int i=0;

  /* Form your tree first. */
  while(!q.empty()) {
    cur = q.front();    q.pop();
    int leftNode = indexes[i][0];
    int rightNode = indexes[i][1];
    
    cur->left = (leftNode==-1 ? nullptr : new Node(leftNode, cur->depth+1));
    cur->right = (rightNode==-1 ? nullptr : new Node(rightNode, cur->depth+1));

    // Now we are going to add the nodes for next iteration to create node
    if(cur->left!=nullptr && cur->left->data!=-1)
      q.push(cur->left);
    if(cur->right!=nullptr && cur->right->data!=-1)
      q.push(cur->right);
    
    i++;
  }

  // traverse the tree and swap nodes, construct your resultant vector as well.
  vector<vector<int>> res(queries.size(), vector<int>());
  for(size_t i=0; i<queries.size(); i++) {
    SwapNodesInOrder(root, queries[i]);
    // Now construct you resultant vector by traversing tree in InOrder.
    inOrderTraverseAndFormResultantVector(root, res, i);
  }  
  return res;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> indexes(n);
  for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
    indexes[indexes_row_itr].resize(2);

    for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
      cin >> indexes[indexes_row_itr][indexes_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> queries(queries_count);

  for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
    int queries_item;
    cin >> queries_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    queries[queries_itr] = queries_item;
  }

  vector<vector<int>> result = swapNodes(indexes, queries);

  for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
    for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
      fout << result[result_row_itr][result_column_itr];

      if (result_column_itr != result[result_row_itr].size() - 1) {
        fout << " ";
      }
    }

    if (result_row_itr != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}
