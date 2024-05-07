#!/usr/bin/python3

import requests


def number_of_subscribers(subreddit):
    headers = {"User-Agent": "Mozilla/5.0"}
    response = requests.get("https://www.reddit.com/r/{}/about.json".
                            format(subreddit), headers=headers,
                            allow_redirects=False)

    if response.status_code != 200:
        return 0

    return response.json()["data"]["subscribers"]
