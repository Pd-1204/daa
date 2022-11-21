#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct minHeapNode{
    int freq;
    char data;
    minHeapNode *left, *right;
    minHeapNode(char data, int freq){
        left=right=nullptr;
        this->data=data;
        this->freq=freq;
    }
};
struct compare{
    bool operator()(minHeapNode *a, minHeapNode *b){
        return (a->freq > b->freq);
    }
};

void printNodes(struct minHeapNode* root, string str){
    if(root==nullptr){
        return;
    }
    if(root->data !='$'){
        cout<<root->data<<" :"<<str<<endl;
    }
    printNodes(root->left, str+'0');
    printNodes(root->right, str+'1');
}

void huffman(char data[], int freq[], int size){

    struct minHeapNode *left , *right, *temp;
    priority_queue<minHeapNode*, vector<minHeapNode*> , compare>minHeap;
    for(int i=0;i<size;i++){
        minHeap.push(new minHeapNode(data[i], freq[i]));
    }
    while(minHeap.size()!=1){
    left=minHeap.top();
    minHeap.pop();
    right=minHeap.top();
    minHeap.pop();
    temp= new minHeapNode('$', left->freq+right->freq);
    temp->left=left;
    temp->right=right;
    minHeap.push(temp);
    }
    printNodes(minHeap.top(), " ");
}


int main(){
    char data[]={'a','b', 'c', 'd'};
    int freq[] ={2,3,5,1};
    huffman(data,freq,4);
    return 0;
}