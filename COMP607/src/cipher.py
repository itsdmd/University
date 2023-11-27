import argparse

parser = argparse.ArgumentParser(
    description="Encrypt or decrypt a message using various ciphers"
)

parser.add_argument(
    "-c",
    "--cipher",
    type=str,
    help="Cipher to use for encryption/decryption\nOptions: ceasar/c, ceasar_rand/cr, vigenere/v, railfence/rf",
)
parser.add_argument("-e", "--encrypt", action="store_true", help="Encrypt a message")
parser.add_argument("-d", "--decrypt", action="store_true", help="Decrypt a message")
parser.add_argument(
    "-k",
    "--key",
    type=str,
    help="Key to use for encryption/decryption. Example: '3' means A becomes D, B becomes E, etc.",
)
parser.add_argument("-m", "--message", type=str, help="Message to encrypt/decrypt")

args = parser.parse_args()


if args.cipher == "ceasar" or args.cipher == "c":
    import modules.ceasar as ceasar

    if args.encrypt:
        print(ceasar.encrypt(args.message, args.key))
    elif args.decrypt:
        print(ceasar.decrypt(args.message, args.key))
    else:
        print("Please specify whether to encrypt or decrypt the message using -e or -d")

elif args.cipher == "ceasar_rand" or args.cipher == "cr":
    import modules.ceasar_rand as ceasar_rand

    # Parse the input key string into array.
    # The string is split by commas.
    key = []
    for k in args.key.split(","):
        key.append(k)

    if args.encrypt:
        print(ceasar_rand.encrypt(args.message, key))
    elif args.decrypt:
        print(ceasar_rand.decrypt(args.message, key))
    else:
        print("Please specify whether to encrypt or decrypt the message using -e or -d")

elif args.cipher == "vigenere" or args.cipher == "v":
    import modules.vigenere as vigenere

    if args.encrypt:
        print(vigenere.encrypt(args.message, args.key))
    elif args.decrypt:
        print(vigenere.decrypt(args.message, args.key))
    else:
        print("Please specify whether to encrypt or decrypt the message using -e or -d")

elif args.cipher == "railfence" or args.cipher == "rf":
    import modules.railfence as railfence

    if args.encrypt:
        print(railfence.encrypt(args.message, args.key))
    elif args.decrypt:
        print(railfence.decrypt(args.message, args.key))
    else:
        print("Please specify whether to encrypt or decrypt the message using -e or -d")
