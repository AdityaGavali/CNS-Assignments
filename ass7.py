q,alpha = 29,11
private_key = int(input("Enter private key :  in between(2 to q-1)"))
public_key = pow(alpha,private_key,q)
m = int(input("Enter the value of m : "))
k = int(input("Enter the value of k : "))
s1 = pow(alpha,k,q)
kv = 1
while(kv*k)%(q-1) != 1:
    kv = kv+1
kinv = kv
dif = m-(private_key*s1)
s2 =  (kinv*dif)%(q-1)
v1 = pow(alpha,m,q)
v2 = (pow(public_key,s1,q)*pow(s1,s2,q))%q
if v1==v2 :
    print("Verified")
else:
    print("fail")



