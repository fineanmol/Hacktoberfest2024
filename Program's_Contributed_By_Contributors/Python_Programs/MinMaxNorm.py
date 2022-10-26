# Min Max Normalization method
class MinMaxNorm:
    def __init__(self, data):
        self.data = data
    def calculate(self):
        data_norm = self.data.copy()
        for i, da in enumerate(data_norm):
            maxi = max(da)
            mini = min(da)
            for j, d in enumerate(da):
                data_norm[i][j] = (d-mini)/(maxi-mini)
        return data_norm

sample_data = [[1,2,3], [5,6,7]]
data_norm = MinMaxNorm(sample_data).calculate()
print(data_norm) #output: [[0.0, 0.5, 1.0], [0.0, 0.5, 1.0]]