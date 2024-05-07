#!/usr/bin/python3
"""Module for querying the Reddit API"""


def number_of_subscribers(subreddit):
    """Query the Reddit API and returns the number of subscribers
    to the subreddit
    """
    import requests

    headers = {"User-Agent": "Mozilla/5.0"}
    response = requests.get("https://www.reddit.com/r/{}/about.json".
                            format(subreddit), headers=headers,
                            allow_redirects=False)

    if response.status_code >= 300:
        return 0

    return response.json().get("data").get("subscribers")
