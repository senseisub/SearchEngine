//
// Created by seuns on 11/12/2020.
//
#include "iostream"
using namespace std;
#ifndef SEARCHENGINETEMPLATES_AVLTREE_H
#define SEARCHENGINETEMPLATES_AVLTREE_H
template <typename t>
class AVLTree{
    private:
        class Node{
            public:
                t data;
                Node* left;
                Node* right;
                int height;
                Node(const t& data){
                    this->data = data;
                    height = 0;
                    left = nullptr;
                    right = nullptr;
                }
        };
        Node* root;
        int size;
        void emptyTree(Node*& currentNode){
            if(currentNode == nullptr){
                return;
            }
            emptyTree(currentNode->left);
            emptyTree(currentNode->right);
            if(currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                currentNode = nullptr;
            }
        }
        void insert(const t& data, Node*& node){
            if(node == nullptr) {
                node = new Node(data);
                this->size++;
            }
            else if(data < node->data){
                insert(data, node->left);
                if(height(node->left) - height(node->right)  > 1 || height(node->left) - height(node->right)  < -1){
                    if(data < node->left->data)
                        case1(node);
                    else
                        case2(node);
                }
            }
            else if(data > node->data){
                insert(data, node->right);
                if(height(node->right) - height(node->left)  > 1 || height(node->right) - height(node->left)  < -1){
                    if(data > node->right->data)
                        case4(node);
                    else
                        case3(node);
                }
            }
            else{
                return;
            }

            node->height = max(height(node->left), height(node->right))+1;
        }

        void inorder(Node*& node){
            if(node == nullptr){
                return;
            }
            inorder(node->left);
            cout << node->data << endl;
            inorder(node->right);
        }
    public:
        AVLTree(){
            root = nullptr;
            size = 0;
        }
        ~AVLTree(){

        }
        void emptyTree(){
            emptyTree(this->root);
        }

        // height of the tree
        int height(Node*& currentNode){
            if (currentNode == nullptr)
                return 0;
            return currentNode->height;
        }


        // A utility function to get maximum
        // of two integers
        int max(int a, int b){
            return (a > b)? a : b;
        }

        //left left rotation
        void case1(Node*& k2){
            Node* k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(height(k1->left), k2->height) + 1;

            k2 = k1;
        }

        //right right rotation
        void case4(Node*& k1){
            Node* k2 = k1->right;
            k1->right = k2->left;
            k2->left = k1;
            k1->height = max(height(k1->left), height(k1->right)) + 1;
            k2->height = max(height(k2->left), k1->height) + 1;

            k1 = k2;
        }

        //left right rotation
        void case2(Node*& k3){
            case4(k3->left);
            case1(k3);
        }

        //right left rotation
        void case3(Node*& k1){
            case1(k1->right);
            case4(k1);
        }


        void insert(const t& data){
            insert(data, this->root);
        }

        void inorder(){
            inorder(this->root);
        }

        int getSize(){
            return this->size;
        }

};
#endif //SEARCHENGINETEMPLATES_AVLTREE_H
