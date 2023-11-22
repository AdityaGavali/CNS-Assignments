
p,q = 23,5

alice_private = int(input("Enter alice private key :"))
bob_private = int(input("Enter bob private key: "))
evePrivate =  int(input("Enter eve private key: "))
alice_public = pow(q,alice_private,p)
bob_public = pow(q,bob_private,p)
eve_public = pow(q,evePrivate,p)


s1 = pow(bob_public,alice_private,p)
s2 = pow(alice_public,bob_private,p)

#MIM
# s1 = pow(eve_public,alice_private,p)
# s2 = pow(eve_public,bob_private,p)
print(s1)
print(s2)
if s1==s2:
    print("No intervention, communication successful")
else:
    print("Man in the middle detected")    
