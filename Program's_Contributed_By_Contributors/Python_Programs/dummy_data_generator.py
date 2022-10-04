from faker import Faker
fake = Faker()
print(fake.name())
print(fake.address())
print(fake.text())
from faker import Faker
import pandas as pd
fake = Faker()
data = [fake.profile() for i in range(50)]
data = pd.DataFrame(data)
print(data.head())
