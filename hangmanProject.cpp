#include <iostream>
#include <string>
using namespace std;
string enteredWord;
string usedWord;
int maxIndex=0;
void prtWordDisp(char wordDisp[31]);
bool containsCapitalLetters(const std::string &str);
void playHangman(string word);
int main() {
  bool valid= false;
  while(valid==false){
  cout << "\n\n****** Rules for player 1 *******\n \n\n **Enter a word or phrase NO MORE THAN 30 characters.** \n\n ** End the word or sentence WITH A PERIOD ** \n\n ** NO SPACES BETWEEN THE LAST WORD AND THE PERIOD ** \n\n ** ONLY USE LOWER CASE LETTERS **\n\n*********************************\n\n";
  getline(cin, enteredWord);
  cout << "\n\n You entered: \n\n " << enteredWord << "\n\n" << endl;
  if(enteredWord.length()<=30){
    valid=true;
  }
  else{
    cout << "Make the entry 30 characters or less. Try again.\n";
    continue;
  }
    if( containsCapitalLetters(enteredWord) ==true){
      cout << "Make sure to only use lower case letters. Try again.\n";
      valid=false;
      continue;
    }
    if(enteredWord[enteredWord.length()-1]!= '.'){
      cout << "Make sure to end the word or sentence with a period. Try again.\n";
      valid= false;
      continue;
      }
    if(enteredWord.substr(enteredWord.length()-2, 1)== " "){
      cout << "Make sure to not have any spaces between the last word and the period. Try again.\n";
      valid= false;
      continue;
    }
  }
  int j= 0;
  while(enteredWord.substr(j) !="."){
    j++;
    maxIndex++;
  }
  usedWord=enteredWord.substr(0,maxIndex);
  playHangman(usedWord);
}

void playHangman(string word){
  cout << "Rules for player 2: Try to guess the word or phrase. You have 7 fails to guess the word or phrase.\n";
  bool isCorrect=false;
  int fails=0;
  char wordDisp[31];
  char wordElem[31];
  for(int i=0; i< word.length(); i++){
  if(word.substr(i,1)==" "){
    wordDisp[i]=' ';
  }
  else{
    if(i<word.length()-1){
      wordDisp[i]='_';
    }
    else{
      wordDisp[i]= '_';
    }
  }
  }
  wordDisp[word.length()] = '\0';
  for(int i=0; i< word.length(); i++){
    wordElem[i]=word[i];
  }
  wordElem[word.length()] = '\0';
while(fails<7 && isCorrect==false){
  if(fails==0){
    cout<< "\n";
    cout << " ____\n";
    cout << " |  |\n";
    cout << " |  \n";
    cout << " | \n";
    cout << " | \n";
    cout << " |\n";
    cout << "_____\n\n";
    cout << "Time to Guess! \n\n";
    prtWordDisp(wordDisp);
  }
  bool failed=true;
  cout << "\n\n Please Enter Your Guess ";
  char guess;
  cin >> guess;
  for(int i=0; i<word.length(); i++){
  if(guess==wordElem[i]){
    wordDisp[i]=guess;
    failed=false;
  }
  }
  if(failed==true){
    fails++;
    switch(fails){
      case 1:
        cout<< "\n";
        cout << " ____\n";
        cout << " |  |\n";
        cout << " |  0\n";
        cout << " | \n";
        cout << " | \n";
        cout << " |\n";
        cout << "_____\n";
        cout << "6 fails remaining\n";
        break;
   
    case 2:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " |  |\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "5 fails remaining\n";
      break;
     
    case 3:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "4 fails remaining\n";
      break;
    case 4:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "3 fails remaining\n";
      break;
    case 5:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " |  |\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "2 fails remaining\n";
      break;
    case 6:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " |  |\n";
      cout << " | / \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "1 fail remaining\n";
      break;
     
    case 7:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " |  |\n";
      cout << " | / \\\n";
      cout << " |\n";
      cout << "_____\n";
      cout << "Word Chooser, you win! Guesser, you Lose!\n";
      break;
    break;
  }
 
}
prtWordDisp(wordDisp);
isCorrect=true;
for(int i=0; i<word.length(); i++){
  if(wordDisp[i]!=wordElem[i]){
    isCorrect=false;
  }
}
if(isCorrect==true){
  cout << " Guesser, You Win! Chooser, You Lose!\n";
}
}
}
void prtWordDisp(char wordDisp[31]){
  int i=0;
  while(wordDisp[i] !='\0'){
    cout << wordDisp[i];
    i++;
  }
}
bool containsCapitalLetters(const std::string &str) {
    for (char ch : str) {
        if (std::isupper(static_cast<unsigned char>(ch))) {
            return true;
        }
    }
    return false;
}