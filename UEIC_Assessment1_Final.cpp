//Header Files
#include <iostream>    //input-output header file
#include <cstdlib>     //for 'random' function
#include <ctime>       //for 'srand' function
#include <cstring>     //for identifying the length of the password

using namespace std;

//This 'choose' function is designed to choose random numbers for the whole project.

int choose(string mode)  //The function receives one parameter 'mode' which is a string type. It will return a random number.
{
    //If input mode is 'type', a random number from 1,2 and 3 will be generated for choosing character groups. <Lower Case Letter or Upper Case Letter or numbers>
    //If input mode is 'letter', a random number from 0 to 25 will be generated for choosing letters.
    //If input mode is 'number', a random number from 0 to 9 will be generated for choosing numbers.
    //If input mode is 'passwordCount', a random number from 10 to 16 will be generated for the length of a password.
    //If input mode is NONE of the above, 0 will be generated as default.

    int random;

    if (mode=="type")
    {
        random=rand()%3+1;
    }
    else if (mode=="letter")
    {
        random=rand()%26;
    }
    else if (mode=="number")
    {
        random=rand()%10;
    }
    else if (mode=="passwordCount")
    {
        random=rand()%7+10;
    }
    else
    {
        random=0;
    }
    return random;
}

//This function 'genPassword' is fully designed to generate a random password which meets 5 rules.

string genPassword()  //This function receives no parameters and return a random password string.
{
    //Firstly, an empty string is initialized for password.
    //Then, three strings, one for lowercase case alphabet(a-z), one for uppercase alphabet (A-Z) and one for numbers (0-9) are created.
    //After that, the variables 'count', 'countLower', 'countUpper' and 'countNumbers' are declared to track the overall length, number of lowercase letters, uppercase letters and numbers respectively.
    //Next, the variables 'charkey', 'newCharkey', 'numkey' and 'newNumkey' are declared to store the random number for letters and numbers temporarily.

    string password="";
    string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    int Count=0;
    int countLower, countUpper, countNumbers=0;
    int charkey,newCharkey;
    int numkey, newNumkey;

    //Choose function is called to generate a random length of the password from 10 to 16 and stored in the variable called 'num'.

    int num=choose("passwordCount");

    //After we have got the random length, the password generation process begins.
    //This is the while loop to generate the password.

    while(Count<num)   //It will iterate as long as the current password length is less than the actual password length.
    {
        int randomType=choose("type"); //First of all, we will chose the type of character with 'choose' function and run a switch selection statement.
        switch(randomType)
        {
        case 1:   //If the random number is 1, one of the lower alphabets will be chosen.
            if (Count==0)
                //If it is the first character of the password,
                //The random index for the lower alphabet will be chosen randomly without any further considerations.
                //This random index will be stored in "charkey". Then the chosen alphabet will be added to the password string. Then, countLower and count will be increased by one.
            {
                charkey=choose("letter");
                password+=lowerAlphabet[charkey];
                countLower++;
                Count++;
            }

            //If there is one lower character and there aren't any upper characters and any numbers yet, the loop will be stopped.
            //This ensures our random password to include at least one lower character, one upper character and one number.

            else if ((countLower==1)&&(countUpper==0 || countNumbers==0))
            {
                break;
            }

            //If there is at least one lower character, one upper character and one number present, the loop will continue choosing the lower alphabet.
            else
            {
                newCharkey=choose("letter"); //The random index for the lower alphabet will be chosen randomly and stored in "newCharkey".
                if (newCharkey!=charkey)
                    //If the chosen index "newCharkey" is the same as the previous index "charkey", the loop will be stopped.
                    //This ensures two consecutive characters not to be identical.
                    //Only these two indexes are not the same, the process will be continued, the chosen lower alphabet will be added in the password string and "countLower" and "count" will be increased by one..
                    //Next, the index in "newCharkey" will be assigned to "charkey" for further checking.
                {
                    password+=lowerAlphabet[newCharkey];
                    countLower++;
                    Count++;
                    charkey=newCharkey;
                }
            }
            break;

        case 2:  //If the random number is 2, one of the upper alphabets will be chosen.
            if (Count==0)
                //If it is the first character of the password,
                //The upper alphabet will be chosen randomly without any further considerations.
                //This random index will be stored in "charkey". Then, the chosen alphabet will be added to the password string. Then, countUpper and count will be increased by one.
            {
                charkey=choose("letter");
                password+=upperAlphabet[charkey];
                countUpper++;
                Count++;
            }

            //If there is one upper character and there aren't any lower characters and any numbers yet, the loop will be stopped.
            //This ensures our random password to include at least one lower character, one upper character and one number.

            else if ((countUpper==1)&&(countLower==0 || countNumbers==0))
            {
                break;
            }
            else
            {
                newCharkey=choose("letter"); //The random index for the upper alphabet will be chosen randomly and stored in "newCharkey".
                if (newCharkey!=charkey)
                    //If the chosen index "newCharkey" is the same as the previous index "charkey", the loop will be stopped.
                    //This ensures two consecutive characters not to be identical.
                    //Only these two indexes are not the same, the process will be continued, the chosen upper alphabet will be added in the password string and "countUpper" and "count" will be increased by one..
                    //Next, the index in "newCharkey" will be assigned to "charkey" for further checking.
                {
                    password+=upperAlphabet[newCharkey];
                    countUpper++;
                    Count++;
                    charkey=newCharkey;
                }
            }
            break;

        case 3:  //If the random number is 3, one of the numbers will be chosen.
            if (Count==0)
                //If it is the first character,
                //The number will be chosen randomly without any further considerations.
                //This random index will be stored in "numkey". Then, the chosen number will be added to the password string. Then, countNumbers and Count will be increased by one.
            {
                numkey=choose("number");
                password+=numbers[numkey];
                countNumbers++;
                Count++;
            }

            //If there is one number and there aren't any upper characters and any lower characters yet, the loop will be stopped.
            //This ensures our random password to include at least one lower character, one upper character and one number.

            else if ((countNumbers==1)&&(countUpper==0 || countLower==0))
            {
                break;
            }
            else

            {
                newNumkey=choose("number"); //The random index for the number will be chosen randomly and stored in "newNumkey".
                if (newNumkey!=numkey)
                    //If the chosen index "newNumkey" is the same as the previous index "numkey", the loop will be stopped.
                    //This ensures two consecutive numbers not to be identical.
                    //Only these two indexes are not the same, the process will be continued, the chosen upper alphabet will be added in the password string and "countNumbers" and "count" will be increased by one.
                    //Next, the index in "newNumkey" will be assigned to "numkey" for further checking.
                {
                    password+=numbers[newNumkey];
                    countNumbers++;
                    Count++;
                    numkey=newNumkey;
                }
            }
            break;

        default:  //If the random number is not 1, 2 or 3, it will show error. But due to the 'choose' function, it will always generate only from 1,2 and 3.

            password="Error";

            break;
        }
    }
    return password;
}

//Main function to be executed

int main()
{

    string password;
    srand(time(0));  //This srand function is used not to generate same random numbers.
    for (int i=1; i<=20; ++i)    //20 Unique passwords will be executed by this loop according to the instruction.
    {
        password=genPassword(); //A random password is generated.
        cout<<"Random Password No: "<<i<<" - "<<password<<endl; //The generated password is shown as an output.
        cout<<endl;
    }

    return 0;
}
