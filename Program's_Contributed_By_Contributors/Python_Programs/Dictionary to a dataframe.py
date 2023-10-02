import pandas as pd
def create_df():
    data = {'name': ['Alice', 'Bob', 'Carl', 'Dave'],
            'age': [18, 22, 34, 67],
            'income': [100000, 99000, 24000, 44000]}
    df = pd.DataFrame(data)
    return df