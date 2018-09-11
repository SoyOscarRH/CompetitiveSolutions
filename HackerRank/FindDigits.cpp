int findDigits(int num) {
    int temporalNum {num}, result {0};
    
    for (int temporalNum {num}, digit; temporalNum > 0; temporalNum /= 10) {
        digit = temporalNum % 10;
        if (digit and num % digit == 0) result++;
    }
    return result;
}