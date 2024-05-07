#!/usr/bin/python3


def number_of_subscribers(subreddit):
    """Query the Reddit API and returns the number of subscribers
    to the subreddit
    """
    import requests

    headers = {"User-Agent": "My-User-Agent"}
    response = requests.get("https://www.reddit.com/r/{}/about.json".
                            format(subreddit), headers=headers,
                            allow_redirects=False)

    if response.status_code != 200:
        return 0

    return response.json().get("data").get("subscribers")
