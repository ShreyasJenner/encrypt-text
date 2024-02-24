import random

class operations:
    def is_prime(self,no):
        for i in range(2,no):
            if(no%i==0):
                return False
        return True

    # Return the first prime number greater than the seed number
    def generate_prime(self,seed):
        while True:
            if(self.is_prime(seed)):
                return seed
            seed += 1

    def gcd(self,a,b):
        if(a==0):
            return b
        return self.gcd(b%a,a)

class rsa_alg:
    def __init__(self):
        self.oper = operations() # operations class object
        self.lo = 10 # Lower limit of range
        self.hi = 1000 # Higher limit of range
        self.p = 0 # First prime number
        self.q = 0 # Second Prime number
        self.n = 0 # Product of p and q
        self.phi_n = 0 # Product of phi(p) and phi(q)
        self.e = 0 # Encryption exponent
        self.d = 0 # Decryption exponent

        self.generate_prime_pair()
        self.compute_n()
        self.compute_phi_n()
        self.find_e()
        self.find_d()


    def get_public_key(self):
        return (self.e, self.n)

    def get_private_key(self):
        return (self.d, self.n)

    def generate_prime_pair(self):
        r = random.randint(self.lo,self.hi)
        s = r
        while(s==r):
            s = random.randint(self.lo,self.hi)
        
        self.p = self.oper.generate_prime(r)
        self.q = self.oper.generate_prime(s)

        return (self.p,self.q)

    def compute_n(self):
        self.n = self.p * self.q
        return self.n
    
    def compute_phi_n(self):
        self.phi_n = (self.p-1)*(self.q-1)
        return self.phi_n

    def find_e(self):
        for i in range(3,self.phi_n):
            a = self.oper.gcd(i,self.phi_n)
            if(self.oper.gcd(i,self.phi_n)==1):
                self.e = i
                return i
        self.e = -1
        return -1

    def find_d(self):
        i = 1
        while True:
            k = (i*self.e)
            if(k%self.phi_n==1):
                self.d = i
                return i
            i += 1

class text_app:
    def __init__(self):
        self.rsa = rsa_alg() # stores the object of the rsa_alg class
        self.data = 0 # stores the number to be encrypted
        self.pub = self.rsa.get_public_key()
        self.pri = self.rsa.get_private_key()

    def display_keys():
        print("public",self.pub)
        print("private",self.pri)

    def encrypt(self,data):
        return (data**self.pub[0])%self.pub[1]
    
    def decrypt(self,data):
        return (data**self.pri[0])%self.pri[1]


if __name__=='__main__':
    ta = text_app()

    print(ta.encrypt(200))
    print(ta.decrypt(ta.encrypt(200)))