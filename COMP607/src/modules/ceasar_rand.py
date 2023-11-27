# This cipher use a predefined substitution table instead of shifting. Key is an array of strings.


def encrypt(message, key):
    # Convert all characters in key array to uppercase
    key = [k.upper() for k in key]

    encrypted = ""

    # Array to store the case state of each character
    case = []

    # Loop through each character in the message
    for char in message:
        if char.isupper():
            case.append(True)
        elif char.islower():
            case.append(False)
        else:
            case.append(None)

    # Convert the message to uppercase
    message = message.upper()

    # Loop through each character in the message and substitute
    for char in message:
        # If the character is a letter
        if char.isalpha():
            # Convert the character to a number
            number = ord(char)

            # Subtract 65 to get the number in the range 0-25
            number -= 65

            # Substitute the character
            char = key[number]

            # If the character was originally lowercase, convert it back to lowercase
            if not case.pop(0):
                char = char.lower()

        # Add the character to the encrypted message
        encrypted += char

    return encrypted


def decrypt(cipher, key):
    # Convert all characters in key array to uppercase
    key = [k.upper() for k in key]

    decrypted = ""

    # Array to store the case state of each character
    case = []

    # Loop through each character in the message
    for char in cipher:
        if char.isupper():
            case.append(True)
        elif char.islower():
            case.append(False)
        else:
            case.append(None)

    # Convert the message to uppercase
    cipher = cipher.upper()

    # Loop through each character in the message and substitute
    for char in cipher:
        # If the character is a letter
        if char.isalpha():
            # Convert the character to a number
            number = ord(char)

            # Subtract 65 to get the number in the range 0-25
            number -= 65

            # Find the index of the character in the key array
            index = key.index(char)

            # Convert the index to the number in the Unicode range
            char = index + 65

            # Convert the number back to a character
            char = chr(char)

            # If the character was originally lowercase, convert it back to lowercase
            if not case.pop(0):
                char = char.lower()

        # Add the character to the encrypted message
        decrypted += char

    return decrypted
