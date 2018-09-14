long countTipletsGeometricProgression(vector<long>& data, long ratio) {
    long counter {};
    map<long, long> element2, element3;

    for (auto now: data) {
        element2[now * ratio]++;
        if (element2.count(now)) element3[now * ratio] += element2[now];
        if (element3.count(now)) counter += element3[now];
    }

    return counter;
} 
