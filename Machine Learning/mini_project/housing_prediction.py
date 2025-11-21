# Building an end-to-end ML pipeline for housing price prediction

import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder, StandardScaler
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error
from sklearn.svm import SVR
from sklearn.tree import DecisionTreeRegressor
from xgboost import XGBRegressor

# Load and extract data
def load_data(file_path: str) -> pd.DataFrame:
    '''
    Load dataset from a zip or csv file and return as a pandas DataFrame.
    '''
    if file_path.endswith(".csv"):
        df = pd.read_csv(file_path)
    elif file_path.endswith(".zip"):
        df = pd.read_csv(file_path, compression='zip')
    else:
        raise ValueError("The provided file is not a .csv or .zip file.")
    
    return df

# Preprocess data
def preprocess_data(df: pd.DataFrame) -> pd.DataFrame:
    '''
    Preprocess the housing data by handling missing values and scaling features.
    '''
    # Handle missing values
    df_num = df.select_dtypes(include=[np.number])
    df_num = df_num.fillna(df_num.median())
    
    # Feature scaling for numeric features
    scaler = StandardScaler()
    numeric_features = df.select_dtypes(include=[np.number]).columns
    df[numeric_features] = scaler.fit_transform(df[numeric_features])

    # One-hot encoding for categorical features
    ohe = OneHotEncoder(sparse=False, handle_unknown='ignore')
    categorical_features = df.select_dtypes(include=['object']).columns
    if len(categorical_features) > 0:
        ohe_features = ohe.fit_transform(df[categorical_features])
        ohe_df = pd.DataFrame(ohe_features, columns=ohe.get_feature_names_out(categorical_features))
        df = df.drop(columns=categorical_features).reset_index(drop=True)
        df = pd.concat([df, ohe_df], axis=1)
    
    return df

# Feature engineering
def feature_engineering(df: pd.DataFrame) -> pd.DataFrame:
    '''
    Create new features from existing ones to enhance model performance.
    '''
    df['total_rooms_per_household'] = df['total_rooms'] / df['households']
    df['total_bedrooms_per_room'] = df['total_bedrooms'] / df['total_rooms']
    df['population_per_household'] = df['population'] / df['households']
    
    return df

# Split data into training and testing sets
def split_data(df: pd.DataFrame, target_column: str):
    '''
    Split the dataset into training and testing sets.
    '''
    X = df.drop(columns=[target_column])
    y = df[target_column]
    
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    
    return X_train, X_test, y_train, y_test

# Train model
def train_model_RandomForest(X_train: pd.DataFrame, y_train: pd.Series) -> RandomForestRegressor:
    '''
    Train a Random Forest Regressor on the training data.
    '''
    model = RandomForestRegressor(n_estimators=100, random_state=42)
    model.fit(X_train, y_train)
    
    return model

def train_model_DecisionTree(X_train: pd.DataFrame, y_train: pd.Series) -> DecisionTreeRegressor:
    '''
    Train a Decision Tree Regressor on the training data.
    '''
    model = DecisionTreeRegressor(random_state=42)
    model.fit(X_train, y_train)
    
    return model

def train_model_LinearRegression(X_train: pd.DataFrame, y_train: pd.Series) -> LinearRegression:
    '''
    Train a Linear Regression model on the training data.
    '''
    model = LinearRegression()
    model.fit(X_train, y_train)
    
    return model

def train_model_SupportVectorMachine(X_train: pd.DataFrame, y_train: pd.Series) -> SVR:
    '''
    Train a Support Vector Regressor on the training data.
    '''
    model = SVR()
    model.fit(X_train, y_train)
    
    return model

def train_model_XGBoost(X_train: pd.DataFrame, y_train: pd.Series) -> XGBRegressor:
    '''
    Train a XGBoost Classifier on the training data.
    '''
    model = XGBRegressor()
    model.fit(X_train, y_train)
    
    return model

# Evaluate model
def evaluate_model(model, X_test: pd.DataFrame, y_test: pd.Series) -> float:
    '''
    Evaluate the model using Mean Squared Error (MSE).
    '''
    y_pred = model.predict(X_test)
    mse = mean_squared_error(y_test, y_pred)
    
    return mse

# Select best model
def select_best_model(models: dict, X_test: pd.DataFrame, y_test: pd.Series):
    '''
    Select the best model based on evaluation metrics.
    '''
    best_model = None
    best_mse = float('inf')
    
    for name, model in models.items():
        mse = evaluate_model(model, X_test, y_test)
        print(f"Model: {name}, MSE: {mse}")
        if mse < best_mse:
            best_mse = mse
            best_model = model
            
    return best_model


# Main pipeline execution
if __name__ == "__main__":

    # Load data
    data_path = "../datasets/housing.csv"
    df = load_data(data_path)

    print(df.head()) # Display first 5 rows of the dataframe

    df.info() # Display summary of the dataframe

    print(df["ocean_proximity"].value_counts()) # Display counts of unique values in 'ocean_proximity' column, because it's categorical

    df.describe() # Display statistical summary of the dataframe

    # Preprocess data
    df = preprocess_data(df)

    df.head()
    df.info() 
    
    # Feature engineering
    df = feature_engineering(df)
    
    df.head() # Display first 5 rows after feature engineering
    
    # Split data
    X_train, X_test, y_train, y_test = split_data(df, target_column='median_house_value')
    
    # Train models
    models = {
        'RandomForest': train_model_RandomForest(X_train, y_train),
        'DecisionTree': train_model_DecisionTree(X_train, y_train),
        'LinearRegression': train_model_LinearRegression(X_train, y_train),
        'SupportVectorMachine': train_model_SupportVectorMachine(X_train, y_train),
        'XGBoost': train_model_XGBoost(X_train, y_train)
    }
    
    # Select best model
    best_model = select_best_model(models, X_test, y_test)
    print("Best model selected:", best_model)
