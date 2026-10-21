
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;

        if (n == 2)
            return true;

        if (n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        // Check every prefix
        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix = prefix * 10 + (s[i] - '0');

            if (!isPrime(prefix))
                return false;
        }

        // Check every suffix
        int suffix = 0;
        int power = 1;

        for (int i = n - 1; i >= 0; i--) {
            suffix = (s[i] - '0') * power + suffix;

            if (!isPrime(suffix))
                return false;

            power *= 10;
        }

        return true;
    }
};
