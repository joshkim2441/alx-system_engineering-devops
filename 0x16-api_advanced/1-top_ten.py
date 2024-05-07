#!/usr/bin/python3
"""Print the titles of the first 10 hot posts listed in the subreddit
"""
import requests
def top_ten(subreddit):
    headers = {"User-Agent": "Mozilla/5.0"}
    response = requests.get("https://www.reddit.com/r/{}/hot.json?limit=10".format(subreddit),
                            headers=headers, allow_redirects=False)
    if response.status_code != 200:
        print(None)
    else:
        for post in response.json()["data"]["children"]:
            print(post["data"]["title"])
