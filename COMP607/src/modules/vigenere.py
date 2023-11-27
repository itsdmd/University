# Vigenere Cipher


def encrypt(message, key):
    # Convert all characters in key array to uppercase, and convert to numbers in range 0-25
    key = [ord(k.upper()) - 65 for k in key]

    encrypted = ""
    case = []
    for char in message:
        if char.isupper():
            case.append(True)
        elif char.islower():
            case.append(False)
        else:
            case.append(None)
    message = message.upper()

    # For each character in the message, add the corresponding key value to the character ordinal value
    for i, char in enumerate(message):
        if char.isalpha():
            number = ord(char)
            number += key[i % len(key)]
            number -= 65
            number %= 26
            number += 65
            char = chr(number)
            if not case.pop(0):
                char = char.lower()
        encrypted += char
    return encrypted


def decrypt(message, key):
    key = [ord(k.upper()) - 65 for k in key]

    decrypted = ""
    case = []
    for char in message:
        if char.isupper():
            case.append(True)
        elif char.islower():
            case.append(False)
        else:
            case.append(None)
    message = message.upper()

    # For each character in the message, subtract the corresponding key value from the character ordinal value
    for i, char in enumerate(message):
        if char.isalpha():
            number = ord(char)
            # Wrap around if index is larger than key length
            number -= key[i % len(key)]
            number -= 65
            number %= 26
            number += 65
            char = chr(number)
            if not case.pop(0):
                char = char.lower()
        decrypted += char
    return decrypted
