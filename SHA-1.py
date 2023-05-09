import hashlib

def sha1(string):
    hash_object = hashlib.sha1(string.encode())
    return hash_object.hexdigest()
    
 print(sha1("Test 1"))