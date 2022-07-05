// avltreeDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "avltree.h"

using namespace std;

int main()
{
    int item;
    char choice;
    avlTree avl;
  
    while (1)
    {
        cout << "\n---------------------" << endl;
        cout << "AVL Tree Implementation" << endl;
        cout << "\n---------------------" << endl;
        cout << "A: Insert Element into the tree and show the balanced tree at each insertion" << endl;
        cout << "B: Display the balaned tree and show inorder traversal" << endl;
        cout << "C: Display the balanced tree and show preorder traversal" << endl;
        cout << "D: Display the balanced tree and show postorder traversal" << endl;
        cout << "E: Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'A':
            cout << "Enter value to be inserted: ";
            cin >> item;
            root = avl.insert(root, item);
if (root == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.display(root, 1);
            break;
        
        case 'B':
            if (root == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.display(root, 1);
            cout << "Inorder Traversal:" << endl;
            avl.inorder(root);
            cout << endl;
            break;
        case 'C':
            if (root == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.display(root, 1);
            cout << "Preorder Traversal:" << endl;
            avl.preorder(root);
            cout << endl;
            break;
        case 'D':
            if (root == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.display(root, 1);
            cout << "Postorder Traversal:" << endl;
            avl.postorder(root);
            cout << endl;
            break;
        case 'E':
            return false;
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }

    return 0;
}
