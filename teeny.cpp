#include <iostream>
#include<conio.h>
#include "Teeny.h"
using namespace std;

//Skeleton of class LinkedText
class LinkedText{
    struct Node{
        char ch;
        Node * next;
        Node * prev;
    } *head, *tail, *cursorPos;

    int textSize;

    public:
        LinkedText(){
            head=tail=cursorPos=NULL;
            textSize=0;
        }
        //some suggested methods
        //All these methods (except copying) are O(1) thanks to the linked list!
		void addCharAtCursorPos(char input)//when char entered
		{
			if (textSize == 0)
			{
				head = new Node;
				head->ch = input;
				head->next = nullptr;
				tail = head;
				cursorPos = head;
				textSize++;
				head->prev = nullptr;
			}
			else if (textSize > 0)
			{
				Node*temp = new Node[1];
				temp->ch = input;
				if (cursorPos == tail)
				{
					Node*temp1 = tail;
					tail = temp;
					temp->next = nullptr;
					temp->prev = temp1;
					temp1->next = temp;
					cursorPos = temp;
					textSize++;
				}
				else if (cursorPos == head)
				{
					head->next = temp;
					temp->next = nullptr;
					temp->prev = head;
					cursorPos = temp;
					tail = temp;
					textSize++;
				}
				else
				{
					temp->prev = cursorPos;
					temp->next= cursorPos->next;
					cursorPos = temp;
					textSize++;
				}
			}
		
		}
		void delCharAtCursorPos()//when bksp pressed
		{
			if (cursorPos == head)
			{
				head = cursorPos->next;
				textSize--;
				if (textSize == 0)
					head = tail = cursorPos = nullptr;
			}
			else if(cursorPos->next==nullptr)
			{
				Node*temp1= cursorPos->prev;
				tail = temp1;
				cursorPos = temp1;
				temp1->next = nullptr;
				textSize--;
			}
			else
			{
				Node*temp1 = cursorPos->prev;
				temp1->next = cursorPos->next;
				cursorPos = temp1;
				textSize--;
			}
		
		
		}
        void moveCursorRight();//right arrow
        void moveCursorLeft();//left arrow
        /*the following method returns the sub-list after cutting,
        and also adjusts cursor position*/
        Node * cutTextBetween(Node * cursorpos1, Node * cursorpos2);
        /*the following method returns the duplicated sub-list after copying,
        and also adjusts cursor position*/
        Node * copyTextBetween(Node * cursorpos1, Node * cursorpos2);
        void insertTextAtCursorPos(Node * subList);

        /*Method returns the number of times key occurs
        in LinkedText*/
        int findInText(const string & key);

        //You may add appropriate printing methods and other methods below
        ~LinkedText(){//add code
        };//delete the list


        /*The methods below will be used to keep
          the screen cursor inside the text area
          only.
        */
        inline bool textToLeft(){
            return (cursorPos!=NULL && cursorPos->prev!=NULL);
        }


        inline bool textToRight(){
            return (cursorPos!=NULL);
        }

};

int main()
{
    GetConsoleWindowDims();
    /*This starter code is capable of detecting the
      left and right arrow keys; the backspace key;
      the escape key (for quit); the F1, F2 and F3 keys;
      and the regular text keys.
      Written for CS-218 "Data Structures" BCS-3A, FAST-NU, Lahore.
    */
    LinkedText text;
    int key=-9;
    while(key!=ESCAPE){
          key=_getch();
          //either an arrow or function key is pressed
          if(SPECIAL_KEY(key)){
              key=_getch();//get 2nd part of code from buffer
              switch(key){
              case ARROW_LEFT:
                  //if(text.textToLeft()){
                    moveScreenCursorLeft();
                    //text.moveCursorLeft();
                  //}
                break;
              case ARROW_RIGHT:
                  //if (text.textToRight()){
                    moveScreenCursorRight();
                    //text.moveCursorRight();
                  //}
                break;
              case F1://start or end text selection
                  cout<<"[F1]";
                break;
              case F2://cut option
                  cout<<"[F2]";
                break;
              case F3://copy option
                  cout<<"[F3]";
                break;
              case F5://for search
                  cout<<"[F5]";
                break;
              case INSERT://to insert text
                cout<<"[INSERT]";
                break;
              };
          }else if(key==BACKSPACE){
              cout<<"[BKSP]";
          }else{
              cout<<char(key);
			 // text.addCharAtCursorPos(key);
			//  cin.ignore(1);
		  }
    }
    return 0;
}
