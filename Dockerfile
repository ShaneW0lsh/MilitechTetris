FROM ubuntu:latest

WORKDIR /Tetris

RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get install -y libsfml-dev

RUN echo '#include <iostream>\n\
int main() {\n\
    std::cout << "Hello, World! HELLO WORLD! HELLO WORLD" << std::endl;\n\
    return 0;\n\
}' > main.cpp

RUN g++ -o hello main.cpp && ./hello
CMD ["./hello"]
