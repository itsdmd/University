# Information Security Technologies COMP607</br>Assignment 1

Student Name: **Dao Minh Duc**

AUT Student ID: **23199710**

## 1.

Key: 4

Plaintext message: **"A good name is better than good habits"**

![01](./img/01.png)

## 2.

### a.

With 7 bits per character, there are 128 possible values for each character in the password. With 10 such characters in a password, the key space of the password will have the size of 128^10.

### b.

There are 10 7-bit characters in the password. Therefore, the key length in bits of it is: 10 \* 7 = 70 bits.

### c.

If only 26 lowercase characters are used, we only need at most 5 bits per character to encode the password. Therefore, the key length in bits in this case will be: 10 \* 5 = 50 bits.

### d.

(i) $128 / 7 = 18$. Therefore, we need at least 18 7-bit characters.

(ii) $128 / 5 = 25.2$. Therefore, we need at least 26 characters.

## 3.

The bit sequence that appears the most frequent is `00011111`, so using frequency attack, we can assume that this sequence represents letter "e", which has the ASCII encode of `01100101`. Therefore, we can assume that the key of this cipher text is: `0b01100101 - 0b00011111 = 0b01000110`.

With that key, we can work out the rest of the message by adding it to the bits in the cipher text.

- `0b00010111 + 0b01000110 = 0b01011101 = m`
- `0b00001110 + 0b01000110 = 0b01010100 = t`
- `0b00011011 + 0b01000110 = 0b01100001 = a`
- `0b00010110 + 0b01000110 = 0b01101100 = l`
- `0b00001100 + 0b01000110 = 0b01110110 = v`
- `0b00010100 + 0b01000110 = 0b01101110 = n`

The decrypted cipher text is: "meetatelevenam"

This can be interprteted in plaintext as: "Meet at eleven AM"

## 4.

![](./img/04-01.png)

![](./img/04-02.png)

Therefore, `putty-0.70-installed.msi` is the good copy.

## 5.

### a.

![](./img/05-01-01.png)

![](./img/05-01-02.png)

### b.

![](./img/05-02.png)

Therefore, `notice2.hmac.txt` is the authentic version.

## 6.

### a.

![](./img/06-01.png)

### b.

![](./img/06-02v2.png)

Conclusion: `test1.txt` and `test2.txt` plaintext files only differs in the last byte (`!` character), but their MD5 hash values are completely different.

### c.

![](./img/06-03.png)

## 7.

### a.

$M = 513, p = 23, q = 29$

$\Rarr N = p \times q = 23 \times 29 = 667$

$\Rarr \phi(N) = (p - 1) \times (q - 1) = 22 \times 28 = 616$

</br>

Select $e = 3$

$\Rarr d = e^{-1} \mod \phi(N) = 3^{-1} \mod 616 = 411$

Public key: $(e, N) = (3, 667)$

Private key: $(d, N) = (411, 667)$

</br>

Encrypt $M = 513$ using public key:

$C = M^d \mod N = 513^{411} \mod 667 = 198$

</br>

Decrypt $C = 198$ using private key:

$M = C^e \mod N = 198^3 \mod 667 = 513$

### b.

$M = 109, p = 11, q = 23$

$\Rarr N = p \times q = 11 \times 23 = 253$

$\Rarr \phi(N) = (p - 1) \times (q - 1) = 10 \times 22 = 220$

</br>

Select $e = 3$

$\Rarr d = e^{-1} \mod \phi(N) = 3^{-1} \mod 220 = 147$

Signature: $S = M^d \mod N = 109^{411} \mod 253 = 109$

</br>

Verify signature:

$M = S^e \mod N = 109^3 \mod 253 = 109$

The signature is verified.

## 8.

### a.

First, Alice and Bob agree on a prime number $n = 4787$ and a generator $g = 2$.

Then, they each choose a secret number, $a$ and $b$, respectively.

Alice chooses $a = 3$ and Bob chooses $b = 5$.

They then calculate their public keys as follows:

Alice: $A = g^a \mod n = 2^3 \mod 4787 = 8$

Bob: $B = g^b \mod n = 2^5 \mod 4787 = 32$

They then exchange their public keys.

Alice receives Bob's public key, $B = 32$, and calculates the shared key as follows:

$K = B^a \mod n = 32^3 \mod 4787 = 4046$

Bob receives Alice's public key, $A = 8$, and calculates the shared key as follows:

$K = A^b \mod n = 8^5 \mod 4787 = 4046$

Both Alice and Bob now have a shared key, $K = 4046$.

### b.

Both Alice and Bob can determine the value of the shared key. The shared key is calculated using the public key of the other party and the secret key of the party itself.

## 9.

The DH algorithm can also be used for encryption as well using the ElGamal scheme. Demonstrate this encryption scheme using a numerical example as follows.

Alice wish to encrypt a secret message, M = 215 to Bob. They have chosen the parammeters and private keys as follows:
Bob: private key b = 231, generator G=2, prime modulus p = 443.
Alice: private key a = 198

Demonstrate how the scheme works by showing what each party computes and sends to each other, showing clearly the cipher texts, and the decrypted messages.
(i) using the above numbers for M, a, b
(ii) using your own choice of numbers for M, a, b

### i.

$M = 215, a = 198, b = 231, G = 2, p = 443$

Alice calculates her public key:

$A = G^a \mod p = 2^{198} \mod 443 = 144$

Bob calculates his public key:

$B = G^b \mod p = 2^{231} \mod 443 = 305$

Alice sends her public key, $A = 144$, to Bob.

Bob sends his public key, $B = 305$, to Alice.

Alice computes the shared key:

$K = B^a \mod p = 305^{198} \mod 443 = 321$

Alice encrypts the message:

$C = M \times K \mod p = 215 \times 321 \mod 443 = 350$

Alice sends the cipher text, $C = 350$, to Bob.

Bob derives the shared key:

$K = A^b \mod p = 144^{231} \mod 443 = 321$

Bob decrypts the message:

$M = C \times K^{-1} \mod p = 350 \times 321^{-1} \mod 443 = 215$
