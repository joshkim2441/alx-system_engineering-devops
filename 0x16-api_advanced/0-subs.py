#!/usr/bin/python3
"""Module for querying the Reddit API"""
import requests


def number_of_subscribers(subreddit):
    """Query the Reddit API and returns the number of subscribers
    to the subreddit
    """


    if subreddit is None or not isinstance(subreddit, str):
        return 0

    headers = {"User-Agent": "Mozilla/5.0"}
    url = "https://www.reddit.com/r/{}/about.json".format(subreddit)
    response = requests.get(url, headers=headers, allow_redirects=False)

    return response.json().get("data").get("subscribers")
