# ![alt text](https://secure.gravatar.com/blavatar/4560c02ab420ca3cefc52ab44e8aefc1?s=32) Competitive Programming Codes

## Judges: 
- [**Code Forces**](CodeForces/)
- [**E-Olymp**](E-Olymp/)
- [**HackerEarth**](HackerEarth/)
- [**OmegaUp**](OmegaUp/)
- [**UVa**](UVa/)

## C++ Tips

### Input / Output Performance
```cpp
// No merge cin/cout with scanf/printf
ios_base::sync_with_stdio(0);
std::ios::sync_with_stdio(0);   

// This unties cin from cout
cin.tie(NULL); 
cout.tie(NULL);  
```

### Read Intergers

You can use this to read char by char
```cpp
template <class T>  
inline void GetNumber(T &Number) {                                      //Super cool way to read ints
    
    Number = 0;                                                         //Set to 0
    T NumberSign = 1;                                                   //Sign all ok
    char CurrentChar = getchar_unlocked();                              //Read a char
 
    while (CurrentChar < '0' or CurrentChar > '9') {                    //If we are not reading numbers
        if (CurrentChar == '-')  NumberSign = -1;                       //If we have found the sign
        CurrentChar = getchar_unlocked();                               //Read the next char
    }

    while (CurrentChar >= '0' and CurrentChar <= '9') {                 //While we read numbers
        Number = (Number << 3) + (Number << 1) + (CurrentChar - '0');   //Multiply by 10
        CurrentChar = getchar_unlocked();                               //Read the next char
    }

    Number *= NumberSign;                                               //If negative
}

```

Now you just do something like:
```cpp
long long int Size;
GetNumber<long long int>(Size);

long long int Data[Size];
for (int i = 0; i < Size; ++i) 
    GetNumber<int>(Data[i]);
```



## Contests
