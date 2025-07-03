# QuadraKeyCipher
CSE361 Assignment

# 🔐 QuadraKey Cipher

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Algorithm: Cryptography](https://img.shields.io/badge/Algorithm-Cryptography-red.svg)](https://en.wikipedia.org/wiki/Cryptography)
[![Math: Quadratic](https://img.shields.io/badge/Math-Quadratic-green.svg)](https://en.wikipedia.org/wiki/Quadratic_equation)

> **A sophisticated cryptographic algorithm that combines quadratic mathematical formulas with position-based dynamic key generation for enhanced security.**

## 🚀 Algorithm Overview

**QuadraKey Cipher** is an advanced cryptographic algorithm that revolutionizes traditional encryption by incorporating mathematical analysis principles. Unlike conventional ciphers, QuadraKey uses quadratic equations to generate unique keys for each character position, making it significantly more resistant to frequency analysis and pattern recognition attacks.

### ✨ Key Features

- 🧮 **Mathematical Formula-Based Encryption**: Uses quadratic equations `key(i) = (a*i² + b*i + c) % prime`
- 🔑 **Dynamic Key Generation**: Each character position gets a unique key
- 🔢 **Prime Number Integration**: Utilizes prime numbers for enhanced mathematical security
- 📍 **Position-Dependent Transformation**: Character position influences encryption strength
- 🔄 **Perfect Reversibility**: Guaranteed decryption back to original plaintext
- 🎯 **Modular Arithmetic**: Keeps encrypted values within printable ASCII range

## 🧪 Mathematical Foundation

The algorithm's security is built on several mathematical concepts:

- **Quadratic Equations**: `f(i) = ai² + bi + c`
- **Modular Arithmetic**: Operations with prime number modulus
- **Prime Number Theory**: Enhanced security through mathematical complexity
- **Linear Transformations**: Character value manipulation
- **Position-Based Functions**: Unique encryption for each character position

## 🔧 Installation & Usage

### Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- Standard C++ library support

### Quick Start

```bash
# Clone the repository
git clone https://github.com/yourusername/quadrakey-cipher.git
cd quadrakey-cipher

# Compile the program
g++ -o quadrakey main.cpp

# Run the program
./quadrakey
```

### Basic Usage Example

```cpp
#include "quadrakey.h"

// Initialize with mathematical formula parameters
// Formula: key(i) = (3*i² + 5*i + 7) % 97
QuadraKey cipher(3, 5, 7, 97);

// Encrypt your message
string encrypted = cipher.encrypt("Hello World");

// Decrypt back to original
string decrypted = cipher.decrypt(encrypted);
```

## 📊 Algorithm Demonstration

### Test Case Results

| Test Case | Formula | Plaintext | Status |
|-----------|---------|-----------|--------|
| Case 1 | `(3i² + 5i + 7) % 97` | "Hello World" | ✅ Success |
| Case 2 | `(2i² + 11i + 13) % 101` | "CSE361" | ✅ Success |
| Case 3 | `(7i² + 3i + 17) % 103` | "This is a test message!" | ✅ Success |

### Key Progression Example

For formula `key(i) = (3i² + 5i + 7) % 97`:

```
Position 0: key(0) = (3*0 + 5*0 + 7) % 97 = 7
Position 1: key(1) = (3*1 + 5*1 + 7) % 97 = 15
Position 2: key(2) = (3*4 + 5*2 + 7) % 97 = 29
Position 3: key(3) = (3*9 + 5*3 + 7) % 97 = 49
Position 4: key(4) = (3*16 + 5*4 + 7) % 97 = 75
```

## 🛡️ Security Analysis

### Strengths
- **Mathematical Complexity**: Quadratic formula creates non-linear key progression
- **Position-Dependent Security**: Each character encrypted with unique key
- **Prime Number Integration**: Adds mathematical sophistication
- **Frequency Analysis Resistance**: Dynamic keys prevent pattern recognition
- **Scalable Security**: Adjustable parameters for different security levels

### Limitations
- **Parameter Dependency**: Security relies on keeping formula parameters secret
- **Known-Plaintext Vulnerability**: Susceptible if parameters are discovered
- **Educational Purpose**: Designed for learning, not production security systems

## 🎮 Interactive Features

The implementation includes several interactive modes:

1. **Test Case Runner**: Automated testing with predefined scenarios
2. **Interactive Mode**: User-defined parameters and text input
3. **Mathematical Properties Demo**: Visualization of different formulas
4. **Key Progression Display**: Shows how keys evolve with position

## 📈 Performance Characteristics

- **Time Complexity**: O(n) where n is the length of input text
- **Space Complexity**: O(1) additional space for encryption/decryption
- **Throughput**: Efficient character-by-character processing
- **Memory Usage**: Minimal memory footprint

## 🧑‍💻 About the Developer

**Zikrul Bari Tomal**
- 🎓 Student ID: 2102056
- 🏛️ Department of Computer Science and Engineering
- 🎓 Hajee Mohammad Danesh Science and Technology University
- 📧 Contact: zbtomal.10@gmail.com

## 📚 Academic Context

This algorithm was developed as part of:
- **Course**: Mathematical Analysis for Computer Science (CSE 361)
- **Assignment Type**: Individual Cryptographic Algorithm Design
- **Focus**: Integration of mathematical concepts with practical cryptography
- **Objective**: Demonstrate advanced understanding of mathematical applications in computer science

## 🔬 Algorithm Specifications

### Encryption Process
1. Initialize with quadratic formula parameters (a, b, c, prime)
2. For each character at position i:
   - Calculate dynamic key using `key(i) = (a*i² + b*i + c) % prime`
   - Transform character: `encrypted = (ascii + key + position) mod range`
   - Ensure printable ASCII range (32-126)

### Decryption Process
1. Use identical formula parameters
2. For each encrypted character:
   - Calculate same dynamic key for position
   - Reverse transformation with proper modular arithmetic
   - Handle wrap-around for ASCII values

## 🎯 Use Cases

- **Educational Cryptography**: Learn mathematical concepts in encryption
- **Academic Projects**: Demonstrate algorithm design skills
- **Mathematical Analysis**: Study quadratic equations in practical applications
- **Security Research**: Analyze position-based encryption techniques
- **Programming Practice**: Implement mathematical formulas in code

## 🤝 Contributing

Contributions are welcome! Please feel free to submit:
- Bug reports and fixes
- Feature enhancements
- Performance optimizations
- Additional test cases
- Documentation improvements

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## ⚠️ Disclaimer

**Important**: This algorithm is designed for educational and research purposes only. It should not be used for actual security-critical applications without thorough security analysis and additional protective measures.

## 🔮 Future Enhancements

- [ ] Variable-length key support
- [ ] Multiple prime number integration
- [ ] Adaptive formula parameters
- [ ] Parallel processing optimization
- [ ] Cryptanalysis resistance improvements
- [ ] GUI implementation
- [ ] Performance benchmarking suite

---

<div align="center">

**QuadraKey Cipher** - Where Mathematics Meets Cryptography 🔐✨

*Developed with ❤️ for the advancement of cryptographic education*

</div>
