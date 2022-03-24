#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define input for (int i= 0 ; i<n ;i++)
// this function converts from plain message to encoded message
string to_rail_fence (string word) {
//    I made every line in a in rail-force in a string to help with code
    string line1 , line2 , line3 ;
    string rail , rail2;
/*    here I placed a space in the position of every character to use this latter in replacing the space with characters
 and you should ignore the ( - ) , I used - to give my self a chick we are the characters are and the - in the output
 */
    for (int i = 0 ; i < word.length(); ++i) {
        if (i%4 == 0) line1+=' ';
        else line1 += '-';

        if (i%2 == 0) line2 += '-';
        else line2 += ' ';

        if (i%2 == 0 && i%4 != 0) line3 += ' ';
        else line3 += '-';
    }
//  this loop is where we replace each space from the past loop with the equivalent character
    for (int i = 0; i < word.length(); ++i) {
        if (line1[i] ==' ') {
            line1[i] = word[i];
        }
        else if (line2[i] == ' '){
            line2[i] = word[i];
        }
        else if (line3[i] == ' '){
            line3[i] = word[i];
        }
    }
//    here we add every line in together in one string and ignore the -
    rail += line1  + line2 +  line3;
    for (int i = 0; i < rail.length(); ++i) if (isalpha(rail[i])) rail2 += rail[i];
    return rail2;
}
// this function converts the encoded message to plain message

string from_rail_fence (string word) {
    string line1 , line2 , line3 ;
    cin.clear();
    cin.sync();
    string rail;
    rail.resize(word.length());
//    the next for loop determines the length of every line from the zigzag
    int len1=0 ,len2=0 ,len3=0;
    for (int i = 0; i < word.length(); ++i) {
        if (i % 4 == 0) len1 +=1;
        else if (i % 2 != 0) len2 +=1;
        else  len3+=1;
    }
//    here we place the sequence of the characters in their line
    line1 = word.substr(0,len1);
    line2 = word.substr(len1,len2+len1);
    line3 = word.substr(len2+len1,len3+len1+len2);

//    here we place the index of the character in his right position
    for (int i = 0 ,j=0; j < line1.length(); i+=4,j++) rail[i] = line1[j];

    for (int i = 1 ,j=0; j < line2.length(); i+=2,j++) rail[i] = line2[j];

    for (int i = 2 ,j=0; j < line3.length(); i+=4,j++) rail[i] = line3[j];

    return rail;
}

int main() {

    cout<<"this is RAIL-FENCE cipher\n\n";

    while (true) {
        string  message;
        cout<<"these are your choices\n"
              "1- enter 1 to cipher a message\n"
              "2- enter 2 to decipher  a message\n"
              "3- enter 3 to end this programme\n";
        cout<<"\n";
        string choice ;
        cout<< "enter your choice : ";
        cin>>choice;

        if (choice == "3") {
            cout<<"you choose to end this programme\n";
            break;
        }

        else if (choice =="1"){
            message = "";
            cout << "enter your message : ";
            while (message.empty()) getline(cin , message);

//            the next three lines are here to resize the length of the message
            int len_before_spaces = message.length() ,spaces = count(message.begin(),message.end(),' ');
            message.erase(remove(message.begin(),message.end(),' '),message.end());
            message.resize(len_before_spaces - spaces);

            for (int i = 0; i < message.length(); ++i) message[i] = toupper(message[i]) ;

            cout<<"this is your zig-zag message : "<<"\n"<<to_rail_fence(message)<<"\n";
        }

        else if (choice=="2") {
            message = "";
            cout << "\n";
            cout << "you choose to enter an encoded message \n";
            cout << "enter your message : \n";
            while (message.empty()) getline(cin, message);

            int len_before_spaces = message.length() ,spaces = count(message.begin(),message.end(),' ');
            message.erase(remove(message.begin(),message.end(),' '),message.end());
            message.resize(len_before_spaces - spaces);

            for (int i = 0; i < message.length(); ++i) message[i] = toupper(message[i]);

            cout<<"this is your rail-fence message : "<<from_rail_fence(message)<<"\n\n";

        }

        else  {
            cout<< "you have to choose 1, 2 or 3 not "<<choice<<"\n\n";
            choice = "";
        }

    }
    return 0;
}
// abddelrahman     ALMBERHADAN