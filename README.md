# ![alt text](https://secure.gravatar.com/blavatar/4560c02ab420ca3cefc52ab44e8aefc1?s=32) Competitive Programming Codes

## Judges: 
- [**Code Forces**](CodeForces/)
- [**E-Olymp**](E-Olymp/)
- [**HackerEarth**](HackerEarth/)
- [**HackerRank**](HackerRank/)
- [**OmegaUp**](OmegaUp/)
- [**UVa**](UVa/)
- [**EulerProject**](EulerProject/)
- [**SPOJ**](SPOJ/)

## C++ Tips

### Input / Output Performance
```cpp
// No merge cin/cout with scanf/printf
std::ios::sync_with_stdio(false);   

// This unties cin from cout
cin.tie(NULL); 
cout.tie(NULL);  
```

### Read Intergers

You can use this to read char by char
```cpp
template <class T>  
inline void getNumberFromStandardInput(T &number) {                     //Super cool way to read ints
    
    number = 0;                                                         //Set to 0
    T numberSign = 1;                                                   //Sign all ok
    char currentChar = getchar_unlocked();                              //Read a char
 
    while (currentChar < '0' or currentChar > '9') {                    //If we are not reading numbers
        if (currentChar == '-')  numberSign = -1;                       //If we have found the sign
        currentChar = getchar_unlocked();                               //Read the next char
    }

    while (currentChar >= '0' and currentChar <= '9') {                 //While we read numbers
        number = (number << 3) + (number << 1) + (currentChar - '0');   //Multiply by 10
        currentChar = getchar_unlocked();                               //Read the next char
    }

    number *= numberSign;                                               //If negative
}

```

Now you just do something like:
```cpp
int inputSize;
getNumberFromStandardInput<long long int>(inputSize);

int data[inputSize];
for (int i = 0; i < inputSize; ++i) 
    getNumberFromStandardInput<int>(data[i]);
```

