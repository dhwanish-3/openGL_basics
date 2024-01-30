# OpenGL - Basics using C

The basics of OpenGL programming in C with comments explaining what each function call does. It covers the fundamental concepts and provides examples to help you get started with OpenGL development.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation
To use this code, you need to have OpenGL installed on your system(Linux). Follow the instructions below to install the necessary dependencies:

1. Install OpenGL library
```
sudo apt update && sudo apt upgrade
sudo apt install freeglut3-dev
```

## Usage
To run the code in this repository, follow these steps:

1. Clone the repository
2. Select any file and compile it using the following command:
```
cd <foldername>
gcc -o <objectname> <filename>.c -lGL -lGLU -lglut -lm
```
3. Run the executable
```
./<objectname>
```

or you can compile and run the latest modified file using the following command:
```
./run.sh
```

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).
