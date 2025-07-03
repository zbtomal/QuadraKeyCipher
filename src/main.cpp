#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class CipherShift {
private:
    int a, b, c, prime;
    
    // Function to calculate dynamic key using mathematical formula
    int calculateDynamicKey(int position) {
        return (a * position * position + b * position + c) % prime;
    }
    
public:
    // Constructor with mathematical formula parameters
    CipherShift(int coeff_a, int coeff_b, int coeff_c, int prime_num) 
        : a(coeff_a), b(coeff_b), c(coeff_c), prime(prime_num) {}
    
    // Encryption function using mathematical formula
    string encrypt(const string& plaintext) {
        string ciphertext = "";
        
        for (int i = 0; i < plaintext.length(); i++) {
            char currentChar = plaintext[i];
            int asciiValue = static_cast<int>(currentChar);
            
            // Calculate dynamic key using mathematical formula
            int dynamicKey = calculateDynamicKey(i);
            
            // Simple but effective transformation using XOR and addition
            int encryptedValue = asciiValue + dynamicKey + i;
            
            // Keep within printable ASCII range (32-126) using modular arithmetic
            encryptedValue = ((encryptedValue - 32) % 95) + 32;
            
            ciphertext += static_cast<char>(encryptedValue);
        }
        
        return ciphertext;
    }
    
    // Decryption function using mathematical formula
    string decrypt(const string& ciphertext) {
        string plaintext = "";
        
        for (int i = 0; i < ciphertext.length(); i++) {
            char currentChar = ciphertext[i];
            int asciiValue = static_cast<int>(currentChar);
            
            // Calculate same dynamic key using mathematical formula
            int dynamicKey = calculateDynamicKey(i);
            
            // Reverse the transformation exactly
            int decryptedValue = asciiValue - dynamicKey - i;
            
            // Handle wrap-around for ASCII values
            while (decryptedValue < 32) {
                decryptedValue += 95;
            }
            while (decryptedValue > 126) {
                decryptedValue -= 95;
            }
            
            plaintext += static_cast<char>(decryptedValue);
        }
        
        return plaintext;
    }
    
    // Function to display algorithm info and mathematical formula
    void displayInfo() {
        cout << "=== CipherShift Algorithm with Mathematical Formula ===" << endl;
        cout << "Mathematical Formula: key(i) = (" << a << "*i² + " << b << "*i + " << c << ") % " << prime << endl;
        cout << "Coefficients: a=" << a << ", b=" << b << ", c=" << c << endl;
        cout << "Prime Modulus: " << prime << endl;
        cout << "Algorithm: Position-based transformation with dynamic mathematical key" << endl;
        cout << "========================================================" << endl;
    }
    
    // Function to show key progression for first few positions
    void showKeyProgression(int positions = 5) {
        cout << "Key Progression for first " << positions << " positions:" << endl;
        for (int i = 0; i < positions; i++) {
            int key = calculateDynamicKey(i);
            cout << "Position " << i << ": key(" << i << ") = (" << a << "*" << i*i << " + " << b << "*" << i << " + " << c << ") % " << prime << " = " << key << endl;
        }
        cout << endl;
    }
};

// Function to run test cases with mathematical formulas
void runTestCases() {
    cout << "\n=== RUNNING TEST CASES WITH MATHEMATICAL FORMULAS ===" << endl;
    
    // Test Case 1: Formula key(i) = (3*i² + 5*i + 7) % 97
    cout << "\n--- Test Case 1: Mathematical Formula ---" << endl;
    CipherShift cipher1(3, 5, 7, 97);
    string plaintext1 = "Hello World";
    
    cipher1.displayInfo();
    cipher1.showKeyProgression();
    cout << "Original Text: " << plaintext1 << endl;
    
    string encrypted1 = cipher1.encrypt(plaintext1);
    cout << "Encrypted Text: " << encrypted1 << endl;
    
    string decrypted1 = cipher1.decrypt(encrypted1);
    cout << "Decrypted Text: " << decrypted1 << endl;
    
    cout << "Success: " << (plaintext1 == decrypted1 ? "YES" : "NO") << endl;
    
    // Test Case 2: Formula key(i) = (2*i² + 11*i + 13) % 101
    cout << "\n--- Test Case 2: Different Mathematical Formula ---" << endl;
    CipherShift cipher2(2, 11, 13, 101);
    string plaintext2 = "CSE361";
    
    cipher2.displayInfo();
    cipher2.showKeyProgression();
    cout << "Original Text: " << plaintext2 << endl;
    
    string encrypted2 = cipher2.encrypt(plaintext2);
    cout << "Encrypted Text: " << encrypted2 << endl;
    
    string decrypted2 = cipher2.decrypt(encrypted2);
    cout << "Decrypted Text: " << decrypted2 << endl;
    
    cout << "Success: " << (plaintext2 == decrypted2 ? "YES" : "NO") << endl;
    
    // Test Case 3: Formula key(i) = (7*i² + 3*i + 17) % 103
    cout << "\n--- Test Case 3: Complex Mathematical Formula ---" << endl;
    CipherShift cipher3(7, 3, 17, 103);
    string plaintext3 = "This is a test message!";
    
    cipher3.displayInfo();
    cipher3.showKeyProgression();
    cout << "Original Text: " << plaintext3 << endl;
    
    string encrypted3 = cipher3.encrypt(plaintext3);
    cout << "Encrypted Text: " << encrypted3 << endl;
    
    string decrypted3 = cipher3.decrypt(encrypted3);
    cout << "Decrypted Text: " << decrypted3 << endl;
    
    cout << "Success: " << (plaintext3 == decrypted3 ? "YES" : "NO") << endl;
}

// Interactive mode for user input with mathematical formula
void interactiveMode() {
    cout << "\n=== INTERACTIVE MODE WITH MATHEMATICAL FORMULA ===" << endl;
    
    int a, b, c, prime;
    string userText;
    
    cout << "Enter coefficient 'a' for ai²: ";
    cin >> a;
    cout << "Enter coefficient 'b' for bi: ";
    cin >> b;
    cout << "Enter coefficient 'c' for constant term: ";
    cin >> c;
    cout << "Enter prime number for modulus: ";
    cin >> prime;
    
    cin.ignore(); // Clear the newline from buffer
    
    CipherShift userCipher(a, b, c, prime);
    
    cout << "Enter text to encrypt: ";
    getline(cin, userText);
    
    cout << "\n--- Results ---" << endl;
    userCipher.displayInfo();
    userCipher.showKeyProgression();
    cout << "Original Text: " << userText << endl;
    
    string userEncrypted = userCipher.encrypt(userText);
    cout << "Encrypted Text: " << userEncrypted << endl;
    
    string userDecrypted = userCipher.decrypt(userEncrypted);
    cout << "Decrypted Text: " << userDecrypted << endl;
    
    cout << "Encryption/Decryption Success: " << (userText == userDecrypted ? "YES" : "NO") << endl;
}

// Function to demonstrate mathematical properties
void demonstrateMathematicalProperties() {
    cout << "\n=== MATHEMATICAL PROPERTIES DEMONSTRATION ===" << endl;
    
    // Show how different formulas produce different encryption results
    string testText = "MATH";
    
    cout << "Testing text: " << testText << endl;
    cout << "\nComparing different mathematical formulas:" << endl;
    
    // Formula 1: Linear (a=0)
    CipherShift linear(0, 5, 3, 97);
    cout << "\n1. Linear Formula: key(i) = (0*i² + 5*i + 3) % 97" << endl;
    linear.showKeyProgression(4);
    cout << "Encrypted: " << linear.encrypt(testText) << endl;
    
    // Formula 2: Quadratic
    CipherShift quadratic(2, 3, 5, 97);
    cout << "\n2. Quadratic Formula: key(i) = (2*i² + 3*i + 5) % 97" << endl;
    quadratic.showKeyProgression(4);
    cout << "Encrypted: " << quadratic.encrypt(testText) << endl;
    
    // Formula 3: Different prime
    CipherShift differentPrime(2, 3, 5, 101);
    cout << "\n3. Same Quadratic, Different Prime: key(i) = (2*i² + 3*i + 5) % 101" << endl;
    differentPrime.showKeyProgression(4);
    cout << "Encrypted: " << differentPrime.encrypt(testText) << endl;
    
    cout << "\nObservation: Different formulas produce completely different encryptions!" << endl;
}

int main() {
    cout << "CipherShift Cryptographic Algorithm" << endl;
    cout << "Mathematical Formula-Based Encryption/Decryption" << endl;
    cout << "================================================" << endl;
    
    int choice;
    
    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Run Test Cases" << endl;
        cout << "2. Interactive Mode" << endl;
        cout << "3. Demonstrate Mathematical Properties" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        cin >> choice;
        
        switch (choice) {
            case 1:
                runTestCases();
                break;
            case 2:
                interactiveMode();
                break;
            case 3:
                demonstrateMathematicalProperties();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1-4." << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}
