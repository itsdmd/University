def encrypt(message, key):
    key = int(key)

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

    # Loop through each character in the message
    for char in message:
        # If the character is a letter
        if char.isalpha():
            # Convert the character to a number
            number = ord(char)

            # Add the key to the number
            number += key

            # Subtract 65 to get the number in the range 0-25
            number -= 65

            # Use modulo to wrap the number around the alphabet
            number %= 26

            # Add 65 to get the number back in the Unicode range
            number += 65

            # Convert the number back to a character
            char = chr(number)

            # If the character was originally lowercase, convert it back to lowercase
            if not case.pop(0):
                char = char.lower()

        # Add the character to the encrypted message
        encrypted += char

    return encrypted


def decrypt(cipher, key):
    key = int(key)
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

    # Loop through each character in the message
    for char in cipher:
        # If the character is a letter
        if char.isalpha():
            # Convert the character to a number
            number = ord(char)

            # Subtract the key from the number
            number -= key

            # Subtract 65 to get the number in the range 0-25
            number -= 65

            # Use modulo to wrap the number around the alphabet
            number %= 26

            # Add 65 to get the number back in the Unicode range
            number += 65

            # Convert the number back to a character
            char = chr(number)

            # If the character was originally lowercase, convert it back to lowercase
            if not case.pop(0):
                char = char.lower()

        # Add the character to the decrypted message
        decrypted += char

    return decrypted
