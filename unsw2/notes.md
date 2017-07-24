1. prime finding ; NlogN when check through prime each time ( instead of all )
2. GCD:
    - gcd(a,b) = gcd(a, b-a)
    - gcd(a, 0) = a
    - gcd(a, b) = gcd(a, b mod a) :: this is used for the gcd algorithm
3. Eculedian method of finding GCD:
    - x, y | a*x + b*y = gcd(a, b)
    ``` c++
    int gcd(int a, int b, int &x, int &y){
        if a == 0 :{ x=0, y =1; return b;}
        int x1, y1;
        int d = gcd (b % a, a, x1, y1);
        x = y1 - (b/a) * x1;
        y = x1;
        return d;
    }
    ```
3. binomial coefficient
    - to get modulo inverse of a number
    - a * a^-1 === 1 (mod m)
    - gcd (a, m) = 1

    - a ^ (m - 1) === 1 (mod m), m prime

    * use eucleudim algo for this
    * a x +m y = 1
    * ax -1 = -y....

4. fast exp
- a^n = a ^ (n/2) * a ^ (n/2)
- a^(m-2) = a^-1 ( mod m)
-  a, a^2, a^4 ... a^(2^x)
- use mask: `a & (1 << i)`
- `(1 << i) = 2 ^ i`
``` c++
// Complexity O(logN)
// use long long for this
int power[33] = {1,0};
// make a power table
for (int i = 1, aa = a; i < 32; ++i){
    power[i] = aa;
    aa *= aa;
    aa %= m;
}

for ( int i = 0 to 32){
    if ( n & (1 << i)){
        x *= power[i];
    }
    x %= m,
}
```
5. x  = 2n, n is natural number, x = a + b, a,b are prime "1+1" prob
    - given a even N,`` 3 < N < 1e6+10``
    - steps
        1. make a prime table
        2. check each and it's complement
        3. Complexity of NlogN


6. `binomial coe (n, k) mod 10 ^ 4 + 7, 0 <= k <=10^5`
    - binomial coe -> fact(n) / ( fact(k) * fact(n-k))
    - (n! mod m) * (k! (n - k)!)^-1
