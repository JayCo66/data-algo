//6620501419 ธนวิชญ์ คชรินทร์
//6620503322 กฤษณัส อินพามา
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int freq;
    char data;
};

struct TreeNode{
    int freq;
    char data;
    struct TreeNode *leftNode;
    struct TreeNode *rightNode;
};

struct Node alphabet[80];
int last = 0;

struct TreeNode *priorityQueue[80];
int queueSize = 0;
char huffmanCode[256][10]; 

void CountFreq(char input[]){
    for(int i=0; i<80; i++){
        alphabet[i].freq = 0;
    }

    int len = strlen(input)-1;
    for(int i=0; i<len; i++){
        int check = 1;
        for(int j=0; j<last; j++){
            if(input[i] == alphabet[j].data){
                alphabet[j].freq++;
                check = 0;
            }
        }
        if(check){
            alphabet[last].data = input[i];
            alphabet[last].freq++;
            last++;
        }
    }
}

void ShowFreq(){
    for(int i=0; i<last; i++){
        printf("'%c' :%d ", alphabet[i].data, alphabet[i].freq);
    }
}

struct Node H[80];
int n = 0;

void swap(struct Node H[], int a, int b){
    struct Node temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}

void heapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < n && H[left].freq < H[smallest].freq)
        smallest = left;

    if (right < n && H[right].freq < H[smallest].freq)
        smallest = right;

    if (smallest != idx) {
        swap(H, idx, smallest);
        heapify(smallest);
    }
}

void BottomUp() {
    for (int i = 0; i < last; i++) {
        H[i] = alphabet[i];
    }
    n = last;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(H, 0, i);
        n--;
        heapify(0);
    }
    n = last;
}

void ShowHeap(){
    for(int i=n-1; i>=0; i--){
        printf("'%c' :%d ", H[i].data, H[i].freq);
    }
}

struct TreeNode* createNode(char data, int freq){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->freq = freq;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

void insertNode(struct TreeNode* node){
    priorityQueue[queueSize++] = node;
}

struct TreeNode* extractMin(){
    int minIndex = 0;
    for(int i = 1; i < queueSize; i++){
        if(priorityQueue[i]->freq < priorityQueue[minIndex]->freq){
            minIndex = i;
        }
    }
    struct TreeNode* minNode = priorityQueue[minIndex];
    priorityQueue[minIndex] = priorityQueue[--queueSize];  
    return minNode;
}

struct TreeNode* HuffmanTree(){
    for (int i = 0; i < last; i++) {
        struct TreeNode* newNode = createNode(alphabet[i].data, alphabet[i].freq);
        insertNode(newNode);
    }

    while (queueSize > 1) {
        struct TreeNode* left = extractMin();
        struct TreeNode* right = extractMin();

        struct TreeNode* newNode = createNode('-', left->freq + right->freq);
        newNode->leftNode = left;
        newNode->rightNode = right;

        insertNode(newNode);
    }

    return priorityQueue[0];
}

void ShowHuffman(struct TreeNode* root){
    if (root == NULL) return;

    printf("'%c':%d ", root->data, root->freq);
    
    if (root->leftNode != NULL) ShowHuffman(root->leftNode);
    if (root->rightNode != NULL) ShowHuffman(root->rightNode);
}

void generateCodes(struct TreeNode* root, char* code, int depth){
    if (root == NULL) return;

    if (root->leftNode == NULL && root->rightNode == NULL) {
        code[depth] = '\0';
        strcpy(huffmanCode[(int)root->data], code);
        printf("%c: %s\n", root->data, code);
    }

    code[depth] = '0';
    generateCodes(root->leftNode, code, depth + 1);

    code[depth] = '1';
    generateCodes(root->rightNode, code, depth + 1);
}

void ShowHuffmanCode(){
    char code[10];
    struct TreeNode* root = priorityQueue[0];
    generateCodes(root, code, 0);
}

void Encoded(char input[]){
    int len = strlen(input) - 1;
    for (int i = 0; i < len; i++) {
        printf("%s ", huffmanCode[(int)input[i]]);
    }
    printf("\n");
}

int main(){
    char input[300];
    printf("Enter sentence: ");
    fgets(input, sizeof(input), stdin);

    CountFreq(input);
    printf("\n1. Frequency table of %d characters", last);
    ShowFreq();

    BottomUp();
    printf("\n\n2.1 A Min-Heap (the less frequency, the higher priority)\n");
    ShowHeap();

    struct TreeNode* root = HuffmanTree();
    printf("\n\n2.2 A Huffman Tree\n");
    ShowHuffman(root);

    printf("\n\n3. Huffman code for each character\n");
    ShowHuffmanCode();

    printf("\n\n4. Encoded sentence\n");
    Encoded(input);

    return 0;
}