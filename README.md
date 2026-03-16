# **Project 2 – Encryption/Decryption Algorithm**
### *By Bryce Cryan*

---

## Overview

This project is a custom encryption and decryption program written in C++. The goal was to design my own reversible algorithm using basic cryptographic ideas. The program reads text from a file, encrypts it using my algorithm, and writes the encrypted output to a new file. It can also decrypt the encrypted file back into the original text as long as the same key is used.

My algorithm uses three techniques:

- **Shifting**
- **Substitution (XOR)**
- **Transposition**

All three steps are reversible, which is what makes the decryption process work.

---

## How My Encryption Algorithm Works

### **1. Shifting**
The first step is a Caesar‑style shift. Every character gets moved forward in the ASCII table by the key the user enters.  
This is undone during decryption by subtracting the same key.

---

### **2. Substitution (XOR Masking)**
After shifting, I apply XOR with the constant value `0x5A`. XOR is useful because:

- It scrambles the bits  
- It’s perfectly reversible (XOR again with the same value restores the original)

This adds another layer of confusion beyond just shifting.

---

### **3. Transposition**
Finally, I swap characters in pairs:

- Swap (0,1), (2,3), (4,5), etc.

This changes the structure of the text and makes the encrypted output look even more random.  
During decryption, I swap the same pairs again to restore the original order.

---

### **Decryption**
Decryption reverses the steps in the opposite order:

1. Undo the transposition  
2. Undo the XOR  
3. Undo the shift  

Because each step is reversible, the decrypted text matches the original exactly.

---

## How to Compile and Run the Program

This program uses only standard C++ libraries:

- `<iostream>`
- `<fstream>`
- `<string>`

---

### **Compile**
```bash
clang++ main.cc -o encryptor
```

### **Run**
```bash
./encryptor
```

You’ll see a menu:

```
1. Encrypt a file
2. Decrypt a file
```

Then the program asks for:

- Input file name  
- Output file name  
- Key (integer)

---

## User Guide (Beginner‑Friendly)

### **Encrypting a File**
1. Create a text file (example: `test_original_file.txt`).
2. Run the program.
3. Choose **1** for encryption.
4. Enter:
   - Input file name (`test_original_file.txt`)
   - Output file name (`test_encryption.txt`)
   - A key (any integer)
5. The encrypted file will look like random symbols. That’s normal.

---

### **Decrypting a File**
1. Run the program again.
2. Choose **2** for decryption.
3. Enter:
   - Input file name (`test_encryption.txt`)
   - Output file name (`test_decrypted.txt`)
   - The **same key** you used before
4. The program will recreate the original text.

---

### **Example**

**Input (test_original_file.txt):**
```
Hi this is a test file. My name is Bryce Cryan. I am in CPSC 253. 
```

**Encrypted output (test_encryption.txt):**
```
1,x10x//19x,x/=x,12=4xj!*x59x=/1x!.=?x!.*9xjx591xx*nxomxj
```

**Decrypted output (decrypted.txt):**
```
Hi this is a test file. My name is Bryce Cryan. I am in CPSC 253. 
```

This shows that the algorithm is fully reversible.

---

## ✅ Summary

This project helped me understand how simple cryptographic techniques can be combined to create a reversible encryption system. By using shifting, XOR substitution, and transposition, I built an algorithm that is easy to explain but still demonstrates real cryptography concepts. The program handles file input/output, user interaction, and error checking, and it successfully encrypts and decrypts text files using my custom method.

---