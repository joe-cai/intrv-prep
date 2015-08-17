#Fraction to Recurring Decimal
```C++
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if (numerator == 0) return "0";
        int64_t nume = numerator, denom = denominator;
        if (nume < 0 ^ denom < 0) res += '-';
        nume = abs(nume), denom = abs(denom);
        res += to_string(nume / denom);
        if (nume % denom == 0) return res;

        res.push_back('.');
        unordered_map<int, int> recur;
        nume = nume % denom;
        while (nume != 0 && recur.count(nume) == 0) {
            recur[nume] = res.size();
            nume *= 10;
            res += to_string(nume / denom);
            nume = nume % denom;
        }
        if (nume == 0) return res;
        res.insert(res.begin() + recur[nume], '(');
        res.push_back(')');
        return res;
    }
};
```
