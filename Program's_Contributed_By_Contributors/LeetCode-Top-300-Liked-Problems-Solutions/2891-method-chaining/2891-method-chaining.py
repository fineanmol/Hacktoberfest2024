def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    filtered_animals = animals[animals['weight'] > 100]
    sorted_animals = filtered_animals.sort_values(by='weight', ascending=False)
    names = sorted_animals[['name']]
    return names