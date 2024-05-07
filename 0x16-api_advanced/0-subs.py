#!/usr/bin/python3
"""Module for querying the Reddit API"""


def number_of_subscribers(subreddit):
    """Query the Reddit API and returns the number of subscribers
    to the subreddit
    """
    import requests

    if subreddit is None or not isinstance(subreddit, str):
        return 0

    headers = {"User-Agent": "Mozilla/5.0"}
    url = "https://www.reddit.com/r/{}/about.json".format(subreddit)
    response = requests.get(url, headers=headers)

    if response.status_code != 200:
        return 0

    return response.json().get("data").get("subscribers")
