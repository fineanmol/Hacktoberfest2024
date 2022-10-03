import tweepy
import csv 

api_key = "YOUR_API_KEY"
api_key_secret = "YOUR_API_SECRET_KEY"
bearer_token = "YOUR_BEARER_TOKEN"
bearer_token_secret = "YOUR_BEARER_TOKEN_SECRET"

# Verifying Credentials
auth = tweepy.OAuthHandler(api_key, api_key_secret)
auth.set_access_token(bearer_token, bearer_token_secret)
api = tweepy.API(auth)

try:
	api.verify_credentials()
	print("Authentication OK")
	tweets = tweepy.Cursor(api.search_tweets, q="bjorka").items()

	# CMD
	#for tweet in tweets:
	#	print(tweet.created_at, tweet.user.name,'\n',tweet.text)
	#	print('\n')
	
	# Flat File
	#with open('tweet.txt', 'a+', newline='', encoding="utf-8") as file:	
	#	try:
	#		i = 0
	#		for tweet in tweets:
	#			file.write(str(tweet.created_at))
	#			file.write('\n')
	#			file.write(tweet.user.name)
	#			file.write('\n')
	#			file.write(tweet.text)
	#			file.write('\n')
	#			file.write('\n')
	#			print(i)
	#			i = i + 1
	#		file.close()
	#	except Exception as e:
	#		print(e)
	
	# CSV
	with open('tweet.csv', 'a', newline='', encoding="utf-8") as file:
		try:
			writer = csv.writer(file)
			i = 0
			for tweet in tweets:
				tw = [tweet.created_at,tweet.user.name,tweet.text,tweet.user.location]
				writer.writerow(tw)
				print(i)
				i = i + 1
		except Exception as e:
			print(e)
except Exception as e:
    print(e)
