#!/usr/bin/python3
"""Print the titles of the first 10 hot posts listed in the subreddit
"""


def top_ten(subreddit):
    """Print the titles of the first 10 hot
    posts listed in the subreddit
    """
    import requests

    headers = {"User-Agent": "Mozilla/5.0"}
    response = requests.get("https://www.reddit.com/r/{}/hot.json?limit=10".
                            format(subreddit),
                            headers=headers, allow_redirects=False)
    if response.status_code >= 300:
        print('None')
    else:
        [print(post.get("data").get("title"))
         for post in response.json().get("data").get("children")]
