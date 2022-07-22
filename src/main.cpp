#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
    
using namespace std;

bool endswith(string a, string b);

int main() {

begin:

    string input;
    vector<string> phrase;
    map<string,int> digits;

    string nextSearch;
    int searchResult;
    int finalResult;
    vector<int> results;

    digits["one"] = 1;
    digits["two"] = 2;
    digits["three"] = 3;
    digits["four"] = 4;
    digits["five"] = 5;
    digits["six"] = 6;
    digits["seven"] = 7;
    digits["eight"] = 8;
    digits["nine"] = 9;
    digits["ten"] = 10;
    digits["eleven"] = 11;
    digits["twelve"] = 12;
    digits["thirteen"] = 13;
    digits["fourteen"] = 14;
    digits["fifteen"] = 15;
    digits["sixteen"] = 16;
    digits["seventeen"] = 17;
    digits["eighteen"] = 18;
    digits["nineteen"] = 19;

    digits["twenty"] = 20;
    digits["thirty"] = 30;
    digits["forty"] = 40;
    digits["fifty"] = 50;
    digits["sixty"] = 60;
    digits["seventy"] = 70;
    digits["eighty"] = 80;
    digits["ninety"] = 90;

    digits["hundred"] = 100; 
    digits["thousand"] = 1000;
    digits["million"] = 1000000;
    digits["billion"] = 1000000000;
    digits["trillion"] = 1000000000;

    cout << "Welcome to the text review program!\nThis program that converts written numbers in words to digits in the middle of a paragraph.\n\n";
    cout << "Type one text to review, folowed by \":q\" : ";
    
    while( cin >> input ){
        if (input == ":q"){
            break;
        }
        
        phrase.push_back( input );
    }
 
    for (int i = 0; i < phrase.size(); i++){
        string searchWord = phrase[i];
        transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);

        searchResult = digits[searchWord];
        finalResult = searchResult;

        if(searchResult != 0){
            int countInternal = i+1;
            valid_next: 
            if(countInternal < phrase.size()){
                
                string nextSearch = phrase[countInternal];
                transform(nextSearch.begin(), nextSearch.end(), nextSearch.begin(), ::tolower);

                    if(nextSearch == "hundred") {
                        finalResult *= digits[nextSearch];
                        phrase[countInternal] = "";
                        countInternal += 1;
                        if(countInternal < phrase.size()){
                            string nextWordVector = phrase[countInternal];
                            transform(nextWordVector.begin(), nextWordVector.end(), nextWordVector.begin(), ::tolower);
                            if(nextWordVector == "thousand" || nextWordVector == "million" || nextWordVector == "billion"){
                                goto valid_next;
                            }
                        }

                        results.push_back( finalResult );
                        finalResult = 0;
                        goto valid_next;

                    }

                    if(nextSearch == "thousand"){
                        finalResult *= digits[nextSearch];
                        phrase[countInternal] = "";
                        countInternal += 1;

                        if(countInternal < phrase.size()){
                            string nextWordVector = phrase[countInternal];
                            transform(nextWordVector.begin(), nextWordVector.end(), nextWordVector.begin(), ::tolower);
                            if(nextWordVector == "million" || nextWordVector == "billion"){
                                goto valid_next;
                            }
                        }
                        
                        results.push_back( finalResult );
                        finalResult = 0;
                        goto valid_next;
                        
                    }

                    if(nextSearch == "million"){
                        finalResult *= digits[nextSearch];
                        phrase[countInternal] = "";
                        countInternal += 1;

                        if(countInternal < phrase.size()){
                            string nextWordVector = phrase[countInternal];
                            transform(nextWordVector.begin(), nextWordVector.end(), nextWordVector.begin(), ::tolower);
                            if(nextWordVector == "billion"){
                                goto valid_next;
                            }
                        }

                        results.push_back( finalResult );
                        finalResult = 0;
                        goto valid_next;
                        
                    }

                    if(nextSearch == "billion"){
                        finalResult *= digits[nextSearch];
                        results.push_back( finalResult );
                        phrase[countInternal] = "";
                        countInternal += 1;
                        finalResult = 0;
                        goto valid_next;
                    }

                    if (nextSearch == "and" || nextSearch == "-"){
                        phrase[countInternal] = "";
                        countInternal += 1;
                        goto valid_next;
                    }

                    if (endswith(nextSearch,"ty")){
                        finalResult += digits[nextSearch];
                        phrase[countInternal] = "";
                        countInternal += 1;

                        if(countInternal < phrase.size()){
                            string nextWordVector = phrase[countInternal];
                            transform(nextWordVector.begin(), nextWordVector.end(), nextWordVector.begin(), ::tolower);
                            if(digits[nextWordVector] != 0){
                                goto valid_next;
                            }
                        }
                        
                        results.push_back( finalResult );
                        finalResult = 0;
                        goto valid_next;
                        
                    }

                    if(digits[nextSearch] > 0 and digits[nextSearch] < 20){
                        finalResult += digits[nextSearch];
                        phrase[countInternal] = "";
                        countInternal += 1;
                        goto valid_next;
                    }
                    
                    countInternal = phrase.size() + 1;
                    goto valid_next;

            } else {
                if(results.size() > 0){
                    for(int countFromResult = 0; countFromResult < results.size(); countFromResult++){ 
                        finalResult += results[countFromResult]; 
                    } 
                }    
                cout << finalResult << " ";
                results.clear();
            }
        } else {
            if(phrase[i] != ""){
                cout << phrase[i] << " ";
            } 
        }
    }
    cout << endl;

    string opt;
    cout << "You want to sent/write a new text? [s/n]" << endl;
    cin >> opt;

    if(opt == "s"){
        system("clear");
        goto begin;
    } else if( opt == "n") {
        system("clear");
        cout << "Bye! See you later!" << endl; exit;
    } else {
        cout << "Invalid option! Bye" << endl; exit; 
    }

    return 0; 

}

bool endswith(string a, string b){
    //To check if the word ends with ty eg. thirty, forty

    int len = a.length();
    string last_two = a.substr(len-2, len-1);

    if((last_two.compare(b)) == 0){
        return true;
    }

    return false;
}
   