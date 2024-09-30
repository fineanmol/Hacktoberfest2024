import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    # df.loc[condition, [columns]]
    return students.loc[students["student_id"] == 101, ["name", "age"]]