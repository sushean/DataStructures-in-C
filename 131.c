#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insertNode(struct node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
  } else {
    if (data < root->data) {
      insertNode(root->left, data);
    } else {
      insertNode(root->right, data);
    }
  }
}

void inorderTraversal(struct node *root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

void preorderTraversal(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void postorderTraversal(struct node *root) {
  if (root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}

struct node *searchNode(struct node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return searchNode(root->left, data);
  } else {
    return searchNode(root->right, data);
  }
}

void deleteNode(struct node *root, int data) {
  if (root == NULL) {
    return;
  } else if (data < root->data) {
    deleteNode(root->left, data);
  } else if (data > root->data) {
    deleteNode(root->right, data);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
    } else if (root->left == NULL) {
      struct node *temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      struct node *temp = root;
      root = root->left;
      free(temp);
    } else {
      struct node *minNode = root->right;
      while (minNode->left != NULL) {
        minNode = minNode->left;
      }
      root->data = minNode->data;
      deleteNode(root->right, minNode->data);
    }
  }
}

int main() {
  struct node *root = NULL;

  insertNode(root, 10);
  insertNode(root, 5);
  insertNode(root, 15);
  insertNode(root, 2);
  insertNode(root, 7);
  insertNode(root, 12);
  insertNode(root, 17);

  printf("Inorder traversal: ");
  inorderTraversal(root);
  printf("\nPreorder traversal: ");
  preorderTraversal(root);
  printf("\nPostorder traversal: ");
  postorderTraversal(root);
  printf("\n");

  struct node *foundNode = searchNode(root, 10);
  if (foundNode != NULL) {
    printf("Found node: %d\n", foundNode->data);
  } else {
    printf("Node not found\n");
  }

  deleteNode(root, 10);

  printf("Inorder traversal after deletion: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}