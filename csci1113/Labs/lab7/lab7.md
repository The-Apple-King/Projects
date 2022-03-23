string  str1; str2; 
getline(cin,str1);  // Hello is input 
  
string sentence = “Outside it is cloudy and warm”; 
str2 = “cloudy”;

cout << sentence.find(“is”) << endl; // Ans: 11
 
cout << sentence.find(‘o’) << endl; // Ans:  16
 
cout << sentence.find(str2) << endl; // Ans:  14
 
cout << sentence.find(“the”) << endl;     // Ans:  String::npos
 
cout << sentence.substr(0, 5) << endl;    // Ans:  outsi
 
cout << sentence.substr(sentence.find(“is”), 7) << endl;  Ans:  is clou
 
cout << sentence.substr(sentence.find(str2), str2.length());  Ans:  Cloudy


for(int i = 0; i < 4; i++){
    cout << str1[i] << "\n";
    }


for(int i = 0; i < 3; i++){
    str2 = str2 + str1[i];
    }


str2 = str1.substr(0, (str1.length-1);

str1 = str1.substr(0, str1.find("=")-1);

string::npos

if(str1.find(",") != -1){
    cout << "the comma is at index: " << str1.find(",");
}
else{
    cout << "no comma found";
}