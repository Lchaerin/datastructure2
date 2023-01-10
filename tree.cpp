#include "tree.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
  if (start > end)
    return -1;

  string s;

  for (int i = start; i <= end; i++) {

    // if open parenthesis, push it
    if (str[i] == '(')
      s.push_back(str[i]);

    // if close parenthesis
    else if (str[i] == ')') {
      if (s.back() == '(') {
        s.pop_back();

        if (!s.length())
          return i;
      }
    }
  }
  // if not found return -1
  return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {
  if (start > end)
    return NULL;

  Node *root = new Node(data[start]);
  int index = -1;

  if (start + 1 <= end && data[start + 1] == '(')
    index = findIndex(data, start + 1, end);

  if (index != -1) {
    root->left = _buildFromString(data, start + 2, index - 1);
    root->right = _buildFromString(data, index + 2, end - 1);
  }
  return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
  Node *root = _buildFromString(data, 0, strlen(data) - 1);
  _root = root;
}

string output="";
int depth_cnt=0;
int tree_depth=0;
int result=-1;
void preorder(Node *node) {
    if(output==""){
    output= node->value;}
    else{
      output=output+" "+node->value;
    }
    if(node->left!=NULL){
      //cout<<node->value<<"'s left value is "<<node->left->value<<endl;
      preorder(node->left);
      }
    if (node->right != NULL){
      //cout<<node->value<<"'s right value is "<<node->left->value<<endl;
      preorder(node->right);
    }
}


void inorder(Node *node) {
  if(node->left!=NULL)
        inorder(node->left);
    if(output==""){
    output= node->value;}
    else{
      output=output+" "+node->value;
    }
    if (node->right != NULL)
        inorder(node->right);
    
}

void postorder(Node *node) {
  if(node->left!=NULL)
        postorder(node->left);
    if (node->right != NULL)
        postorder(node->right);
    if(output==""){
    output= node->value;}
    else{
      output=output+" "+node->value;
    }
    
}
bool met=false;
bool met_4_real=false;
int height=0;
int max_height=0;
void checking_nodes(Node *node, int node_value){
  int temp=node->value-48;
  if(temp==node_value){//으아아아 이부분 고쳐야함
    result=depth_cnt; 
    met=true;
    met_4_real=true;
    ////cout<<"value: "<<node->value<<" input: "<<node_value<<"->일치"<<endl;
  }
  else{
    ////cout<<"value: "<<node->value<<" input: "<<node_value<<"->불일치"<<endl;
  }
  
    if(node->left!=NULL){
      depth_cnt++;
      if(met){
        height++;
        height>=max_height?max_height=height:max_height=max_height;
      }
      checking_nodes(node->left, node_value);
      }
    if(node->right != NULL){
      depth_cnt++;
      checking_nodes(node->right, node_value);
      if(met){
        height++;
        height>=max_height?max_height=height:max_height=max_height;
      }
    }
    met?height--:height=height;
    depth_cnt--;
    if(temp==node_value){
      met=false;
    }
}

int depth_cnt2=0;
int tree_depth2=0;
int node_cnt2=0;
bool ZeroOrTwo= true;
bool cmpOrNot=true;
void check_proper(Node *node){
  if(node->left!=NULL){
    //cout<<"value "<<node->value<<"'s left exists"<<endl;
    check_proper(node->left);
    }
  if(node->right != NULL){
    //cout<<"value "<<node->value<<"'s right exists"<<endl;
    check_proper(node->right);
    }
  if((node->right!=NULL&&node->left==NULL)||(node->right==NULL&&node->left!=NULL)){
    ZeroOrTwo = false;
    //cout<<"not proper"<<endl;
    }
}
int depth_cnt3=0;
int tree_depth3=0;
void check_depth(Node *node){
    if(node->left!=NULL){
      depth_cnt3++;
      depth_cnt3>=tree_depth3?tree_depth3=depth_cnt3:tree_depth3=tree_depth3;
      check_depth(node->left);
      }
    if(node->right != NULL){
      depth_cnt3++;
      depth_cnt3>=tree_depth3?tree_depth3=depth_cnt3:tree_depth3=tree_depth3;
      check_depth(node->right);
    }
    depth_cnt3--;
}
int depth_cnt4=0;
bool complete=true;
bool checking_cplt=true;
void check_complete(Node *node, int dpt){
  if(node->left!=NULL){
      depth_cnt4++;
      check_complete(node->left,dpt);
      }
    if(node->right != NULL){
      depth_cnt4++;
      check_complete(node->right,dpt);
    }
    if(depth_cnt4==dpt-1){
      //cout<<node->value<<endl;
    if(node->right!=NULL&&node->left==NULL){
    complete = false;
    }
    if(node->right==NULL&&node->left!=NULL){
    checking_cplt == false?complete=false:checking_cplt = false;
    }
    else if(node->right==NULL&&node->left==NULL){
    checking_cplt = false;
    }
    if(node->right!=NULL&&node->left!=NULL){
      checking_cplt==false?complete=false:complete=complete;
    }
    }
    depth_cnt4--;
    
}


void check_full(Node *node){
  node_cnt2++;
  if(node->left!=NULL){
      depth_cnt2++;
      depth_cnt2>=tree_depth2?tree_depth2=depth_cnt2:tree_depth2=tree_depth2;
      check_full(node->left);
      }
    if(node->right != NULL){
      depth_cnt2++;
      depth_cnt2>=tree_depth2?tree_depth2=depth_cnt2:tree_depth2=tree_depth2;
      check_full(node->right);
    }
    depth_cnt2--;
}

string BinaryTree::getDepthHeight(int node_value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node* root=_root;
  checking_nodes(root, node_value);
  string answer="";
  if(met_4_real){
    answer = to_string(result)+" "+to_string(max_height);
  }
  else{
    answer="error";
  }
  
  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::preOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  
  Node* root=_root;
  preorder(root);
  return output;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::postOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  
  Node* root=_root;
  postorder(root);
  return output;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::inOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  Node* root=_root;
  inorder(root);
  return output;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::isProper() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node* root=_root;
  //cout<<"isProper까진 왔어용"<<endl;
  check_proper(root);
  //cout<<"check_proper 돌아갔어용"<<endl;
  if(ZeroOrTwo){
    return "True";
  }
  else{
    return "False";
  }

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::isFull() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node* root=_root;
  //cout<<"isFull까진 왔어용"<<endl;
  check_full(root);
  //cout<<"check_full 돌아갔어용"<<endl;
  //cout<<"tree_depth: "<<tree_depth2<<" node 개수: "<<node_cnt2<<endl;
  if((int)(pow(2,tree_depth2+1))-1==node_cnt2){
    return "True";
  }
  else{
    return "False";
  }
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::isComplete() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node* root=_root;
  //cout<<"isComplete까진 왔어용"<<endl;
  tree_depth3=0;
  check_depth(root);
  check_complete(root, tree_depth3);
  //cout<<"check_complete 돌아갔어용"<<endl;
  //cout<<"tree_depth: "<<tree_depth3<<endl;
  if(complete){
    return "True";
  }
  else{
    return "False";
  }

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}
