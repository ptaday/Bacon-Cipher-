# Bacon's Cipher Implementation 

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
-  - [Testing](#testing)
- [License](#license)
- [Contact](#contact)

---

## Description

This project involves the implementation of a variant of Bacon’s cipher in the C programming language. Bacon's cipher is a technique of encoding messages using 6-bit codes known as "Bacon codes." In our version of the cipher, these codes represent uppercase letters, digits, and various symbols. Before you proceed, it's recommended that you familiarize yourself with the linked Wikipedia article to understand the concepts. https://en.wikipedia.org/wiki/Bacon%27s_cipher.

The Bacon codes are not assigned randomly. They follow a specific pattern, and the assignment of codes is outlined in the provided documentation.

## Features

- Implementation of Bacon’s cipher using 6-bit codes.
- Encryption of messages using Bacon codes.
- Decryption of ciphertext encoded with Bacon's cipher.
- Error handling for different cases, including invalid input and insufficient memory.

## Prerequisites

- Basic understanding of the C programming language.
- Familiarity with ASCII codes and encoding concepts.

## Installation

1. Clone this repository to your local machine.
2. Open the project in your preferred C development environment (e.g., VS Code).
3. Compile and build the project using the provided build commands.(git add ., git commit _am "your message", git push origin).

## Usage

To use this implementation of Bacon’s cipher:

1. Include the necessary headers from the `include` directory.
2. Implement the provided `encrypt` and `decrypt` functions in your code.
3. Use the functions to encrypt and decrypt messages using Bacon codes.

Encrypt function : The encrypt function takes a null-terminated string plaintext containing only ASCII characters with Bacon codes 0 through 52. It encodes the message using 6-bit Bacon codes and stores the result in the mutable character array ciphertext. The function returns the number of characters successfully encoded or -1 if there was insufficient memory to encode the "end-of-message" (EOM) marker.

Decrypt function : The decrypt function takes a null-terminated string ciphertext that encodes a message using Bacon's cipher. It decrypts the ciphertext and stores the decrypted message in the mutable character array plaintext. The function returns the number of encrypted characters successfully decrypted or an error code (-1, -2, -3) based on specific conditions.

Ensure that you handle error cases and follow the guidelines outlined in the assignment description.

## Contributing

Contributions to this project are welcome. If you find any issues or improvements, please submit a pull request. Follow the provided guidelines for contributing and ensure that your code adheres to the coding standards.

## Testing 

- The provided unit tests (written using Criterion) help verify the correctness of your implementation.
- Test your code with both computational tests and Valgrind tests for memory errors.
- Use the provided make commands to compile, test, and check test coverage.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

For any inquiries or feedback, please contact:
- Pushkar Taday
- Email: pmtaday@gmail.com
- GitHub: ptaday
