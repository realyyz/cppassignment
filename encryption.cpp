#include <iostream>
#include <string.h>
using namespace std;
const int length_of_sentence = 62;
// The flunction below makes a shift of a letter.
// The first parameter represents the letter to be converted, and the second parameter represents the number of digits to be shifted.
// For example, with a shift of 3, A would be replaced by D, Z would become c, and so on.
char rotate_right(char original_letter, int steps)
{
    if (original_letter < char('A') || original_letter > char('Z') && original_letter < char('a') || original_letter > char('z'))
    // This conditional judgment guarantees that punctuation marks and spaces will not be encrypted.
    {
        return original_letter;
    }
    char new_letter = original_letter + steps;
    if (original_letter >= char('A') && new_letter <= char('Z') && new_letter >= char('A') || original_letter >= char('a') && new_letter >= char('a') && new_letter <= char('z'))
    {
        return new_letter;
    }
    return new_letter - 26;
}
// The flunction below receives a keyword and repeats it until it matches the length of the length defined.
void vigenere_passwords_complete(char *vigenere_passwords)
{
    int length = strlen(vigenere_passwords);
    for (int i = length; i < length_of_sentence; i++)
    {
        vigenere_passwords[i] = vigenere_passwords[i - length];
    }
}
// The flunction below is a part of the vigenere algorithm, including encryption and decryption.
int rotate_number_of_each_letter(char letter)
{
    if (letter <= char('Z'))
        return int(letter - char('A'));
    return int(letter - char('a'));
}
void caesor_encryption(char *original_sentence, char *encrypted_sentence, long int &caesor_passwords)
{
    cout << "Please enter the password. Please input an integral number. \n";
    cin >> caesor_passwords;
    cout << "Please enter the sentence you want to encrypt " << endl;
    cin.ignore();
    cin.getline(original_sentence, length_of_sentence, '\n');
    // cout << original_sentence << endl;
    for (int i = 0; i < strlen(original_sentence); i++)
    {
        encrypted_sentence[i] = rotate_right(original_sentence[i], caesor_passwords % 26);
    }
    cout << "The encrypted sentence is:" << endl;
    cout << encrypted_sentence << endl;
}
void vigenere_encryption(char *original_sentence, char *encrypted_sentence, char *vigenere_passwords)
{
    cout << "Please enter the password. Please input a series of letters. \n";
    cin >> vigenere_passwords;
    vigenere_passwords_complete(vigenere_passwords);
    cout << "Please enter the sentence you want to encrypt " << endl;
    cin.ignore();
    cin.getline(original_sentence, length_of_sentence, '\n');
    // cout << original_sentence << endl;
    for (int i = 0; i < strlen(original_sentence); i++)
    {
        encrypted_sentence[i] = rotate_right(original_sentence[i], rotate_number_of_each_letter(vigenere_passwords[i]));
    }
    cout << "The encrypted sentence is:" << endl;
    cout << encrypted_sentence << endl;
}
void caesor_decryption(char *original_sentence, char *encrypted_sentence, long int &caesor_passwords)
{
    cout << "Please enter the password. Please input an integral number. \n";
    cin >> caesor_passwords;
    cout << "Please enter the sentence you want to decrypt " << endl;
    cin.ignore();
    cin.getline(encrypted_sentence, length_of_sentence, '\n');
    // cout << encrypted_sentence << endl;
    for (int i = 0; i < strlen(encrypted_sentence); i++)
    {
        original_sentence[i] = rotate_right(encrypted_sentence[i], 26 - caesor_passwords % 26);
    }
    cout << "The decrypted sentence is:" << endl;
    cout << original_sentence << endl;
}
void vigenere_decryption(char *original_sentence, char *encrypted_sentence, char *vigenere_passwords)
{
    cout << "Please enter the password. Please input a series of letters. \n";
    cin >> vigenere_passwords;
    vigenere_passwords_complete(vigenere_passwords);
    cout << "Please enter the sentence you want to decrypt " << endl;
    cin.ignore();
    cin.getline(encrypted_sentence, length_of_sentence, '\n');
    // cout << encrypted_sentence << endl;
    for (int i = 0; i < strlen(encrypted_sentence); i++)
    {
        original_sentence[i] = rotate_right(encrypted_sentence[i], 26 - rotate_number_of_each_letter(vigenere_passwords[i]));
    }
    cout << "The decrypted sentence is:" << endl;
    cout << original_sentence << endl;
}
int main()
{
    char vigenere_passwords[length_of_sentence + 1], original_sentence[length_of_sentence], encrypted_sentence[length_of_sentence], function_mode, encryption_mode;
    long int caesor_passwords;
    cout << "Do you want to encrypt or decrypt? \n";
    cout << "If you want to encrypt, press \"e\". if you want to decrypt, press \"d\".\n";
    cin >> function_mode;
    if (function_mode == char('e') || function_mode == char('E'))
    {
        cout << "Please choose the encryption algorithm. \n";
        cout << "If you want to choose caesor encryption algorithm, press \"c\", \nIf you want to choose vigenere algorithm, press \"v\" . \n";
        cin >> encryption_mode;
        if (encryption_mode == char('c') || encryption_mode == char('C'))
        {
            caesor_encryption(original_sentence, encrypted_sentence, caesor_passwords);
        }
        if (encryption_mode == char('v') || encryption_mode == char('V'))
        {
            vigenere_encryption(original_sentence, encrypted_sentence, vigenere_passwords);
        }
    }
    if (function_mode == char('d') || function_mode == char('D'))
    {
        cout << "Please choose the decryption algorithm. \n";
        cout << "If you want to choose caesor encryption algorithm, press \"c\", \nIf you want to choose vigenere algorithm, press \"v\" . \n";
        cin >> encryption_mode;
        if (encryption_mode == char('c') || encryption_mode == char('C'))
        {
            caesor_decryption(original_sentence, encrypted_sentence, caesor_passwords);
        }
        if (encryption_mode == char('v') || encryption_mode == char('V'))
        {
            vigenere_decryption(original_sentence, encrypted_sentence, vigenere_passwords);
        }
    }
}