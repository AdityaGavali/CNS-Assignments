from cryptography.fernet import Fernet
key = Fernet.generate_key()
cipher_suite = Fernet(key)
input_image_path = input("Enter the path of the image")
with open(input_image_path,"rb") as file : 
    image_data = file.read()
encrypted_data = cipher_suite.encrypt(image_data)
encyrpted_image_path = "encrypted_image.bin"
with open(encyrpted_image_path,"wb")  as file:
    file.write(encrypted_data)   
print("Image encrypted and saved as 'encrypted_image.bin'. Transmit this file securely.")
decrypted_data = cipher_suite.decrypt(encrypted_data)
decrypted_file_path = "decrypted_image.jpg"
with open(decrypted_file_path, "wb") as file:
    file.write(decrypted_data)
print("Image decrypted and saved as 'decrypted_image.jpg'.")        