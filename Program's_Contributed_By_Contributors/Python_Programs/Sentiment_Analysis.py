%matplotlib inline
from textblob import TextBlob
import sys
import tweepy
import matplotlib.pyplot as plt

feeback1="the food was awesome"
feedback2="the food was very good"
blob1=TextBlob(feeback1)
blob2=TextBlob(feedback2)
print(blob1.sentiment)
print(blob2.sentiment)

def percentage(part,whole):
    return 100 * float(part)/float(whole)

ckey="<your ckey>"
csecret="<your csecret>"
atoken="<your atoken>"
asecret="<your asecret>"

auth=tweepy.OAuthHandler(ckey,csecret)
auth.set_access_token=(atoken,asecret)
api=tweepy.API(auth)

searchterm=input("enter keyword to search about ")
noofsearchterms=int(input("no of tweets to be analyzed: "))
tweets=tweepy.Cursor(api.search,q=searchterm,lang='en').items(noofsearchterms)


positive=0
negative=0
nuetral=0
polarity=0

for tweet in tweets:
    print(tweet.text)
    analysis=TextBlob(tweet.text)
    polarity+=analysis.sentiment.polarity
    
    if(analysis.sentiment.polarity==0):
        nuetral+=1
    elif(analysis.sentiment.polarity<0.00):
        negative+=1
    elif(analysis.sentiment.polarity>=0.00):
        positive+=1
positive=percentage(positive,noofsearchterms)
negative=percentage(negative,noofsearchterms)
nuetral=percentage(nuetral,noofsearchterms)

positive=format(positive, '.2f')
negative=format(negative, '.2f')
nuetral=format(nuetral, '.2f')


labels = ['Positive [' + str(positive) + '%]','Negative [' + str(negative) + '%]','Nuetral [' + str(nuetral) + '%]']

sizes=[positive,negative,nuetral]
colors=['yellowgreen','gold','red']
patches,texts=plt.pie(sizes,colors=colors,startangle=90)
plt.legend(patches,labels,loc="best")
plt.axis('equal')
plt.show()

tweetx=tweepy.Cursor(api.search,q=searchterm,lang='English').items(200)
document=[]
for tweet in tweetx:
    document.append(tweet.text)
document

import pandas as pd

df=pd.DataFrame(document)

df.to_csv('testing_data.csv')

df
