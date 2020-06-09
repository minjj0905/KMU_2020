import numpy as np
import matplotlib.pyplot as plt

# 데이터 생성 (일일 평균 학습량 - 평균평점)
np.random.seed(seed=11)
X_min = 1
X_max = 8
X_n = 20
X = np.round(1 + 7*np.random.rand(X_n), 2)
T = np.round(4.0 - 3.0 * np.exp(-0.2 * X), 2)

print(X)
print(T)