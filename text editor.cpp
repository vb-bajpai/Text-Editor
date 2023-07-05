#include <iostream>
#include <stack>
#include<fstream>
using namespace std;

class textEditor {

    private:
    stack<char> leftStack;
    stack<char> rightStack;

    public:
        void insertWord(char word[]);
        void insertCharacter(char character);
        bool deleteCharacter();
        bool backSpace();
        void CursorControls(int position);
        void Leftcontrol(int position);
        void Rightcontrol(int position);
        void Replace(char findWhat, char replaceWith);
        void Top();
        void display();
        void slow();
};

void textEditor::Top(){
    if(leftStack.empty())
        cout << "leftStack: empty\t";
    else
        cout << "leftStack: " << leftStack.top() << "," << leftStack.size() << "\t\t";
    if(rightStack.empty())
        cout << "rightStack: empty\n";
    else
        cout << "rightStack: " << rightStack.top() << "," << rightStack.size() << endl;
}

void textEditor::insertWord(char word[]) {
    int i=0;

    while(word[i]!='\0') {
        insertCharacter(word[i]);
        i++;
    }
}

void textEditor::insertCharacter(char character){

    leftStack.push(character);
}

bool textEditor::deleteCharacter(){

    if (rightStack.empty())
        return false;
    else
        rightStack.pop();
    return true;
}

bool textEditor::backSpace(){

    if (leftStack.empty())
        return false;
    else
        leftStack.pop();
    return true;
}

void textEditor::CursorControls(int position){

    int leftSize, rightSize, count;
    leftSize = leftStack.size();
    rightSize = rightStack.size();
    if (position < leftSize)
        Leftcontrol(position);
    else {
        count = position - leftSize;
        Rightcontrol(count);
    }
}

void textEditor::Leftcontrol(int position){
    int leftSize;
    leftSize = leftStack.size();
    while(position!=leftSize) {
        rightStack.push(leftStack.top());
        leftStack.pop();
        leftSize = leftStack.size();
    }
}

void textEditor::Rightcontrol(int count){
    int rightSize, i=1;
    rightSize = rightStack.size();
    if (count > rightSize)
        cout << "Cannot move the cursor, right, to the specified position";
    else {
        while(i<=count) {
            leftStack.push(rightStack.top());
            rightStack.pop();
            i++;
        }
    }
}
void textEditor::Replace(char findWhat, char replaceWith){

    int count=1, originalCursorPoistion = leftStack.size();
    CursorControls(0);
    while(!rightStack.empty()) {
        if(rightStack.top()==findWhat) {
        deleteCharacter();
        insertCharacter(replaceWith);
        }
        else
            CursorControls(count);
            count++;
    }
    CursorControls(originalCursorPoistion);
}
void textEditor::display()
{   char arr[100],testArray[100];
    int i=0;
    Leftcontrol(0);
    while(!rightStack.empty())
    {   cout<<rightStack.top();
        ifstream File;
        ofstream F;
        File.open("testfile.txt");
        F.open("newfile.txt",ios::app);
        testArray[i]=rightStack.top();
        F<<testArray[i];
        rightStack.pop();
    }
}
void textEditor::slow()
{
    for (int i = 0; i < 10000000; i++)
    {
        cout<<"";
    }

}
int main() {
    int y;
    cout<<"::::::::::: :::::::::: :::    ::: :::::::::::      :::::::::: ::::::::: ::::::::::: ::::::::::: ::::::::  :::::::::" <<endl;
    cout<<"   :+:      :+:        :+:    :+:     :+:          :+:        :+:    :+:    :+:         :+:    :+:    :+: :+:    :+:" <<endl;
    cout<<"   +:+      +:+         +:+  +:+      +:+          +:+        +:+    +:+    +:+         +:+    +:+    +:+ +:+    +:+ "<<endl;
    cout<<"   +#+      +#++:++#     +#++:+       +#+          +#++:++#   +#+    +:+    +#+         +#+    +#+    +:+ +#++:++#: " <<endl;
    cout<<"   +#+      +#+         +#+  +#+      +#+          +#+        +#+    +#+    +#+         +#+    +#+    +#+ +#+    +#+ "<<endl;
    cout<<"   #+#      #+#        #+#    #+#     #+#          #+#        #+#    #+#    #+#         #+#    #+#    #+# #+#    #+#" <<endl;
    cout<<"   ###      ########## ###    ###     ###          ########## ######### ###########     ###     ########  ###    ### "<<endl;

    do
    {
    int a,b,x;
    char u,v;
    int i=0; char text[80],testArray[100];
    textEditor txt;
    cout<<"\n\nDo you want to enter the new text or open it from existing file"<<endl<<"1.New Text"<<endl<<"2.Existing File"<<endl;
    cin>>x;
    fflush(stdin);
    if(x==1)
    {
    cout << "Enter the word to be inserted: ";
    cin.getline(text,80);
    }
    if(x==2)
    {
    ifstream inputFile;
    inputFile.open("testfile.txt");
    while(inputFile >> testArray[i])
    {
    text[i]=testArray[i];
    i++;
    }
    }
    txt.insertWord(text);
    cout << "Inserting the word:";
    txt.Top();
    fflush(stdin);
    cout << "Enter the word to be inserted: ";
    cin.getline(text,80);
    txt.insertWord(text);
    cout << "Inserting the word:";
    txt.Top();
    txt.slow();
    cout<<"KIndly please enter the location number to which u want to take the cursor"<<endl;
    cin>>a;

    cout << "Move cursor to the position : "<<a<<"\t";
    txt.CursorControls(a);
    txt.Top();
    cout<<"KIndly please enter the location number to which u want to take the cursor again"<<endl;
    cin>>b;
    cout << "Move cursor to the position : "<<b;
    txt.CursorControls(b);

    txt.Top();
    cout<<"\n Deletion operation :\n ";
    for(i=0;i<3;i++){
        if(!txt.deleteCharacter())
            cout << "There is nothing to delete. Move your cursor accordingly to delete the character";
        else
            cout << "Delete characters using DEL: ";
            txt.Top();
    }
     cout<<"\n Backspace operation : \n";
    for(i=0;i<7;i++){
        if(!txt.backSpace())
            cout << "There is nothing to delete. Move your cursor accordingly to delete the character";
        else
            cout << "Delete characters using Backspace: ";
            txt.Top();
    }
    cout<<"\nFunction of replacing : ";
    cout<<"\nEnter the letters u want to replace : ";
    cin>>u;
    cout<<"\nEnter the letter u want to replace with : ";
    cin>>v;
    txt.Replace(u,v);
    cout << "\n Replace occurrences of "<<u<<" with"<< v<<" : ";
    txt.Top();
    txt.display();
    txt.slow();
     cout<<"\n\nDo u want text editor operate-"<<endl<<"1.yes"<<endl<<"2.no"<<endl;
    cin>>y;8
    fflush(stdin);
    }while (y==1);
    return 0;
}
