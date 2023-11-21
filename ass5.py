import hashlib
def sha1(message):
    sha1_hash = hashlib.sha1(message.encode()).hexdigest()
    return sha1_hash

message = input("Enter the message to be hashed: ")
hash_value = sha1(message)
print("SHA-1 Hash of the message:", hash_value)
print("First 8 characters of the hash:", hash_value[:8])
#pip install hashlib

