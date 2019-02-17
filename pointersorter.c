#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct List
{
    /*This is my main data structure: Linked list.*/
    char word[10000];// The maxium length of a single word is 10000 characters
    int length;// stroes the current length of the word in a node
    struct List * next;// next node
}List;

List* prev=NULL;// the previous node before ptr

int comTo(char* ,int ,char* ,int );
List* search(List* ,char*  ,int );
List* insert (List* , char*  ,int);


int comTo(char* x,int xl,char* y,int yl){
    /* This method is used to compare 2 words and
    return the indicator of the word which should
    be higher in the printed list. -1 means variable y
    shuold be higher than variable x in the list. 0 means
    two words are exactly same. 1 means x is higher than y*/
    int i=0;
    int j=0;
    while(i<xl&&j<yl){
        if(x[i]==y[j]){
             i++;j++;
            continue;// the characters are same. so compare next characters.
        }
        if('A'<=x[i]&&x[i]<='Z'&&'A'<=y[j]&&y[j]<='Z'){
            // two characters both are capital letters.
            if(x[i]<y[j]){
                return -1;//y is up
            }
            return 1;//x is up
        }else if('A'<=x[i]&&x[i]<='Z'&&'a'<=y[j]&&y[j]<='z'){
            return 1; //x is up
        }else if('a'<=x[i]&&x[i]<='z'&&'a'<=y[j]&&y[j]<='z'){
            // two characters both are non-capital letters.
            if(x[i]<y[j]){
                return -1;//y is up
            }
            return 1;//x is up
        }else if('a'<=x[i]&&x[i]<='z'&&'A'<=y[j]&&y[j]<='Z'){
            return -1;//y is up
        }
    }
    
    // when every letters are same, longer word should be higher than another.
    if (i==xl&&j<yl){
        return -1;
    }else if(i<xl&&j==yl){
        return 1;
    }
    return 0;// two words are exactly same.
}


List* search(List* head,char* word ,int l){
    /* This method searches the corect location,
     and returns the pointer behind the location.
     return NULL if the new node should be added
     to the end of the list.*/
    List* ptr=head;
    while(ptr!=NULL){
        int num=comTo(ptr->word,ptr->length, word,l);
        if(num>0){
            prev=ptr;
            ptr=ptr->next;
            continue;
        }
        break;
    }
    return ptr;
}


List* insert (List* head, char* word ,int l){
    /* This method inserts the new node into the main list,
     and returns the pointer of the head of the list. */
    if(head==NULL){
        /* if the head is NULL, and add the new node as the head */
        head=(List*)malloc(sizeof(List*));
        head->next=NULL;
        strcpy(head->word, word);
        head->length=l;
        return head;
    }
    int num=comTo(head->word,head->length, word,l);
    if(num<=0){
        /* Add the new node before the head */
        List* t=(List*)malloc(sizeof(List*));
        t->next=head;
        strcpy(t->word, word);
        t->length=l;
        return t;
    }
    /* Add the new node before the pointer */
    List* ptr=search(head, word, l);
    List* temp=(List*)malloc(sizeof(List*));
    temp->next=ptr;
    temp->length=l;
    prev->next=temp;
    strcpy(temp->word, word);
    return head;
}


int main(int argc,char** argv){
    if(argc<2){
        // if there is no string input, return 0;
        return 0;
    }
    unsigned long length=strlen(argv[1]); // get the string length
     if(length<=0)return 0;// avoid Segmentation fault
    char* pointer=argv[1];
    while(isspace(*pointer)!=0){
        length--;
        pointer++;
    }
    if(length<=0)return 0;
    int i=0;
    List* words=NULL;
    char single[length];// stores the single word
    int l=0;// count the length of each single word
    while(i<length){
        int c=isalpha(*(pointer+i));
        if(c!=0){
            single[l]=*(pointer+i);// add the letter into the single word
            l++;
        }else if(l!=0){
            // find the non-letter character and add the word in to linked list
            single[l]='\0';
            words=insert(words,single,l);
            l--;
            while(l>=0){
                single[l]='\0';
                l--;
            }
            l=0;
        }
        i++;
    }
    
    if(l!=0){
        // if the input string does not end with a non-letter character
        single[l]='\0';
        words=insert(words,single,l);
    }
    List* ptr=words;
    while(ptr!=NULL){// print out the list
        printf("%s\n",ptr->word);
        ptr=ptr->next;
    }
    if(words!=NULL&&words->length<=26)
    free(words);
    return 0;
}
