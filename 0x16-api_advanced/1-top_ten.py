#!/usr/bin/python3
"""Print the titles of the first 10 hot posts listed in the subreddit
"""
from requests import get


def top_ten(subreddit):
    """Print the titles of the first 10 hot
    posts listed in the subreddit
    """


    user_agent = {'User-agent': 'Mozilla/5.0'}
    params = {'limit': 10}
    url = 'https://www.reddit.com/r/{}/hot/.json'.format(subreddit)

    response = get(url, headers=user_agent, params=params)
    results = response.json()
    if response.status_code != 200:
        return None
    try:
        my_data = results.get('data').get('children')

        for i in my_data:
            print(i.get('data').get('title'))

    except Exception:
        print("None")
