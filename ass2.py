import time 

def gcd(a,b):
    while(b):
        a,b = b,a%b
    return a
    
def generate_key():
    p = 29
    q = 11
    n = p*q
    phi = (p-1)*(q-1)
    e = 2
    while e<phi and gcd(e,phi)!= 1:
        e = e+1
    d= 0
    while (e*d)%phi != 1:
        d = d+1
    return e,d,n

def rsa_encrypt(msg,e,n):
    encrypt = []
    for ch in msg:
        encrypt.append(pow(ord(ch),e,n))
    return encrypt

def rsa_decrypt(encrypt,d,n):
    decrypted_message = []
    for i in encrypt:
        decrypted_message.append(chr(pow(i,d,n)))
    return ''.join(decrypted_message)


msg = input("Enter the message : ")
start_time = time.time()
e,d,n = generate_key()
key_gen_time = time.time()-start_time

start_time = time.time()
encrypt = rsa_encrypt(msg,e,n)
encrypt_time = time.time()-start_time

start_time = time.time()
decrypt = rsa_decrypt(encrypt,d,n)
decrypt_time = time.time()-start_time

print("Key generation time : ", key_gen_time)
print("Encrypted message : ",  encrypt)
print("Decrypted message : ",  decrypt)
print("Encryption Time : ", encrypt_time)
print("Decryption Time : ", decrypt_time)




