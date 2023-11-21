import hashlib
def gcd(a,b):
    while b!=0:
        a,b = b,a%b
    return  a
def generate_keypair():
    p,q = 29,11
    phi = (p-1)*(q-1)
    n = p*q
    e = 2
    while e<phi and gcd(e,phi)!=1:
        e += 1
    d = 0
    while (d*e)%phi !=1:
        d += 1
    print(e,d)
    return e,d,n
def rsa_encrypt(message, e, n):
    encrypted_message = [pow(ord(char), e, n) for char in message]
    return encrypted_message
def rsa_decrypt(encrypted_message, d, n):
    decrypted_message = [chr(pow(c, d, n)) for c in encrypted_message]
    return ''.join(decrypted_message)
def generate_signature(msg,d,n):
    hashh = hashlib.sha256(msg.encode()).hexdigest()
    signature  = rsa_encrypt(hashh,d,n)
    return signature   
def verify_signature(msg,signature,e,n):
    hashh = hashlib.sha256(msg.encode()).hexdigest()
    decrypted_signature = rsa_decrypt(signature,e,n)
    return decrypted_signature==hashh
message = input("Enter message : \n")
e,d,n = generate_keypair()
cipher = rsa_encrypt(message,e,n)
signature = generate_signature(message,d,n)
original = rsa_decrypt(cipher,d,n)
print(original)
verifictation = verify_signature(message,signature,e,n)
if verifictation == True:
    print("Signature is valid. Message integrity verified.")
else:
    print("Message integrity failed")