import numpy as np

def gauss(x, mu, sigma):
    N, D = x.shape
    c1 = 1 / (2 * np.pi)**(D / 2)
    c2 = 1 / (np.linalg.det(sigma)**(1 / 2))
    print("c2 = " + str(c2))
    inv_sigma = np.linalg.inv(sigma)
    print("inv_sigma = " + str(inv_sigma))
    c3 = x - mu
    print("c3 = " + str(c3))
    c4 = np.dot(c3, inv_sigma)
    print("c4 = " + str(c4))
    c5 = np.zeros(N)
    for d in range(D):
        print("i = " + str(d))
        print(c4[:, d] , c3[:, d])
        print(c4[:, d] * c3[:, d])
        print("c5" + str(c5))
        print(c5 + c4[:, d] * c3[:, d])
        c5 = c5 + c4[:, d] * c3[:, d]
    p = c1 * c2 * np.exp(-c5 / 2)
    return p

x = np.array([[1, 2], [2, 1], [3, 4]])
mu = np.array([1, 2])
sigma = np.array([[1, 0], [0, 1]])
print(gauss(x, mu, sigma))