#!/usr/bin/python3
"""Print the titles of the first 10 hot posts listed in the subreddit
"""


def top_ten(subreddit):
    """Print the titles of the first 10 hot
    posts listed in the subreddit
    """
    import requests

    if subreddit is None or not isinstance(subreddit, str):
        print("None")

    headers = {"User-Agent": "Mozilla/5.0"}
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        print('None')
    else:
        [print(post.get("data").get("title"))
         for post in response.json().get("data").get("children")]
