import hashlib

def md5(str):
    result = hashlib.md5(str.encode())
    return result.hexdigest()

print(md5("Test"))