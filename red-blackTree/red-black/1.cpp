#include <iostream>
#include <vector>

using namespace std;

const int RED = 1;
const int BLACK = 0;
class RBNode {
public:
    int val;
    int color;
    RBNode *left;
    RBNode *right;
    RBNode *parent;
    RBNode() {
        val = -1;
        color = -1;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    void setVal(int val) {
        val = val;
    }

    void setColor(int color) {
        color = color;
    }
};

RBNode *root;

void leftRotate(RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRoate(RBNode *y) {
    RBNode *x = y->left;
    y->left = x->right;
    if (x->right) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nullptr) {
        root = x;
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void insertFixUp(RBNode *z) {
    RBNode *par, *gParent;
    while(z->parent != NULL && z->parent->color == RED) {
        par = z->parent;
        gParent = par->parent;
        if (par == gParent->left) {
            RBNode *uncle = gParent->right;
            if (uncle->color == RED) {
                par->color = BLACK;
                uncle->color = BLACK;
                gParent->color = RED;
                z = gParent;
                continue;
            }
            else if (z == par->right){
                leftRotate(par);
                RBNode *tmp = par;
                par = z;
                z = tmp;
            }
            par->color = BLACK;
            gParent->color = RED;
            rightRoate(gParent);
        }
        else {
            RBNode *uncle = gParent->left;
            if (uncle->color == RED) {
                par->color = BLACK;
                uncle->color = BLACK;
                gParent->color = RED;
                z = gParent;
                continue;
            }
            else if (z == par->left) {
                rightRoate(par);
                RBNode* tmp = par;
                par = z;
                z = par;
            }
            par->color = BLACK;
            gParent->color = RED;
            leftRotate(gParent);
        }
        root->color = BLACK;
    }
}

//插入一个节点
void insertNode(RBNode *z) {
    RBNode *y = nullptr;
    RBNode *x = root;
    while(x) {
        if (z->val < x->val) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        z = root;
    }
    else if (z->val < y->val) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->setColor(RED);
    insertFixUp(z);
}

void deleteFixUp(RBNode *x) {
    RBNode *other, *par;
    while ((x == nullptr || x->color == BLACK) && x != root) {
        par = x->parent;
        if (x == par->left) {
            other = par->right;
            if (other->color == RED) {
                other->color = BLACK;
                par->color = RED;
                leftRotate(par);
                other = par->right;
            }
            if ((other->left == nullptr || other->left->color == BLACK) && (other->right == nullptr && other->right->color == BLACK)) {
                other->color = RED;
                x = par;
            }
            else if (other->right == nullptr || other->right->color == BLACK) {
                other->left->color = BLACK;
                other->color = RED;
                rightRoate(other);
                other = par->right;
            }
            other->color = par->color;
            par->color = BLACK;
            other->right->color = BLACK;
            leftRotate(par);
            x = root;
            break;
        }
        else {
            other = par->left;
            if (other->color = RED) {
                other->color = BLACK;
                par->color = RED;
                rightRoate(par);
                other = par->left;
            }
            if ((other->left == nullptr || other->left->color == BLACK) && (other->right == nullptr && other->right->color == BLACK)) {
                other->color = RED;
                x = par;
            }
            else if (other->left == nullptr || other->left->color == BLACK) {
                other->right->color = BLACK;
                other->color = RED;
                leftRotate(other);
                other = par->left;
            }
            other->color = par->color;
            par->color = BLACK;
            other->left->color = BLACK;
            rightRoate(par);
            x = root;
            break;
        }
    }
    if (x) {
        x->color = BLACK;
    }
}

//删除一个节点
void deleteNode(RBNode *z) {
    RBNode *successor;
    if (!z->left || !z->right) {
        successor = z;
    }
    else {
        successor = z->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
    }
    RBNode *nexts;
    if (successor->left) {
        nexts = successor->left;
    }
    else {
        nexts = successor->right;
    }
    if (successor->parent == nullptr) {
        root = nexts;
    }
    else if (successor == successor->parent->left) {
        successor->parent->left = nexts;
    }
    else {
        successor->parent->right = nexts;
    }
    if (successor != z) {
        z->val = successor->val;
    }
    if (successor->color == BLACK) {
        deleteFixUp(successor);
    }
}

int main() {
}
