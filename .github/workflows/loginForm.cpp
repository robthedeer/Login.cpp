#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>


using namespace std;



void welcome();//Done
void createAccount();//Done
void isloggedIn();//Done
void passWord();//Done
void passwordLength();//Done
void checkSpecialCharInPassword();//done
void checkUpperCaseInPassword(); //Done
void myProfile(); //Done
void compare();


extern string firstname, surname, username,newpassword, un, pw, email,phone, address,confirmPassword;

void welcome(){
    cout<<"/////////////WELCOME TO QesBankLoginPage ///////////////\n";
    cout<<"/////////////WELCOME TO QesBankLoginPage ///////////////\n";
    cout<<"/////////////WELCOME TO QesBankLogInPage ///////////////\n";
    cout<<"/////////////WELCOME TO QesBankLogInPage ///////////////\n";
    cout<<"/////////////WELCOME TO QesBankLogInPage ///////////////\n";
    cout<<"/////////////WELCOME TO QesBankLogInPage ///////////////\n";

    int choice;

    cout<<"1. Login\n2.Create Account\n3. Exit\n";
    cout<<"Choose the option by number:\n";
    cin>>choice;

    if (choice == 1)
    {
          
          isloggedIn();
            
    }
    else if(choice == 2){
        
        
        createAccount();
        
        
    }
    else{
            
        welcome();
    }
   


}
void passwordLength() {
    string newpassword;
    if(newpassword.length() < 8)
    {
        cout<<"Password is too short! Try again!\n";
        passWord();

    } 
    else if(newpassword.length() == 8 )
    {
        cout<<"Password is too weak!\n";
        
    }
    else if(newpassword.length() >=8)
    {
        cout<<"Password is medium!\n";
        

    }
    else {
        cout<<"Password is strong\n";
        
    }


}
void checkSpecialCharInPassword(){
    
    string newpassword;
    int flag =0;

    for(int i=0; i <newpassword.length(); i++){

        if (newpassword[i]>=48 && newpassword[i]<=57 || newpassword[i]>=65 && newpassword[i]<=90 || (newpassword[i]>=97 && newpassword[i] <=122))
        {
            continue;
        }
        else{
            cout<<"The password contains special characters\n";
            flag=1;
            
        }
        if(flag ==0)
        {
            cout<<"The password does not contain any special characters\n";
        }

    }
    

}
void checkUpperCaseInPassword(){

    for(int i =0; newpassword.length();i++)
    {
        if(newpassword[i]>=65 && newpassword[i]<=90)
        {
            cout<<"The Password contains an Uppecase\n";
            
        }
        else{
            cout<<"An Uppercase is missing in your password!\n";
            cout<<"Enter the password again!\n";
            passWord();
        }
    }
}
void passWord(){

     cout<<"Enter New Password:\n"; cin>>newpassword; //Let our new password include at least 2 special characters ,at least 1 capatal letter and 1 digit 

    //check length 
    //passwordLength();
    //check if there are special characters
    checkSpecialCharInPassword();

    //Check if there are at least 1 digit
    //Check if there are at least 1 uppercase letter
    //checkUpperCaseInPassword();
    
    cout<<"Confirm Password:\n"; cin>>confirmPassword;
    if(confirmPassword == newpassword)
    {
        cout<<"Password successifuly confirmed!\n";
    }
    
}
void createAccount()
{
    
    cout<<"Enter Your Name:\n"; cin>>firstname;
    if (firstname.length()>=25)
    {
        cout<<"Firstname too long!! Please enter less than 25 charaters\n";
        createAccount();
    }
   
    cout<<"Enter your Surname: max[25]\n"; cin>>surname; 
    cout<<"Enter username of your choice:"; cin>>username; 
    cout<<"Enter your Email:\n"; cin>>email; 
    cout<<"Enter your Phone:\n"; cin>>phone;
    cout<<"Enter your Address:\n"; cin>>address;
    passWord();
    for (int i = 0; i < firstname.length(); i++)
    {
        toupper(firstname[i]);
    }
    for (int i = 0; i < surname.length(); i++)
    {
        toupper(surname[i]);
    }
    for (int i = 0; i < email.length(); i++)
    {
        tolower(email[i]);
    }

   //Declare ofstream for writing data
   ofstream profile;

   //opening a file where passwords will be stored
   profile.open ("/Users/macrob/Passcodes/profile.txt",ios::out | ios::app | ios::binary);
   if (profile.is_open()){
       //Writing data to the file
       profile<<"Firstname:"<<firstname<<endl;
       profile<<"Surname:"<<surname<<endl;
       profile<<"Email:"<<email<<endl;
       profile<<"Phone Number:+7"<<phone<<endl;
       profile<<"Address: "<<address<<endl;
       profile<<"****Login Details:****\n";
       profile<<"Username: "<<username<<endl;
       profile<<"Password: "<<newpassword<<endl;
       profile.close();
       isloggedIn();
       
   }
   else{
       cout<<"Read Error!Text file can't be opened!\n";
       createAccount();
   }
   
}
void myProfile(){ //reading profile data from the text file 

    //Reading data from the text file using ifstream
    string line;
    ifstream profile("/Users/macrob/Passcodes/profile.txt");
    if(profile.is_open()){
        while(getline(profile,line)){
            cout<<line<<'\n';
        }
        profile.close();
    }
    else
    {
        cout<<"Unable to open your profile! File corrupted!!\n";
    }

}
void compare(string username, string un ,string newpassword, string pw){
    
    int result1 = username.compare(un);
    int result2 =newpassword.compare(pw);
    cout<<"Logging in .......\nChecking Password\n"<<result1<<result2;
    if(result1 && result2 == 0)
    {
        cout<<"Login Succesiful\n";
        myProfile();
    }
    else{
        cout<<"Password or Username is not correct! Try again!\n";
    }
    
    
    }


void isloggedIn(){

   
    
    cout<<"||******Login Page *****||\n";

    cout<<"Username:\n"; cin>>un;
    cout<<"Password:\n";cin>>pw;

    ifstream profile;
    ifstream read("/Users/macrob/Passcodes/profile.txt",ios::out);
    getline(read,username);
    getline(read,newpassword);
    compare();
    
    
}

int main()
{
    string newpassword;
    welcome();
    return 0;
}
