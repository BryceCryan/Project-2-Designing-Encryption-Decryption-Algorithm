#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ------------------ CORE ENCRYPTION (SHIFT + XOR SUBSTITUTION) ------------------
string coreEncrypt(const string &text, int key) {
    string result; 
    result.reserve(text.size());

    for (char c : text) {
        char shifted = c + key;          // SHIFTING
        char substituted = shifted ^ 0x5A; // SUBSTITUTION (XOR)
        result.push_back(substituted);
    }

    return result;
}

// ------------------ CORE DECRYPTION (REVERSE XOR + REVERSE SHIFT) ------------------
string coreDecrypt(const string &text, int key) {
    string result;
    result.reserve(text.size());

    for (char c : text) {
        char unsub = c ^ 0x5A;           // REVERSE SUBSTITUTION
        char unshift = unsub - key;      // REVERSE SHIFTING
        result.push_back(unshift);
    }

    return result;
}

// ------------------ TRANSPOSITION (SWAP NEIGHBORING CHARACTERS) ------------------
string transposeEncrypt(string text) {
    for (size_t i = 0; i + 1 < text.size(); i += 2) {
        swap(text[i], text[i + 1]);      // TRANSPOSITION
    }
    return text;
}

// ------------------ REVERSE TRANSPOSITION ------------------
string transposeDecrypt(string text) {
    for (size_t i = 0; i + 1 < text.size(); i += 2) {
        swap(text[i], text[i + 1]);      // REVERSE TRANSPOSITION
    }
    return text;
}

// ------------------ FULL ENCRYPTION PIPELINE ------------------
string encrypt(const string &plaintext, int key) {
    string step1 = coreEncrypt(plaintext, key);
    string step2 = transposeEncrypt(step1);
    return step2;
}

// ------------------ FULL DECRYPTION PIPELINE ------------------
string decrypt(const string &ciphertext, int key) {
    string step1 = transposeDecrypt(ciphertext);
    string step2 = coreDecrypt(step1, key);
    return step2;
}

// ------------------ FILE ENCRYPTION ------------------
void encryptFile(string inputFile, string outputFile, int key) {
    ifstream in(inputFile);
    ofstream out(outputFile);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        out << encrypt(line, key) << endl;
    }

    in.close();
    out.close();
}

// ------------------ FILE DECRYPTION ------------------
void decryptFile(string inputFile, string outputFile, int key) {
    ifstream in(inputFile);
    ofstream out(outputFile);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        out << decrypt(line, key) << endl;
    }

    in.close();
    out.close();
}

// ------------------ MAIN MENU ------------------
int main() {
    int choice, key;
    string inputFile, outputFile;

    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter input file name: ";
    cin >> inputFile;
    cout << "Enter output file name: ";
    cin >> outputFile;
    cout << "Enter key (integer): ";
    cin >> key;

    if (choice == 1) {
        encryptFile(inputFile, outputFile, key);
    } else if (choice == 2) {
        decryptFile(inputFile, outputFile, key);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}