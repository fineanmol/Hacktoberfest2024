
# coding: utf-8

# ### 1) IMPORTING IMPORTANT LIBRARIES:

# In[3]:


# INSTALLING NLTK, GENSIM AND WORDCLOUD
get_ipython().system('pip install --upgrade pip')
get_ipython().system('pip install nltk')
get_ipython().system('pip install gensim')
get_ipython().system('pip install wordcloud')

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from wordcloud import WordCloud, STOPWORDS
import nltk
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize
import gensim
from gensim.utils import simple_preprocess
from gensim.utils import simple_preprocess
from gensim.parsing.preprocessing import STOPWORDS
from sklearn.metrics import classification_report, confusion_matrix


# In[4]:


resume_df = pd.read_csv('Dataset/resume.csv', encoding = 'latin-1')
resume_df


# In[5]:


resume_df = resume_df[['resume_text', 'class']]
resume_df


# ### 2) PERFORMING EXPLORATORY DATA ANALYSIS:

# In[6]:


resume_df.info()


# In[7]:


resume_df['class'].value_counts()


# In[8]:


# HERE WE OBSERVE, WE HAVE NO NULL POINTS IN OUR DATASET
resume_df['class'] = resume_df['class'].apply(lambda x:1 if x == 'flagged' else 0)
resume_df


# ### 4) PERFORMING DATA CLEANING:

# In[9]:


# PREMOVING UNNECESSARY WORDS FROM DATASET

resume_df['resume_text'] = resume_df['resume_text'].apply(lambda x: x .replace('\r', ''))

nltk.download('punkt')
nltk.download('stopwords')

from nltk.corpus import stopwords

stop_words = stopwords.words('english')

stop_words.extend(['from', 'subject', 'edu', 're', 'use', 'email', 'com'])

def preprocess(text):
    result = []
    for token in gensim.utils.simple_preprocess(text):
        if token not in gensim.parsing.preprocessing.STOPWORDS and len(token) > 2 and token not in stop_words:
            result.append(token)
    return ' '.join(result)


# In[10]:


resume_df


# In[11]:


resume_df['cleaned'] = resume_df['resume_text'].apply(preprocess)

resume_df


# In[12]:


resume_df['cleaned'][0]


# ### 5) VISUALIZING CLEANED DATASETS

# In[13]:


# PLOTTING COUNTS OF SAMPLE LABELLED AS 1 AND 0
sns.countplot(resume_df['class'], label = 'Count Plot')
plt.show()


# In[15]:


# PLOTTING THE WORDCLOUD:

# 1) FOR CLASS 1:

get_ipython().magic('matplotlib inline')

plt.figure(figsize = (20, 20))

wc = WordCloud(max_words = 2000, width = 1600, height = 800, stopwords = stop_words).generate(str(resume_df[resume_df['class']==1].cleaned))

plt.imshow(wc)


# In[16]:


#1) FOR CLASS 0:

get_ipython().magic('matplotlib inline')

plt.figure(figsize = (20, 20))

wc = WordCloud(max_words = 2000, width = 1600, height = 800, stopwords = stop_words).generate(str(resume_df[resume_df['class']==0].cleaned))

plt.imshow(wc)


# ### 6) PREPARING THE DATA BY APPLYING COUNT VECTORIZATION:

# In[17]:


# CONVERTING SENTENCES INTO TOKENIZED FORMS AND THEN CONVERTING TO NUMERICAL VALUES IN ORDER FOR THE MODEL TO TRAIN:

from sklearn.feature_extraction.text import CountVectorizer

vectorizer = CountVectorizer()
countvectorizer = vectorizer.fit_transform(resume_df['cleaned'])

print(vectorizer.get_feature_names())


# In[18]:


# PROCESSED DATA:
print(countvectorizer.toarray())


# ### 7) TRAINING A NAIVE BAYES CLASSIFER:

# In[89]:


X = countvectorizer
y = resume_df['class']

from sklearn.model_selection import train_test_split


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2)


from sklearn.naive_bayes import MultinomialNB

Bayes_clf = MultinomialNB(alpha = 3)
Bayes_clf.fit(X_train, y_train)  ## Training the model


# ### 8) ASSESING THE TRAINED MODEL:

# In[90]:


get_ipython().magic('matplotlib inline')

# PLOTTING CONFUSION MATRIX:

# 1) FOR TRAINING DATA

y_pred_train = Bayes_clf.predict(X_train)

cm = confusion_matrix(y_train, y_pred_train)

sns.heatmap(cm, annot=True)

plt.show()


# In[91]:


get_ipython().magic('matplotlib inline')

# WE CAN SEE OUR MODEL PERFORMED REALLY WELL ON TRAINING DATA: IT CLASSFIED ALL OF THE POINTS CORRECTLY

# 2) FOR TEST DATA:

y_pred_test = Bayes_clf.predict(X_test)

cm = confusion_matrix(y_test, y_pred_test)

sns.heatmap(cm, annot=True)

plt.show()


# In[92]:


print(classification_report(y_test, y_pred_test))


# In[93]:


from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, roc_auc_score

print("Accuracy of model on Train Dataset = {}".format(accuracy_score(y_train, y_pred_train)))
print("Accuracy of model on Test Dataset = {}".format(accuracy_score(y_test, y_pred_test)))


# In[95]:


print("Accuracy of model is = {}".format(accuracy_score(y_test, y_pred_test)))
print("F1 of model is = {}".format(f1_score(y_test, y_pred_test)))
print("Precision of model is = {}".format(precision_score(y_test, y_pred_test)))
print("Recall of model is = {}".format(recall_score(y_test, y_pred_test)))


# In[ ]:




