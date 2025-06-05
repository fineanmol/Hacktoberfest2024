import re
from collections import Counter

# Function to preprocess and tokenize text
def preprocess_text(text):
    # Convert text to lowercase
    text = text.lower()
    
    # Remove special characters and numbers
    text = re.sub(r'[^a-z ]', '', text)
    
    # Tokenize the text into words
    words = text.split()
    
    return words

# Function to calculate the Jaccard similarity between two sets of words
def calculate_jaccard_similarity(set1, set2):
    intersection = len(set1.intersection(set2))
    union = len(set1) + len(set2) - intersection
    return intersection / union if union > 0 else 0

# Function to check for plagiarism
def check_plagiarism(text1, text2, threshold=0.5):
    words1 = set(preprocess_text(text1))
    words2 = set(preprocess_text(text2))
    
    similarity = calculate_jaccard_similarity(words1, words2)
    
    if similarity >= threshold:
        return True
    else:
        return False

# Example usage
if __name__ == "__main__":
    document1 = "This is a sample document for testing plagiarism detection."
    document2 = "This is a sample document used for testing plagiarism checker."
    
    is_plagiarized = check_plagiarism(document1, document2)
    
    if is_plagiarized:
        print("Plagiarism detected!")
    else:
        print("No plagiarism detected.")
