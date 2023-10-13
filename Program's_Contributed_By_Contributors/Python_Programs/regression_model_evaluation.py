import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Load and preprocess your dataset
df = pd.read_csv('./custom_data.csv')
# ... Preprocessing steps ...
# Assuming 'University Rating' is a categorical feature
df['University Rank Category'] = 'U' + df['University Rating'].astype(str)

# Define the categorical columns you want to one-hot encode
categorical_columns = ['University Rank Category']  # Add more columns if needed

# Perform one-hot encoding on categorical columns
df_encoded = pd.get_dummies(df, columns=categorical_columns, drop_first=True)

# Define features and target variable
X = df_encoded.drop('Chance of Admit ', axis=1)
y = df_encoded['Chance of Admit ']

# Split the dataset into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Initialize models for analysis
models = {
    'Random Forest': RandomForestRegressor(),
    'Linear Regression': LinearRegression()
}

# Create a dictionary to store MSE values for each model and category
mse_results = {model_name: [] for model_name in models.keys()}

# Loop through each University Rank Category
for category in df['University Rank Category'].unique():
    print(f"University Rank Category: {category}")

    # Filter data for the current category
    column_name = 'University Rank Category_' + category
    # category_data = df_encoded[df_encoded[column_name] == 1]

    # Prepare datasets for the current category
    X_train_category = X_train[X_train.index.isin(category_data.index)]
    X_test_category = X_test[X_test.index.isin(category_data.index)]
    y_train_category = y_train[y_train.index.isin(category_data.index)]
    y_test_category = y_test[y_test.index.isin(category_data.index)]

    # Train and evaluate selected models
    for model_name, model in models.items():
        print(f"\nModel: {model_name}")

        # Train the model
        model.fit(X_train_category, y_train_category)

        # Make predictions
        y_pred = model.predict(X_test_category)

        # Calculate MSE
        mse = mean_squared_error(y_test_category, y_pred)
        mse_results[model_name].append(mse)

# Create a DataFrame from the mse_results dictionary
mse_df = pd.DataFrame(mse_results)

# Plot a bar chart
mse_df.plot(kind='bar', xlabel='University Rank Category', ylabel='Mean Squared Error',
            title='Mean Squared Error by Model and University Rank Category')
plt.xticks(rotation=0)
plt.legend(title='Model')
plt.show()